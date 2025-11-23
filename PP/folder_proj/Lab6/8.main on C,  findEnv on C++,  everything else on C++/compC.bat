@echo off
call clean.bat
cl /c /W3 /Fonul /Fa buildOutput.cpp
cl /c /W3 /Fonul /Fa findEnv.cpp
cl /c /W3 /Fonul /Fa nextToken.cpp
cl /c /W3 /Fonul /Fa main.c