@echo off
ml /c /W3 buildOutput.asm
ml /c /W3 findEnv.asm
ml /c /W3 nextToken.asm
ml /c /W3 main.asm

link *.obj /OUT:main.exe