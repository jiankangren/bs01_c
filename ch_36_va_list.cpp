
#include <stdio.h>
#include <stdarg.h>

void MyPrintf(const char* format, ...)
{
	static char sOrg[8192];
	va_list val;
	
	va_start(val, format);
	vsprintf(sOrg, format, val);
	va_end(val);
	
	printf(sOrg);
}


void main()
{
	MyPrintf("MyPrintf: %s %d\n", "Hello world", 100);

}