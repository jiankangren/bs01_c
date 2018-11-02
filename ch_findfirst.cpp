
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>


int LFindFileList(const char* begin_dir)
{
	DIR*	pd	= NULL;			// directory stream object.
	dirent* dt = NULL;

	pd = opendir(begin_dir);
	if(NULL == pd)
	{
		printf( "opendir() failed: %s\n", begin_dir);
		return -1;
	}

	dt = readdir(pd);

	if(NULL == dt)
	{
		printf("readdir() failed: %s\n", begin_dir);
		return -1;
	}


	while(NULL != dt)
	{
		struct stat s;
		char   Name[260] = {0};		// Name

		lstat( dt->d_name, &s);
		sprintf(Name, "%s/%s", begin_dir, dt->d_name);

		// if it is a directory name then Search to sub-directory.
		if(DT_DIR == dt->d_type && '.' != dt->d_name[0])
		{
			printf("Drct: %s\n", Name);
			//FindFileList( drct ) ;
		}

		// printf file name
		else if(DT_REG == dt->d_type && '.' != dt->d_name[0])
		{
			printf("File: %s\n", Name);
		}


		dt = readdir(pd);
	}
typedef long long         L_PTR;

	if( -1 == closedir(pd))
	{
		printf( "closedir() failed: %s\n", begin_dir);
		return -1;
	}

	return 0;
}



typedef struct tagTDGE_FINDDATA
{
    unsigned int	attrib;
    long			time_create;    /* -1 for FAT file systems */
    long			time_access;    /* -1 for FAT file systems */
    long			time_write;
    unsigned long	size;
    char			name[260];
}TDGE_FINDDATA;



typedef long long L_PTR;


L_PTR DgeFile_FindFirst(TDGE_FINDDATA* fd, const char* begin_dir)
{
	DIR*	pd	= NULL;			// directory stream object.
	dirent* dt  = NULL;
	struct  stat st={0};

	L_PTR	handle = -1;

	pd = opendir(begin_dir);
	if(NULL == pd)
	{
		printf( "opendir() failed: %s\n", begin_dir);
		return handle;
	}

	dt = readdir(pd);

	if(NULL == dt)
	{
		printf("readdir() failed: %s\n", begin_dir);
		return handle;
	}

	lstat( dt->d_name, &st);


	// setting atribute for windows
	if(DT_DIR == dt->d_type)		fd->attrib = 0x10;
	else if(DT_REG == dt->d_type)	fd->attrib = 0x20;
	else							fd->attrib = 0x04;

	// setting time
	fd->time_create = st.st_mtime;
	fd->time_access = st.st_atime;
	fd->time_write  = st.st_ctime;

	// Settting size
	fd->size		= st.st_size;

	// copy name
	strcpy(fd->name, dt->d_name);

	// return pd
	handle = (L_PTR)pd;
	return handle;
}


int DgeFile_FindNext(L_PTR handle, TDGE_FINDDATA* fd)
{
	DIR*	pd	= (DIR*)handle;
	dirent* dt  = NULL;
	struct  stat st={0};

	dt = readdir(pd);
	if(NULL == dt)
		return -1;

	lstat( dt->d_name, &st);


	// setting atribute for windows
	if(DT_DIR == dt->d_type)		fd->attrib = 0x10;
	else if(DT_REG == dt->d_type)	fd->attrib = 0x20;
	else							fd->attrib = 0x04;

	// setting time
	fd->time_create = st.st_mtime;
	fd->time_access = st.st_atime;
	fd->time_write  = st.st_ctime;

	// Settting size
	fd->size		= st.st_size;

	// copy name
	strcpy(fd->name, dt->d_name);

	return 0;
}



int DgeFile_FindClose(long handle)
{
	DIR* pd	= (DIR*)handle;
	int hr = closedir(pd);

	if( -1 == hr)
		printf( "DgeFile_FindClose() failed.\n");


	return hr;
}





int DgeFindFileList(const char* begin_dir)
{
	TDGE_FINDDATA	fd={0};
	L_PTR			handle=0;
	int				hr=1;

	handle= DgeFile_FindFirst(&fd, begin_dir);

	if (handle == -1)
		return -1;

	while(-1 != hr)
	{
		// Folder
		if( (fd.attrib & 0x10) && '.' != fd.name[0])
			printf("Drct: %s/%s\n", begin_dir, fd.name);

		// File
		else if( (fd.attrib & 0x20) && '.' != fd.name[0])
			printf("File: %s/%s\n", begin_dir, fd.name);

		hr= DgeFile_FindNext(handle, &fd);
	}

	return DgeFile_FindClose(handle);
}





int main(int argc, char** argv)
{
	printf("GCC File and Directory Find----------------------------\n\n");
	LFindFileList("/Afew_work");

	printf("\n");

	printf("DgeFindFileList----------------------------\n\n");
	DgeFindFileList("/Afew_work");

    return 0;
}



