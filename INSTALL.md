# 📋 Complete Installation & Setup Instructions

## Current Project Status

✅ **Code Structure**: Complete  
❌ **Compiler**: Not installed  
❌ **CMake**: Not installed  

---

## What You Need to Install

### 1. **C++ Compiler** (Choose ONE)

#### Option A: Visual Studio Community (Recommended)
- **Size**: ~15 GB
- **Includes**: MSVC compiler + MSVC tools + VS IDE
- **Best for**: Beginners, has IDE included
- **Download**: https://visualstudio.microsoft.com/vs/community/
- **Setup**:
  1. Run installer
  2. Select "Desktop development with C++"
  3. Install (~30 minutes)
  4. Verify: Open PowerShell, type `cl.exe` (should show version)

#### Option B: MinGW-w64 (Lightweight)
- **Size**: ~750 MB
- **Includes**: GCC compiler only
- **Best for**: Command-line users, quick setup
- **Download**: https://www.mingw-w64.org/
- **Setup**:
  1. Run installer
  2. Select x86_64, posix, dwarf/seh
  3. Install to default location
  4. Add to PATH (see troubleshooting)
  5. Verify: Open PowerShell, type `g++ --version`

---

### 2. **CMake** (Required for both options above)

- **Size**: ~50 MB
- **Download**: https://cmake.org/download/
- **Step 1**: Select "Windows x64 Installer"
- **Step 2**: Run installer
- **Step 3**: ✓ Check "Add CMake to system PATH"
- **Step 4**: Complete installation
- **Step 5**: Verify: Open PowerShell, type `cmake --version`

---

## 🚀 Installation Steps (Quickest Method)

### Step 1: Install Visual Studio Community (~30 min)
```
1. Go to: https://visualstudio.microsoft.com/vs/community/
2. Click "Download Visual Studio Community"
3. Run the installer
4. Choose "Desktop development with C++"
5. Accept defaults and install
```

### Step 2: Install CMake (~5 min)
```
1. Go to: https://cmake.org/download/
2. Download "cmake-3.x.x-windows-x86_64.msi"
3. Run installer
4. Check "Add CMake to system PATH"
5. Click Install
```

### Step 3: Verify Installation
```powershell
# Open PowerShell and run:
cl.exe
cmake --version
```
Both should show version info (not "command not found")

### Step 4: Build the Project
```powershell
# In PowerShell, navigate to project:
cd c:\uet\coding\Cong_tac

# Run setup script:
.\setup.bat
# Follow prompts to build
```

### Step 5: Run the Application
```powershell
# After build completes:
.\build\Release\StudentManagement.exe
```

---

## 📁 Project Files Structure

```
c:\uet\coding\Cong_tac\
│
├── Documentation:
│   ├── README.md              ← Main documentation
│   ├── QUICKSTART.md          ← Quick start guide
│   ├── ARCHITECTURE.md        ← Project structure explanation
│   ├── SETUP.md               ← Detailed setup instructions
│   └── INSTALL.md             ← This file
│
├── Configuration:
│   ├── CMakeLists.txt         ← Build configuration
│   ├── build.bat              ← Auto build script (Windows)
│   ├── build.sh               ← Auto build script (Linux/Mac)
│   └── setup.bat              ← Dependency checker & builder
│
├── C++ Source Code:
│   ├── include/
│   │   ├── student.h          ← Student model header
│   │   ├── database.h         ← Database layer header
│   │   ├── ui_manager.h       ← UI manager header
│   │   └── app_controller.h   ← Controller header
│   │
│   ├── src/
│   │   ├── main.cpp           ← Entry point
│   │   ├── backend/
│   │   │   ├── student.cpp    ← Student implementation
│   │   │   └── database.cpp   ← Database implementation
│   │   └── frontend/
│   │       ├── ui_manager.cpp      ← UI implementation
│   │       └── app_controller.cpp  ← Controller implementation
│   │
│   └── build/                 ← Build output (created after build)
│       └── bin/
│           └── StudentManagement.exe
│
└── Runtime Data:
    └── students.dat           ← Student data file (created at runtime)
```

---

## ⚡ Quick Command Reference

### After Installation

**Check everything is installed:**
```powershell
cl.exe
g++ --version
cmake --version
```

**Build the project (Windows):**
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

**Build with MinGW:**
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

**Run the program:**
```powershell
# Windows/MSVC:
.\build\Release\StudentManagement.exe

# Windows/MinGW:
.\build\StudentManagement.exe

# Linux/Mac:
./build/StudentManagement
```

---

## 🔧 Troubleshooting

### Problem: "cmake is not recognized"
**Solution**:
1. Uninstall CMake
2. Reinstall and make sure to check "Add CMake to system PATH"
3. Close and reopen PowerShell
4. Type: `cmake --version`

### Problem: "cl.exe is not recognized" or "g++ is not recognized"
**Solution**:
1. Install Visual Studio or MinGW (see above)
2. Add compiler to system PATH if using MinGW
3. Close and reopen PowerShell
4. Type: `cl.exe` or `g++ --version`

### Problem: CMake says "No compiler found"
**Solution**:
1. Make sure compiler is installed first
2. Close and reopen PowerShell
3. Type `cmake --version` to verify CMake
4. Type `cl.exe` or `g++ --version` to verify compiler
5. Try CMake again

### Problem: Build fails with "permission denied"
**Solution**:
1. Close all running instances of the program
2. Delete the `build` folder
3. Create new `build` folder
4. Try again

### Problem: "Generator not found"
**Solution**:
1. Check available generators: `cmake -G`
2. Use correct generator for your compiler:
   - MSVC: "Visual Studio 16 2019" or "Visual Studio 17 2022"
   - MinGW: "MinGW Makefiles"

---

## 📊 Installation Time Estimates

| Method | Time | Difficulty |
|--------|------|------------|
| Visual Studio + CMake | 40-50 min | Easy (guided installer) |
| MinGW + CMake | 15-20 min | Medium (PATH setup) |
| Pre-installed tools | 5 min | Easy (just build) |

---

## ✅ Verification Checklist

After each step, verify:

- [ ] Visual Studio installed (if chosen)
- [ ] Compiler works: `cl.exe` or `g++ --version`
- [ ] CMake installed and in PATH: `cmake --version`
- [ ] Can create build folder without errors
- [ ] CMake configuration completes: `cmake ..`
- [ ] Build completes: `cmake --build .`
- [ ] Executable created: `StudentManagement.exe` exists
- [ ] Program runs: `StudentManagement.exe` starts UI

---

## 🎯 Success Indicators

✅ **All installed correctly** if you see:
```
C:\...\Cong_tac\build> cmake --version
cmake version 3.x.x

C:\...\Cong_tac\build> cl.exe
Microsoft (R) C/C++ Optimizing Compiler...

C:\...\Cong_tac\build> cmake ..
-- The C++ compiler identification is MSVC...
-- Configuring done
-- Generating done

C:\...\Cong_tac\build> cmake --build . --config Release
...
Build successful!
```

---

## 📞 Next Steps

1. **Install compiler + CMake** (follow options above)
2. **Verify installation** (run test commands)
3. **Build the project** (use build.bat or cmake commands)
4. **Run the program** (execute StudentManagement.exe)
5. **Reference** QUICKSTART.md for usage

---

**Need help?** Refer to:
- SETUP.md - More detailed instructions
- QUICKSTART.md - How to use the program
- ARCHITECTURE.md - Code structure explanation

Good luck! 🚀
