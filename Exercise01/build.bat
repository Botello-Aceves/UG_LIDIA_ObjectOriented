@echo off
echo Compiling project with MinGW...

gcc -Wall -Wextra -std=c11 main.c -o exec.exe

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo Build successful. Executable: exec.exe
