
// Defined ShlObj.h
//	#define CSIDL_DESKTOP                   0x0000
//	#define CSIDL_INTERNET                  0x0001
//	#define CSIDL_PROGRAMS                  0x0002
//	#define CSIDL_CONTROLS                  0x0003
//	#define CSIDL_PRINTERS                  0x0004
//	#define CSIDL_PERSONAL                  0x0005
//	#define CSIDL_FAVORITES                 0x0006
//	#define CSIDL_STARTUP                   0x0007
//	#define CSIDL_RECENT                    0x0008
//	#define CSIDL_SENDTO                    0x0009
//	#define CSIDL_BITBUCKET                 0x000a
//	#define CSIDL_STARTMENU                 0x000b
//	#define CSIDL_DESKTOPDIRECTORY          0x0010
//	#define CSIDL_DRIVES                    0x0011
//	#define CSIDL_NETWORK                   0x0012
//	#define CSIDL_NETHOOD                   0x0013
//	#define CSIDL_FONTS                     0x0014
//	#define CSIDL_TEMPLATES                 0x0015
//	#define CSIDL_COMMON_STARTMENU          0x0016
//	#define CSIDL_COMMON_PROGRAMS           0X0017
//	#define CSIDL_COMMON_STARTUP            0x0018
//	#define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019
//	#define CSIDL_APPDATA                   0x001a
//	#define CSIDL_PRINTHOOD                 0x001b
//	#define CSIDL_ALTSTARTUP                0x001d
//	#define CSIDL_COMMON_ALTSTARTUP         0x001e
//	#define CSIDL_COMMON_FAVORITES          0x001f
//	#define CSIDL_INTERNET_CACHE            0x0020
//	#define CSIDL_COOKIES                   0x0021
//	#define CSIDL_HISTORY                   0x0022

// Not defined. So U'll make it.
#define CSIDL_COMMON_DESKTOPDIRECTORY	0x0019
#define CSIDL_LOCAL_APPDATA				0x001C

#define CSIDL_INTERNET_CACHE			0x0020
#define CSIDL_COOKIES					0x0021
#define CSIDL_HISTORY					0x0022
#define CSIDL_COMMON_APPDATA			0x0023
#define CSIDL_WINDOWS					0x0024
#define CSIDL_SYSTEM					0x0025
#define CSIDL_PROGRAM_FILES				0x0026
#define CSIDL_MYPICTURES				0x0027
#define CSIDL_PROFILE					0x0028
#define CSIDL_SYSTEMX86					0x0029
#define CSIDL_PROGRAM_FILESX86			0x002A
#define CSIDL_PROGRAM_FILES_COMMON		0x002B
#define CSIDL_PROGRAM_FILES_COMMONX86	0x002C
#define CSIDL_COMMON_TEMPLATES			0x002D
#define CSIDL_COMMON_DOCUMENTS			0x002E
#define CSIDL_COMMON_ADMINTOOLS			0x002F

#include <windows.h>
#include <Shlobj.h>
#include <stdio.h>


void main()
{
	char pBuffer[MAX_PATH];
	char buf[1024];
	LPITEMIDLIST pidl;

	printf("Using GetSystemDirectory Function.\n"); 
	GetSystemDirectory(pBuffer, sizeof pBuffer);
	printf("%s\n\n", pBuffer);

	printf("Using GetWindowsDirectory Function.\n"); 
	GetWindowsDirectory(pBuffer, sizeof pBuffer);
	printf("%s\n\n", pBuffer);


	printf("Using SHGetSpecialFolderLocation Function.\n"); 
	SHGetSpecialFolderLocation(NULL, CSIDL_PROGRAMS, &pidl);
	SHGetPathFromIDList(pidl, buf);
	printf("%s\n\n", buf);


	printf("Using SHGetSpecialFolderPath Function.\n"); 
	
	for(int i=CSIDL_DESKTOP; i<=CSIDL_COMMON_ADMINTOOLS; ++i)
	{
		printf("index:0x00%2x	", i); 
		SHGetSpecialFolderPath( NULL, pBuffer, i, 0); 
		printf("%s\n", pBuffer); 
	}
}
