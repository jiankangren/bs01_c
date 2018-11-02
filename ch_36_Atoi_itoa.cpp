

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>



int MyAsciiToInt(const char *Src)
{
	int	c;
	int	Tot;
	int	Sgn =0;
	
	while(isspace(*Src) )
		++Src;
	
	if ('-' == *Src)
	{
		++Src;
		Sgn = 1;
	}
	else if('+' == *Src)
		++Src;
	
	Tot = 0;
	
	while(0 != *Src)
	{
		c = *Src - '0';

		if(c<0 || c>10)
			break;

		Tot = 10 * Tot + c;
		++Src;
	}
	
	if (Sgn)
		return -Tot;

	return Tot;
}


void MyIntToAscii(int n, char* s, int L)
{
	char	s1[16]={0};

	int	Sgn=0;
	char *t1	= s1;
	char *t2	= s;

	
	if(n<0)
	{
		Sgn =1;
		n = ~n +1;
		*(t2++) ='-';
	}

	for( ;n !=0; ++t1)
	{
		*t1	= n%10 + '0';
		n	/= 10;
	}

	for( ;	t1 != s1;)
		*(t2++)	= *(--t1);


	*(t2) = 0;
}


void reverse(char* s1, const char* s2)
{
	char*	t = (char*)s2;
	while( *t )
		++t;

	while(t != s2)
		*(s1++) = *(--t);

	*s1 = 0;
}


#define MAX_VALUE	128

struct BigNumber
{
	char t[MAX_VALUE];

	BigNumber()
	{
		memset(t, 0, MAX_VALUE);
	}


	BigNumber(const BigNumber& r)
	{
		strcpy(t, r.t);
	}


	BigNumber(const char* r)
	{
		strcpy(t, r);
	}

	void add(const BigNumber& r)
	{
		char s1[MAX_VALUE]={0};
		char s2[MAX_VALUE]={0};

		reverse(s1, t);
		reverse(s2, r.t);


		int iL1 = strlen(s1);
		int iL2 = strlen(s2);

		int Max	= __max(iL1, iL2);
		int Min	= __min(iL1, iL2);

		int c =0;
		int	i =0;


//		for(i=0; i != iL1; ++i)
//			s1[i] -= '0';
//
//		for(i=0; i != iL2; ++i)
//			s2[i] -= '0';

		for(i=0; i != Min; ++i)
		{
			s1[i] += s2[i];
			s1[i] += c;

			s1[i] -= '0';
			s1[i] -= '0';

			c	= s1[i]/10;

			s1[i]	%=10;
			s1[i]	+='0';
		}


		for(; i != Max; ++i)
		{
			s1[i] += s2[i];
			s1[i] += c;

			s1[i] -= '0';

			c	= s1[i]/10;

			s1[i]	%=10;
			s1[i]	+='0';
		}

		if(c)
			s1[i]=c + '0';

		s1[++i] = 0;

		reverse(t, s1);
	}
};

void main()
{
//	char	s1[] = "  -9876543";
//	char	s2[32] ={0};
//	int		c=0;
//
//
//	c = MyAsciiToInt(s1);
//
//	printf("%d\n", c);
//
//
//	MyIntToAscii(c, s2, 32);
//
//	printf("%s\n", s2);
//
//
//	char	s3[] = "1234567890123455";
//	char	s4[64];
//
//	reverse(s4, s3);
//
//	printf("%s\n", s4);

	BigNumber s5("7534634679808907999");
	BigNumber s6("56452521452452456654242254");

	s5.add(s6);

	printf("%s\n", s5.t);
	
}

