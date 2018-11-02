
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* MyStrtok(char **pOut, char *strToken, const char *strDelimit)
{
	unsigned char* bgn = (unsigned char*)strToken;
	unsigned char* end = NULL;

	unsigned char* ctl = NULL;
	unsigned char* dst = NULL;
	unsigned char* str = NULL;

	int		iLen = 0;
	int		bFind= 0;

	*pOut = NULL;


	// Setup Begin
	bgn = (unsigned char*)strToken;

	if('\0'== *bgn)
		return NULL;

	for(; *bgn; ++bgn)
	{
		ctl = (unsigned char*)strDelimit;

		bFind = 0;

		for(; *ctl; ++ctl)
		{
			if(*bgn == *ctl)
			{
				bFind = 1;
				break;
			}
		}

		if(!bFind)
			break;
	}


	bFind = 0;


	// Setup End
	end = bgn+1;
	for(; *end; ++end)
	{
		ctl = (unsigned char*)strDelimit;

		for(; *ctl; ++ctl)
		{
			if(*end == *ctl)
			{
				bFind = 1;
				break;
			}
		}

		if(bFind)
			break;
	}


	iLen = int(end - bgn);
	dst = (unsigned char*)malloc( ( (iLen+7)/4 ) * 4 );

	*pOut = (char *)dst;

	ctl  = bgn;
	str  = dst;

	for( ;ctl != end; ++str, ++ctl)
		*str = *ctl;

	*str  = '\0';
	*pOut = (char *)dst;

	return (char*)end;
}


int main(int argc, char** argv)
{
	char Msg[] = "A string\tof ,,,,,,tokens\nand some  more tokens";
	char sep[] = " ,\t\n";

	char *s = NULL;
	char *stok = NULL;

	stok = MyStrtok(&s, Msg, sep);

	while(s)
	{
		printf("%s\n", s);
		free(s);

		stok = MyStrtok(&s, stok, sep);
	}
	
	return 0;
}