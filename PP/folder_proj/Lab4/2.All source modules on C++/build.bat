@echo off
call clean.bat
cl /c /W3 *.c
link *.obj
*.exe