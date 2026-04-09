# Build and Setup Instructions

## Prerequisites
- **Windows OS** (Windows 10 or later)
- **Visual Studio 2019+** OR **MinGW/G++**
- **CMake 3.10+** (Download from https://cmake.org/download/)

## Installation Steps

### Step 1: Install CMake
1. Visit https://cmake.org/download/
2. Download the Windows installer
3. Run the installer and add CMake to your system PATH
4. Verify installation:
   ```
   cmake --version
   ```

### Step 2: Install C++ Compiler
Choose ONE of the following:

#### Option A: Visual Studio (Recommended for Windows)
1. Install Visual Studio Community 2019/2022 (Free)
2. Select "Desktop development with C++" workload
3. Ensure "MSVC" compiler is installed

#### Option B: MinGW (Alternative)
1. Download from: http://www.mingw.org/download
2. Install MinGW with G++ compiler
3. Add MinGW to system PATH

### Step 3: Build the Project

#### Method 1: Using the Provided Build Script
```bash
# From project root directory
build.bat
```

This will:
- Create a build directory
- Run CMake to generate build files
- Compile the project
- Automatically run the executable

#### Method 2: Manual CMake Build
```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"  # or "MinGW Makefiles"
cmake --build . --config Release
cd ..
./build/Release/StudentManagement.exe
```

#### Method 3: Using setup.bat
```bash
setup.bat
```

## Directory Structure After Build
```
project_root/
├── build/
│   ├── Release/
│   │   └── StudentManagement.exe
│   └── [CMake build files]
├── bin/
│   └── StudentManagement.exe (copy)
└── data/
    ├── students.dat
    ├── users.dat
    ├── courses.dat
    └── grades.dat
```

## First Time Setup

### Creating Default Data
When you first run the application:

1. **Default Admin Account is Created Automatically**
   - Username: `admin`
   - Password: `admin123`

2. **Data Files Created**
   - The `data/` directory is created automatically
   - Binary data files are generated on first save

3. **Sample Data Entry**
   - Add a few students
   - Create sample courses
   - Input some grades
   - Test the system

## Troubleshooting

### Error: "cmake: command not found"
**Solution:** Install CMake and add to PATH
```bash
# Or use full path
"C:\Program Files\CMake\bin\cmake" --version
```

### Error: "MSVC compiler not found"
**Solution:** 
- Install Visual Studio with C++ workload
- Or use MinGW: `cmake .. -G "MinGW Makefiles"`

### Error: "Cannot open file for writing"
**Solution:**
- The `data/` directory doesn't exist yet
- Manually create: `mkdir data`
- Or the application will create it on first save

### Build succeeds but executable not found
**Solution:** Check these locations:
- `build\Release\StudentManagement.exe` (MSVC)
- `build\StudentManagement.exe` (MinGW)
- The build.bat should have found it automatically

## Environment Variables

### Windows PATH Setup
The following should be in your System PATH:
```
C:\Program Files\CMake\bin
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\[version]\bin\Hostx64\x64
```

Or for MinGW:
```
C:\MinGW\bin
C:\mingw64\bin
```

## Running the Application

### From Build Directory
```bash
cd build
Release\StudentManagement.exe
```

### From Project Root (After build.bat)
```bash
# Automatic if build.bat completes successfully
StudentManagement  # Should open automatically
```

### Or manually
```bash
.\build\Release\StudentManagement.exe
```

## Data Persistence

All data is automatically saved to binary files:
- `data/students.dat` - Student records
- `data/users.dat` - User accounts  
- `data/courses.dat` - Course information
- `data/grades.dat` - Grade records

Data persists between sessions automatically.

## Resetting Data

To reset all data and start fresh:
1. Delete the `data/` folder (or individual .dat files)
2. Run the application again
3. New default files will be created
4. Default admin account will be recreated

## Testing the Build

After successful build, verify with a test run:
```bash
# Quick verification
StudentManagement.exe

# Login with:
# Username: admin
# Password: admin123
# Then logout
```

## Performance Notes
- Loading database: ~1-2ms
- Adding student: ~1-5ms  
- Calculating GPA: <1ms per student
- Typical session memory usage: 10-50MB

## Advanced Build Options

### With Debug Symbols
```bash
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
```

### With Optimization
```bash
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

### Clean Build
```bash
rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Support & Help
If you encounter issues:
1. Check that cmake --version works
2. Verify compiler is installed: `cl.exe` (MSVC) or `g++ --version`
3. Ensure you have write permissions in the project directory
4. Check that files were compiled: `dir build\Release\*`
5. See INSTALL.md for more details

## Next Steps After Building
1. Run the application
2. Login as admin (admin/admin123)
3. Add some students
4. Add some courses
5. Input grades
6. View reports
7. Read SYSTEM_OVERVIEW.md for complete feature documentation
