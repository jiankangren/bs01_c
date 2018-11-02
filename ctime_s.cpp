

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>


#include <sys/stat.h>

int fexist(char *filename)
{
	int hr = 0;

#if defined(_MSC_VER)
	struct _stat st;
	hr = _stat(filename, &st);
#else
	stat st ;
	hr = stat( filename, &st);
#endif

	return hr? -1: 0;
}


int main(int argc, char** arv)
{
	int hr;
	char	timebuf[26];
	char*	filename = "tst.txt";
	errno_t err;

	// Get data associated with file 
	hr = fexist(filename);

	// Check if statistics are valid: 
	if(0 == hr)
	{
		// Output some of the statistics: 
		printf( "File size     : %ld\n", st.st_size );
		printf( "Drive         : %c:\n", st.st_dev + 'A' );
		err = ctime_s(timebuf, 26, &st.st_mtime);
		if (err)
		{
			printf("Invalid arguments to ctime_s.");
			return 0;
		}
		printf( "Time modified : %s", timebuf );
	}
	else
	{
		perror( "Problem getting information" );
		switch (errno)
		{
		case ENOENT:
			printf("File %s not found.\n", filename);
			break;
		case EINVAL:
			printf("Invalid parameter to _stat.\n");
			break;
		default:
			/* Should never be reached. */
			printf("Unexpected error in _stat.\n");
		}		
	}

	return 0;
}

