
#include <stdio.h>

//	File Open Attribute
//		속성	파일 유				파일 무
//	r			r					NULL
//	r+	rwa							NULL
//	w	 wa		이전파일 덮어씀		새파일 생성
//	w+	rwa		이전파일 삭제		새파일 생성
//	a	  a		이전파일 위에 추가	새파일 생성
//	a+	r a		이전파일 위에 추가	새파일 생성
//
//	getc/putc, fgets/fputs, fread/fwrite, fgetc/fputc

void main()
{
	printf("File Read/Write ...\n");
}

