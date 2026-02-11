@echo off
call ..\..\..\..\env_set.bat
cl /c *.c
link /DLL /OUT:..\nextToken.dll nextToken.obj /IMPLIB:..\nextToken.lib
echo Library Created!