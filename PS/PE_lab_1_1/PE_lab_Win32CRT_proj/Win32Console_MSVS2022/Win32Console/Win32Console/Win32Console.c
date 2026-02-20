// Win32Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define MAX_CHARNAME 16
#define MAX_CHARGROUP 3
FILE* stream;

struct Student {
	_TCHAR Name[MAX_CHARNAME];
	_TCHAR Surname[MAX_CHARNAME];
	_TCHAR Famname[MAX_CHARNAME];
	_TCHAR Group[MAX_CHARGROUP];
	int FacNum;
};

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR name[MAX_CHARNAME];

	if ((stream = fopen(argv[1], "r")) == NULL) { // C4996
		// Note: fopen is deprecated; consider using fopen_s instead
		_tprintf("The file %s was not opened\n", argv[1]);
	}
	else {
		_tprintf("The file %s was opened\n", argv[1]);
		fseek(stream, 0L, SEEK_SET);
		_ftscanf(stream, "%s", name);
		printf("%s", name);
	};
	return 0;
}