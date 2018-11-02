
#include <stdio.h>
#include <windows.h>


union UFloat
{
	FLOAT	f;
	INT		n;

	struct
	{
		UINT	m:	23;	// mantissa
		UINT	e:	8;	// exponent
		UINT	b:	1;	// sign
	};

	struct
	{
		UINT f00: 1;	UINT f01: 1;	UINT f02: 1;	UINT f03: 1;
		UINT f04: 1;	UINT f05: 1;	UINT f06: 1;	UINT f07: 1;
		UINT f08: 1;	UINT f09: 1;	UINT f10: 1;	UINT f11: 1;
		UINT f12: 1;	UINT f13: 1;	UINT f14: 1;	UINT f15: 1;
		UINT f16: 1;	UINT f17: 1;	UINT f18: 1;	UINT f19: 1;
		UINT f20: 1;	UINT f21: 1;	UINT f22: 1;	UINT f23: 1;
		UINT f24: 1;	UINT f25: 1;	UINT f26: 1;	UINT f27: 1;
		UINT f28: 1;	UINT f29: 1;	UINT f30: 1;	UINT f31: 1;
	};


	UFloat(FLOAT _f) : f(_f){}
	UFloat(INT	 _n) : n(_n){}

};



void ConvertFloat(FLOAT f)
{
	UFloat	k =f;

	printf("%5.2f %12d %2d %3d %7d", k.f, k.n, k.b, k.e, k.m);

	printf(	"  %d"
			"  %d%d%d%d"
			"%d%d%d%d"
			"  %d%d%d"
			"%d%d%d%d"
			" %d%d%d%d"
			"%d%d%d%d"
			" %d%d%d%d"
			"%d%d%d%d\n"
			, k.f31, k.f30
			, k.f29, k.f28, k.f27, k.f26, k.f25, k.f24, k.f23, k.f22, k.f21, k.f20
			, k.f19, k.f18, k.f17, k.f16, k.f15, k.f14, k.f13, k.f12, k.f11, k.f10
			, k.f09, k.f08, k.f07, k.f06, k.f05, k.f04, k.f03, k.f02, k.f01, k.f00);
}



void main()
{
	FLOAT f=-123.456f;
	ConvertFloat(f);

	for(float a=-2.f; a<2.1f; a+=0.1f)
	{
		ConvertFloat(a);
	}
}
