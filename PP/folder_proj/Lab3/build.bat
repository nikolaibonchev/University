@echo off
call ..\..\env_set.bat
call clean.bat
cl /c /W3 *.c
link *.obj /OUT:lab3.exe