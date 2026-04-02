@echo off
REM Student Management System - Build and Run Script

echo ====================================
echo Student Management System Builder
echo ====================================
echo.

REM Check if build directory exists
if not exist "build" (
    echo Creating build directory...
    mkdir build
)

cd build

echo Generating build files with CMake...
cmake .. -G "Visual Studio 16 2019"

if errorlevel 1 (
    echo CMake generation failed. Trying MinGW...
    cmake .. -G "MinGW Makefiles"
)

echo.
echo Building the project...
cmake --build . --config Release

if errorlevel 1 (
    echo Build failed!
    cd ..
    pause
    exit /b 1
)

echo.
echo ====================================
echo Build Successful!
echo ====================================
echo.

cd ..

echo Running StudentManagement...
echo.

if exist "build\Release\StudentManagement.exe" (
    build\Release\StudentManagement.exe
) else if exist "build\StudentManagement.exe" (
    build\StudentManagement.exe
) else (
    echo Could not find executable!
    pause
)

pause
