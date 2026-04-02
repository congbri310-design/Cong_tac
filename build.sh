#!/bin/bash

echo "===================================="
echo "Student Management System Builder"
echo "===================================="
echo ""

# Create build directory
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build

echo "Generating build files with CMake..."
cmake ..

echo ""
echo "Building the project..."
cmake --build .

if [ $? -ne 0 ]; then
    echo "Build failed!"
    cd ..
    exit 1
fi

echo ""
echo "===================================="
echo "Build Successful!"
echo "===================================="
echo ""

cd ..

echo "Running StudentManagement..."
echo ""

if [ -f "build/StudentManagement" ]; then
    ./build/StudentManagement
else
    echo "Could not find executable!"
    exit 1
fi
