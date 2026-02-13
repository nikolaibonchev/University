// Win32Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

FILE* stream;

int _tmain(int argc, _TCHAR* argv[])
{
	long l;
	float fp;
	char s[81];
	char c;

	for (int i = 0; i < argc; i++) {
		errno_t err = fopen_s(&stream, argv[i], "w+");

        if (err)
            printf_s("The file %s was not opened\n", argv[i]);
        else
        {
            fprintf_s(stream, "%s %ld %f%c", "a-string",
                65000, 3.14159, 'x');
            // Set pointer to beginning of file:
            fseek(stream, 0L, SEEK_SET);

            // Read data back from file:
            fscanf_s(stream, "%s", s, _countof(s));
            fscanf_s(stream, "%ld", &l);

            fscanf_s(stream, "%f", &fp);
            fscanf_s(stream, "%c", &c, 1);

            // Output data read:
            printf("%s\n", s);
            printf("%ld\n", l);
            printf("%f\n", fp);
            printf("%c\n", c);

            fclose(stream);
        }
	}

	return 0;
}

