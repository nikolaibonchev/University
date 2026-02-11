@echo off
cl /c /W3 *.c
cl /c /W3 *.cpp
link *.obj /OUT:main.exe