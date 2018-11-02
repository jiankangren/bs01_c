#include <stdio.h>
#include <string.h>


int CheckSSL(char* sStr)
{
	int pSSL[13]={0};
	
	int iSum=0;
	
	if(strlen(sStr) !=13)
		return 0;
	

	for(int i=0; i<13; ++i)
	{
		pSSL[i] = sStr[i] + 1 - '1';
		iSum += pSSL[i] * (2+ i%8);
	}
	
	iSum =iSum % 11;
	iSum =11 - iSum;
	
	iSum %=10;
	
	if(pSSL[12] ==iSum)
		return 1;
	
	return 0;
}


int CheckSSL(int* pSSL)
{
	int iSum=0;

	for(int i=0; i<13; ++i)
		iSum += pSSL[i] * (2+ i%8);
	
	iSum =iSum % 11;
	iSum =11 - iSum;
	
	iSum %=10;
	
	if(pSSL[12] ==iSum)
		return 1;
	
	return 0;
}



void main()
{
	int hr = CheckSSL("1234567890123");
	
	if(hr)
	{
		printf(" True\n");
	}
	else
	{
		printf(" False\n");
	}
}
