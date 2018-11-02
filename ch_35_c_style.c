/* C-Style형식의 함수 사용.
 *
 */


#include <stdio.h>


#define CASE	1

#if CASE

/* case 1: 함수 사용
 함수를 뒤에 정의 한다.
 이런 방법은 워닝을 부른다.

 워닝을 없애려면 미리 함수를 정의하거나 선언을 해주어야 한다.
 리턴 타입을 적지 않으면 int형 된다.
 다음주석을 지워서 컴파일 해보세요.
*/

/*
Func1();
int Func2();
int Func3();
*/


main()
{
	int a=10;
	float c=0;

	Func1();
	
	/* 위에서 함수의 선언이 int로 되어 있어서 아래의 함수의 정의에서	*/
	/* float으로 되어 있어도											*/
	/* int로 반환이 된다.												*/
	c=Func2(a);
	printf("%f\n", c);


	Func3(&a);
}


Func1()
{
	printf("Func1 Call\n");
}


float Func2(k, l)
int k;
int l;
{
	printf("Func2 Call: arg1:%d arg2:%x\n", k, l);

	return 2.5f;
}


int Func3(k, l)
/* Call by Reference에서*/
/* int& k;				*/	/* 이것은 안된다.		*/
int* k;						/* 오직 이 방식만 된다.	*/
int* l;
{
	printf("Func3 Call: arg1:%d\n", *k);
}



#else


/* case 2: 구조체														*/
/* 구조체를 사용하기 위해서 반드시 앞에 struct 키워드를 붙여야 한다.	*/
Func4();

struct MyStruct
{
	int a;
};



main()
{
	struct MyStruct st;
	st.a = 10;
	/* 위에서 함수의 선언이 int로 되어 있어서 아래의 함수의 정의에서	*/
	/* float으로 되어 있어도											*/
	/* int로 반환이 된다.												*/
	Func4(&st);
}


Func4(pSt)
struct MyStruct	*pSt;
{
	printf("Func4 Call: MyStruct:%x, value: %d\n", pSt, pSt->a);
}

#endif
