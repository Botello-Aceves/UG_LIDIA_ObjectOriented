@echo off
echo Compiling project with MinGW (C++)...

g++ -std=c++17 ^
    -Wall -Wextra ^
    main.cpp matrix.cpp ^
    -o matrix.exe

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo Build successful.
