@echo off
call clean.bat
cl /c /W3 /Fonul /Fa buildOutput.c
cl /c /W3 /Fonul /Fa findEnv.cpp
cl /c /W3 /Fonul /Fa nextToken.c
cl /c /W3 /Fonul /Fa main.c