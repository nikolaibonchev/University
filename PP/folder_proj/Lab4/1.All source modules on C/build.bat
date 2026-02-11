@echo off
call clean.bat
cl /c /W3 *.c
link *.obj /OUT:main.exe

