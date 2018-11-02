#include <string.h>
#include <stdio.h>

// Is it true that 'pbrk' means pointer break?
//
void main()
{
	char str[] = "The 3 men and 2 boys ate 5 pigs\n";
	char *r;

	printf( "1: %s\n", str );

	r = strpbrk( str, " 0123456789" );
	printf( "2: %s\n", r++ );
	
	r = strpbrk( r, " 0123456789" );
	printf( "3: %s\n", r++ );
	
	r = strpbrk( r, " 0123456789" );
	printf( "4: %s\n", r );
	
}
