////////////////////////////////////////////////////////////////////////////////
//
// Explain: Pointer와 동적 할당
// Alias '&'와 혼용해서 사용하는 법을 잘 보자.


#include <stdio.h>
#include <memory.h>

int main()
{
	printf("new를 이용한 동적할당\n\n");

	int array1[100];

	for(int i=0; i<100; ++i)
	{
		array1[i] = i;
	}

	int	*p = NULL;							// 포인터의 경우 항상 널 포인터로 초기화 하는 습관을 들이자
	int iSize=100;
	(int*)p = (int*) new int[iSize];		// 캐스팅이 필요할 때도 있다.


	memcpy(p, array1, sizeof(int) * iSize);


	for(i=0; i<100; ++i)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}


	if(p)
	{
		delete [] p;
		p = NULL;
	}


	int iWidth  = 100;
	int iHeight = 50;

	int **pp = NULL;


	pp = new int*[100];						//pp = (int**)new int[100]; 둘다 같다.

	for(i=0; i<100; ++i)
		pp[i] = new int[50];


	if(pp)
	{
		for(int i=0; i<100; ++i)
			delete [] pp[i];

		delete [] pp;
		pp = NULL;
	}



	int array3[10][5][2];


	for(i=0; i<10; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			for(int k=0; k<2; ++k)
				array3[i][j][k] = k + j*2 + i*5*2;
		}
	}


//	for(i=0; i<10; ++i)
//	{
//		for(int j=0; j<5; ++j)
//		{
//			for(int k=0; k<2; ++k)
//				printf("array3[%d][%d][%d] = %d\n", i, j, k, array3[i][j][k]);
//		}
//	}


	printf("\n------------------------------------------------------------\n\n");

	iWidth  = 10;
	iHeight = 5;
	int iDepth	= 2;

	int ***ppp = NULL;

	ppp = (int***)new int[iWidth];

	for(i=0; i<iWidth; ++i)
	{
		ppp[i] = (int**)new int[iHeight];

		for(int j=0; j<iHeight; ++j)
		{
			ppp[i][j] = (int*)new int[iDepth];

			for(int k=0; k<iDepth; ++k)
				ppp[i][j][k] = k + j*2 + i*5*2;
		}
	}


// memcpy은 연속적으로 메모리가 할당된 곳에서만 가능하다. 그런데 위에서는
// 배열의 행, 열, 깊이 마다 메모리를 동적으로 할당했지만 이들의 주소가
// 모든 메모리가 연속으로 할당되지는 않다.
// 따라서 다음의 주석은 문제를 반드시 일으킨다.

//	memcpy(ppp, array3, sizeof(int) * iWidth * iHeight * iDepth);

	for(i=0; i<iWidth; ++i)
	{
		for(int j=0; j<iHeight; ++j)
		{
			for(int k=0; k<iDepth; ++k)
				printf("array3[%d][%d][%d] = %d\n", i, j, k, ppp[i][j][k]);
		}
	}


	if(ppp)
	{
		for(int i=0; i<10; ++i)
		{
			for(int j=0; j<5; ++j)
			{
				delete [] ppp[i][j];
			}


			delete [] ppp[i];
		}

		delete [] ppp;
		ppp = NULL;
	}



	// 과제 int x = 20 int y = 10 int z= 5 int w= 2으로 주어질 때
	// int array4[20][10][5][2]와 동일한 4중 포인터 ****pppp의 메모리를 할당하고 해제하라.

	return 1;
}