// Win32Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define MAX_CHARNAME 11
#define MAX_CHARGROUP 4
FILE* stream;

struct Student {
	_TCHAR Name[MAX_CHARNAME];
	_TCHAR Surname[MAX_CHARNAME];
	_TCHAR Famname[MAX_CHARNAME];
	_TCHAR Group[MAX_CHARGROUP];
	int FacNum;
};

int compare(const void* x_void, const void* y_void) {
	struct Student *p1 = (struct Student*)x_void;
	struct Student *p2 = (struct Student*)y_void;

	return (p1->FacNum - p2->FacNum);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;

	if ((stream = fopen(argv[1], "r")) == NULL) {
		_tprintf("The file %s was not opened\n", argv[1]);
	}
	else {
		_tprintf("The file %s was opened\n", argv[1]);

		struct Student temp;

		while (!feof(stream)) {
			_ftscanf(stream, _T("%s %s %s %s %d"), temp.Name, temp.Surname, temp.Famname, temp.Group, &temp.FacNum);
			count++;
		};

		fseek(stream, 0, SEEK_SET);
		printf("lines count is %d\n", count);

		struct Student* array = (struct Student*)malloc(count * sizeof(struct Student));

		while (!feof(stream)) {
			static int i = 0;
			_ftscanf(stream, _T("%s %s %s %s %d"), array[i].Name, array[i].Surname, array[i].Famname, array[i].Group, &array[i].FacNum);
			i++;
		};

		qsort(array, count, sizeof(struct Student), compare);

		for (int k = 0; k < count; k++) {
			_tprintf("%s, %s, %s, %s, %d \n", array[k].Name, array[k].Surname, array[k].Famname, array[k].Group, array[k].FacNum);
		};

		free(array);
	};
	
	return 0;
};