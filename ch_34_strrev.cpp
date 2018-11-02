

#include <stdio.h>


int StrLen(const char* str)
{
	char*	s = (char*)str;

	for( ; *s; ++s);

	return int(s - str);
}

void StrRev(const char* str)
{
	char* bgn = (char*)str;
	char* end = (char*)str;

	// find end
	for(; *end; ++end);

	// decrease end
	--end;

	// one or zero character
	if(end<=bgn)
		return;

	// swap
	for(; bgn < end; ++bgn, --end)
	{
		*bgn ^= *end;
		*end ^= *bgn;
		*bgn ^= *end;
	}
}



void main()
{
	char p[] = "Hello world Welcome!!!";

	int iLen = StrLen(p);

	printf("String Length: %d\n", iLen);

	StrRev(p);

	printf("%s\n", p);

}
