#include <stdio.h>
#include <windows.h>

int main()
{
	FILE* fp1;
	FILE* fp2;
	char sFileName[] ="Test.txt";
	fp1 = fopen(sFileName, "rt");

	if(NULL == fp1)
	{
		char sErr[512];
		sprintf(sErr, "%s file is not found!!!", sFileName);
		MessageBox(0, sErr, "Err", 0);
		return -1;
	}

	fp2 = fopen("Write.txt", "wt");

//	char sString[512];
//	fscanf(fp,"%s",sString);
//	printf("%s\n", sString);
//	fscanf(fp,"%s",sString);
//	printf("%s\n", sString);

	char sString[512];

	while( !feof(fp1))
	{
		fgets(sString, sizeof(sString), fp1);
		
		int iLen = strlen(sString);

		for(int i=0; i<iLen; ++i)
		{
			if(sString[i] == '\n')
			{
				sString[i] = '\0';
				break;
			}
		}

		fprintf(fp2, "%s\n", sString);
	}

	fclose(fp1);
	fclose(fp2);

	return 1;
}
