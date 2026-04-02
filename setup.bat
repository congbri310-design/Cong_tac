@echo off
REM Automated Setup Script for Student Management System
REM This script checks and installs required dependencies

echo.
echo ========================================
echo   Student Management System - Setup
echo ========================================
echo.

REM Check for CMake
echo Checking for CMake...
cmake --version >nul 2>&1
if errorlevel 1 (
    echo [✗] CMake not found
    set CMAKE_MISSING=1
) else (
    echo [✓] CMake is installed
    cmake --version
)

echo.

REM Check for MSVC Compiler
echo Checking for MSVC Compiler...
cl.exe >nul 2>&1
if errorlevel 1 (
    echo [✗] MSVC Compiler not found
    set COMPILER_MISSING=1
) else (
    echo [✓] MSVC Compiler is installed
)

REM Check for GCC Compiler (MinGW)
echo Checking for GCC Compiler (MinGW)...
g++ --version >nul 2>&1
if errorlevel 1 (
    if "%COMPILER_MISSING%"=="1" (
        echo [✗] GCC Compiler not found
    )
) else (
    echo [✓] GCC Compiler is installed
    g++ --version
)

echo.
echo ========================================

REM If anything missing, show instructions
if "%CMAKE_MISSING%"=="1" (
    if "%COMPILER_MISSING%"=="1" (
        cls
        echo.
        echo MISSING DEPENDENCIES DETECTED
        echo.
        echo Your system is missing:
        echo  - CMake (Build system)
        echo  - C++ Compiler (MSVC or GCC^/MinGW^)
        echo.
        echo QUICK FIX OPTIONS:
        echo.
        echo 1. Install Visual Studio Community with C++ support:
        echo    https://visualstudio.microsoft.com/vs/community/
        echo.
        echo 2. Install MinGW: https://www.mingw-w64.org/
        echo.
        echo 3. Install CMake: https://cmake.org/download/
        echo.
        echo Full instructions available in: SETUP.md
        echo.
        pause
    )
)

REM If everything is found, offer to build
if "%CMAKE_MISSING%"=="" (
    if "%COMPILER_MISSING%"=="" (
        cls
        echo.
        echo ========================================
        echo   ALL DEPENDENCIES FOUND!
        echo ========================================
        echo.
        echo Ready to build the project.
        echo.
        echo Would you like to build now?
        echo.
        echo Press 1 to build with Visual Studio
        echo Press 2 to build with MinGW
        echo Press 0 to skip
        echo.
        set /p BUILD_CHOICE="Enter choice (0/1/2): "
        
        if "%BUILD_CHOICE%"=="1" (
            if exist build (
                rmdir /s /q build
            )
            mkdir build
            cd build
            cmake .. -G "Visual Studio 16 2019"
            if errorlevel 1 (
                echo Build configuration failed!
                pause
                exit /b 1
            )
            cmake --build . --config Release
            if errorlevel 1 (
                echo Build failed!
                pause
                exit /b 1
            )
            echo.
            echo Build successful! Executable in: build\Release\StudentManagement.exe
            pause
        ) else if "%BUILD_CHOICE%"=="2" (
            if exist build (
                rmdir /s /q build
            )
            mkdir build
            cd build
            cmake .. -G "MinGW Makefiles"
            if errorlevel 1 (
                echo Build configuration failed!
                pause
                exit /b 1
            )
            cmake --build .
            if errorlevel 1 (
                echo Build failed!
                pause
                exit /b 1
            )
            echo.
            echo Build successful! Executable in: build\StudentManagement.exe
            pause
        )
    )
)

echo.
