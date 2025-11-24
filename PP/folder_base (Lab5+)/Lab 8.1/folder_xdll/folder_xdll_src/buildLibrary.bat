@echo off
call ..\..\..\..\env_set.bat
cl /c /W3 /I.\ *.c
lib /OUT:..\library_xdll.lib *.obj
echo Library Created!