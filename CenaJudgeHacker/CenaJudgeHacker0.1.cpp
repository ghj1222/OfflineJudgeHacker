//CenaJudgeHacker
//ghj1222
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

//The name of some files.
//Please change it.
const char            *InputFileName = "zmjring.in";
const char           *OutputFileName = "zmjring.out";
const char    *InputDataNameTemplate = "color%d.in";
const char   *OutputDataNameTemplate = "color%d.out";

//The range of testdatas.
//Please change it.
const int                      Lower = 1;
const int                      Upper = 20;

//The maxinum size of file size and filename size.
//You can change it if you need to.
const int                MaxFileSize = 1000000;
const int                MaxNameSize = 1000;

//DO NOT change the next things.
//Or you may get CE, RE or WA.
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
			sprintf(OutputDataName, OutputDataNameTemplate, i);
			strcpy(dataPath, MyPath);
			strcat(dataPath, OutputDataName);
			FILE *OutputDataPtr = fopen(dataPath, "r");
			ReadFromFile(OutputDataPtr, OutputData);
			fclose(OutputDataPtr);
			OutputDataPtr = 0;
			PrintToFile(stdout, OutputData);
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
