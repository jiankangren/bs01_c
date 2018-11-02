////////////////////////////////////////////////////////////////////////////////
//
// Explain: Pointer Test
// 포인터는 메모리 주소를 저장하기 위한 변수이다.
// 참조 연산자 '&'와 혼용해서 사용하는 법을 잘 살 펴보자.


#include <stdio.h>


int main()
{
	printf("----------포인터 연습-------\n\n");

	int	a;
	a=10;

	int	(*pi);
	pi = &a;

	printf(" 	a:  %d	&a: %d\n", a, &a);

	printf(	" *pi: %d"
			" pi: %d"
			" &pi:%d"
			" *&pi:%d"
			" **&pi:%d\n"
			, *pi
			, pi
			, &pi
			, *&pi
			, **&pi);


	int	(**ppi);
	ppi = &pi;

	// 다음에 출력이 어떻게 되는지 주의 깊게 보자.
	printf("	**ppi: %d  *ppi: %d	ppi:%d  &ppi:%d\n", **ppi, *ppi, ppi, &ppi);

}


// 이중 포인터는 포인터의 포인터라 부르며 이것은 변수인 포인터 자체에 대한 주소를
// 의미한다.
