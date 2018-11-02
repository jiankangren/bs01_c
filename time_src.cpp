#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

int main(int argc, char** argv)
{

	char dgelog[260]={0};

	char CC[64]={0};
	char YY[16]={0};
	char MM[16]={0};
	char DD[16]={0};
	char TT[32]={0};

	char hh[4]={0};
	char mm[4]={0};
	char ss[4]={0};

	time_t	ltime;

	time( &ltime );

	strcpy(CC, ctime( (const time_t *)&ltime ) );
	sscanf(CC, "%*s %*s %*s %s", TT);

	strncpy(hh, TT, 2);
	strncpy(mm, TT+3, 2);
	strncpy(ss, TT+6, 2);

	strftime(CC, sizeof(CC), "%Y %m %d", gmtime((const time_t *)&ltime) );
	sscanf(CC, "%s %s %s", YY, MM, DD);

	sprintf(dgelog, "dgelog%s%s_%s%s%s.txt", MM, DD, hh, mm, ss);


	return 0;

}

