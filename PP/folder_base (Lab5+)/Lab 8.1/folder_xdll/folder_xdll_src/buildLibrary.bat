@echo off
call ..\..\..\..\env_set.bat
cl /c *.c
link /DLL /OUT:..\library_xdll.dll nextToken.obj /IMPLIB:..\library_xdll.lib
echo Library Created!