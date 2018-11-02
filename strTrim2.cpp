
#include <stdio.h>

void LcStr_TrimLeft(char* sBuf, const char *sTrm)
{
	char*	D= (char*)sBuf;
	char*	L= (char*)sBuf;
	char*	T= NULL;

	while( *L )
	{
		T= (char*)sTrm;
		for(; *T && *T != *L; ++T);

		if(!*T)
			break;

		++L;
	}

	while( *L )
		*(D++) = *(L++);

	*D = '\0';
}


void LcStr_TrimRight(char* sBuf, const char *sTrm)
{
	char*	D= (char*)sBuf;
	char*	R= (char*)sBuf;
	char*	L= (char*)sBuf;
	char*	T= NULL;

	if('\0' == *R)
	{
		*D = '\0';
		return;
	}

	while( *R )
		++R;

	--R;

	while(*R)
	{
		T= (char*)sTrm;
		for(; *T && *T != *R; ++T);

		if(!*T)
			break;

		--R;
	}

	while( L <= R)
		*(D++) = *(L++);

	*D = '\0';
}



void LcStr_Trim(char* sBuf, const char *sTrm)
{
	char*	D= (char*)sBuf;
	char*	R= (char*)sBuf;
	char*	L= (char*)sBuf;
	char*	T= NULL;

	// find L
	while( *L )
	{
		T= (char*)sTrm;
		for(; *T && *T != *L; ++T);

		if(!*T)
			break;

		++L;
	}


	// Find R
	R = L;

	while( *R )
		++R;


	// NULL string
	if(L >= R)
	{
		*D = '\0';
		return;
	}

	--R;

	while(*R)
	{
		T= (char*)sTrm;
		for(; *T && *T != *R; ++T);

		if(!*T)
			break;

		--R;
	}

	while( L <= R)
		*(D++) = *(L++);

	*D = '\0';
}


void main()
{
	char str[] = "		,,   	1,	, 2 world 	,  , 		";

//	LcStr_TrimLeft(str, "\t ,");
//	LcStr_TrimRight(str, "\t ,");

	LcStr_Trim(str, "\t ,1world");

	printf("%s\n", str);
}