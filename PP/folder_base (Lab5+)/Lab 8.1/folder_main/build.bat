@echo off
call ..\..\..\env_set.bat

cl /c /W3 /I.\ *.c

link *obj ..\folder_xlib\library_xlib.lib ..\folder_xdll\nextToken.lib /OUT:program.exe

echo Build Ended!