
#include <Windows.h>
#include <stdio.h>


void DgeStr_Trim(char* sBuf, const char *sTrm)
{
	char*	End=0;
	char*	Dst=0;

	char	*L=0, *R=0;		// iterator
	INT		bTogle = 0;

	INT		n;
	INT		nBuf = strlen(sBuf);
	INT		nTrm = strlen(sTrm);


	if(nBuf <1 || nTrm<1)
		return;


	Dst = sBuf;
	End = sBuf + nBuf;

	// iterator
	L=Dst, R=End;

	// find Left
	while(L<=R)
	{
		bTogle =0;
		for(n=0; n<nTrm; ++n)
		{
			if( *(sTrm+n) == *L)
			{
				bTogle =1;
				break;
			}
		}

		if(bTogle)
		{
			++L;
			continue;
		}

		break;
	}


	// all match...
	if(L>=End)
	{
		*Dst = '\0';
		return;
	}



	// find Right
	while(L<R)
	{
		--R;

		bTogle =0;
		for(n=0; n<nTrm; ++n)
		{
			if( *(sTrm+n) == *R)
			{
				bTogle =1;
				break;
			}
		}

		if(bTogle)
			continue;

		break;
	}



	for(; L<=R; ++L, ++Dst)
		*Dst = *L;

	*Dst = '\0';
}


void DgeStr_TrimLeft(char* sBuf, const char *sTrm)
{
	char*	End=0;
	char*	Dst=0;

	char	*L=0;		// iterator
	INT		bTogle = 0;

	INT		n;
	INT		nBuf = strlen(sBuf);
	INT		nTrm = strlen(sTrm);


	if(nBuf <1 || nTrm<1)
		return;


	Dst = sBuf;
	End = sBuf + nBuf;

	// iterator
	L=Dst;

	// find Left
	while(L<End)
	{
		bTogle =0;
		for(n=0; n<nTrm; ++n)
		{
			if( *(sTrm+n) == *L)
			{
				bTogle =1;
				break;
			}
		}

		if(bTogle)
		{
			++L;
			continue;
		}

		break;
	}


	// setup string
	if(L>=End)
	{
		*Dst = '\0';
		return;
	}

	for(; L<=End; ++L, ++Dst)
		*Dst = *L;
}


void DgeStr_TrimRight(char* sBuf, const char *sTrm)
{
	char*	Bgn=0;

	char	*R=0;		// iterator
	INT		bTogle = 0;

	INT		n;
	INT		nBuf = strlen(sBuf);
	INT		nTrm = strlen(sTrm);


	if(nBuf <1 || nTrm<1)
		return;


	Bgn = sBuf;
	R   = sBuf + nBuf;	// End


	// find Right
	while(Bgn<=R)
	{
		--R;

		bTogle =0;
		for(n=0; n<nTrm; ++n)
		{
			if( *(sTrm+n) == *R)
			{
				bTogle =1;
				break;
			}
		}

		if(bTogle)
			continue;

		break;
	}


	// all match...
	if(Bgn>R)
	{
		*Bgn = '\0';
		return;
	}


	*(R+1) = '\0';
}





int DgeStr_Quot(char* Dst, const char* Src)
{
	INT	nCnt  =0;
	INT bTogle=0;

	INT	iLen = strlen(Src);

	char* p = (char*)Src;

	while( *p && p <= Src+iLen)
	{
		if( '\"' == *p)
		{
			bTogle ^= 1;

			if(!bTogle)
			{
				++nCnt;
				*(Dst++) = '\0';
			}
			else
			{
				++p;
				continue;
			}
		}


		if(bTogle)
			*(Dst++) = *p;

		++p;
	}

	return nCnt;
}





int main(int argc, char** argv)
{
	char	sBuf1[] ="llddddllasasdfasdfsld";

	DgeStr_TrimRight(sBuf1, "ldabf");

	printf("TrimRight: \"%s\"\n", sBuf1);

	printf("--------------------------------------\n\n");


	char	sBuf2[] =" \"abc\"  def   \"ghi \"   \"j kl \" pqr \"dfasdfasd";

	char	sDst[64];
	int		nCnt=0;

	char*	str = sDst;

	nCnt = DgeStr_Quot(sDst, sBuf2);

	for(int i=0; i<nCnt; ++i)
	{
		printf("\"%s\"\n", str);
		str = str + strlen(str) + 1;
	}

	return 0;
}