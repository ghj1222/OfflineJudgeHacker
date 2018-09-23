//CenaJudgeHacker
//ghj1222
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

//The name of some files.
//Please change it.
const char            *InputFileName = "probname.in";
const char           *OutputFileName = "probname.out";
const char    *InputDataNameTemplate = "probname%d.in";
const char   *OutputDataNameTemplate = "probname%d.out";

//The range of testdatas.
//Please change it.
const int                      Lower = 1;
const int                      Upper = 20;

//The maxinum size of file size and filename size.
//You can change it if you need to.
const int                MaxFileSize = 1000000;
const int                MaxNameSize = 1000;

//You Can Decide whice point get what result.
enum statement{AC, WA, TLE, MLE, RE_stack, RE_div0, RE_memory};

const int result[] = {0, AC, AC, AC, WA, WA, WA, TLE, TLE, TLE, MLE, MLE, MLE, RE_stack, RE_stack, RE_stack, RE_div0, RE_div0, RE_div0, RE_memory, RE_memory};

//Enjoy!
char InputFile[MaxFileSize];
char InputData[MaxFileSize];
char OutputData[MaxFileSize];
char InputDataName[MaxNameSize];
char OutputDataName[MaxNameSize];
char MySize[MaxNameSize];
char MyPath[MaxNameSize];
char dataPath[MaxNameSize];
int MyPathLen;

void ReadFromFile(FILE *fp, char *str)
{
	int p = 0;
	while ((str[p] = fgetc(fp)) != EOF)
		p++;
	str[p] = 0;
}

void PrintToFile(FILE *fp, char *str)
{
	int p = 0;
	while (str[p] != EOF && str[p] != 0)
	{
		fputc(str[p], fp);
		p++;
	}
}

void GetMLE()
{
	for (int i = 1; i <= 10000; i++)
	{
		int *a = new int[10000000];
		a[1234567] = 1;
	}
}

void GetRE()
{
	int a[2000];
	a[123] = 1;
	a[234] = a[123];//Avoid -Wall warning
	GetRE();
}

int main()
{
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	
	GetModuleFileName(NULL, MyPath, MaxNameSize);
	MyPathLen = strlen(MyPath);
	for (; MyPathLen >= 0; MyPathLen--)
	{
		if (MyPath[MyPathLen + 1] == 't' && MyPath[MyPathLen + 2] == 'm' && MyPath[MyPathLen + 3] == 'p')
		{
			MyPath[MyPathLen + 1] = 'd';
			MyPath[MyPathLen + 2] = 'a';
			MyPath[MyPathLen + 3] = 't';
			MyPath[MyPathLen + 4] = 'a';
			MyPath[MyPathLen + 5] = '\\';
			MyPath[MyPathLen + 6] = 0;
			MyPathLen += 6;
			break;
		}
	}
	
	ReadFromFile(stdin, InputFile);
	for (int i = Lower; i <= Upper; i++)
	{
		sprintf(InputDataName, InputDataNameTemplate, i);
		strcpy(dataPath, MyPath);
		strcat(dataPath, InputDataName);
		FILE *InputDataPtr = fopen(dataPath, "r");
		ReadFromFile(InputDataPtr, InputData);
		fclose(InputDataPtr);
		InputDataPtr = 0;
		if (strcmp(InputFile, InputData) == 0)
		{
			if (result[i] == AC || result[i] == WA)
			{
				sprintf(OutputDataName, OutputDataNameTemplate, i);
				strcpy(dataPath, MyPath);
				strcat(dataPath, OutputDataName);
				FILE *OutputDataPtr = fopen(dataPath, "r");
				ReadFromFile(OutputDataPtr, OutputData);
				fclose(OutputDataPtr);
				OutputDataPtr = 0;
				PrintToFile(stdout, OutputData);
			}
			if (result[i] == WA)//Output more things to get WA
			{
				PrintToFile(stdout, OutputData);
			}
			if (result[i] == TLE)
			{
				while (1);
			}
			if (result[i] == MLE)
			{
				GetMLE();
			}
			if (result[i] == RE_stack)
			{
				GetRE();
			}
			if (result[i] == RE_div0)
			{
				int x = 0;//Avoid -Wall warning
				int fuckyou = 5 / x;
				x = fuckyou;
			}
			if (result[i] == RE_memory)
			{
				int a[5];
				a[1] = 1;
				a[2] = a[1];//Avoid -Wall warning
				a[40000] = 4;
			}
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fprintf(stdout, "fuck!\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
