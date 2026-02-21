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
	int FacNum[5];
};

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR name[MAX_CHARNAME];
	_TCHAR surname[MAX_CHARNAME];
	_TCHAR famname[MAX_CHARNAME];
	_TCHAR group[MAX_CHARGROUP];
	_TINT fac[5];

	int count = 0;

	if ((stream = fopen(argv[1], "r")) == NULL) {
		_tprintf("The file %s was not opened\n", argv[1]);
	}
	else {
		_tprintf("The file %s was opened\n", argv[1]);

		while (!feof(stream)) {
			_ftscanf(stream, "%s", name);
			_ftscanf(stream, "%s", surname);
			_ftscanf(stream, "%s", famname);
			_ftscanf(stream, "%s", group);
			_ftscanf(stream, "%d", &fac[5]);
			count++;
		};

		fseek(stream, 0, SEEK_SET);
		printf("lines count is %d\n", count);
		struct Student* array = (struct Student*)malloc(count * sizeof(struct Student));

		while (!feof(stream)) {
			static int i = 0;
			_ftscanf(stream, "%s", name);
			array[i].Name[MAX_CHARNAME] = name;

			_ftscanf(stream, "%s", surname);
			array[i].Surname[MAX_CHARNAME] = surname;

			_ftscanf(stream, "%s", famname);
			array[i].Famname[MAX_CHARNAME] = famname;

			_ftscanf(stream, "%s", group);
			array[i].Group[MAX_CHARGROUP] = group;

			_ftscanf(stream, "%d", &fac[5]);
			array[i].FacNum[5] = fac[5];

			_tprintf("%d \n", array[i].FacNum[5]);
			i++;
		}
		printf("-------");
		for (int j = 0; j < count; j++) {
			_tprintf("%d \n", array[j].FacNum[5]);
		}
	};
	
		return 0;
};