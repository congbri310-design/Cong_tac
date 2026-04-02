# ✅ Installation Checklist

## 🎯 Goal
Get the Student Management System up and running

## ⏱️ Time Required
**Total: ~45-60 minutes**
- Download & install tools: 40-50 min
- Build project: 2-5 min
- First run: 1 min
- Read documentation: 5-10 min

---

## 📋 Pre-Installation Checklist

- [ ] I have internet connection (for downloads)
- [ ] I have admin rights to install software
- [ ] I have 20+ GB free disk space (for Visual Studio)
  - OR 1 GB+ (for MinGW only)
- [ ] I can open PowerShell/Command Prompt
- [ ] I have VS Code or text editor to view code

---

## 🔧 Installation Steps

### STEP 1: Install C++ Compiler (Choose Option A or B)

#### Option A: Visual Studio Community ✅ Recommended

Installation steps:
- [ ] Visit: https://visualstudio.microsoft.com/vs/community/
- [ ] Click "Download Visual Studio Community"
- [ ] Run `VisualStudioSetup.exe`
- [ ] When installer opens, select **"Desktop development with C++"**
- [ ] Click "Install" on the bottom right
- [ ] Wait for installation (30-45 minutes)
- [ ] Restart computer if prompted

Verification:
- [ ] Open PowerShell
- [ ] Type: `cl.exe`
- [ ] Should show: `Microsoft (R) C/C++ Optimizing Compiler` (with version)

#### Option B: MinGW (Lightweight Alternative)

Installation steps:
- [ ] Visit: https://www.mingw-w64.org/
- [ ] Click "Recommended Downloads"
- [ ] Download "Online Installer"
- [ ] Run installer
- [ ] Settings:
  - [ ] Architecture: **x86_64**
  - [ ] Threads: **posix**
  - [ ] Exception: **seh** or **dwarf**
  - [ ] Build revision: **0**
- [ ] Click "Next" and wait for installation (10-15 minutes)
- [ ] Note installation path (usually `C:\Program Files\mingw-w64`)

Verification:
- [ ] Open PowerShell
- [ ] Type: `g++ --version`
- [ ] Should show version (e.g., `g++ (x86_64-posix-seh, built by MinGW-w64 project) 8.1.0`)

**IMPORTANT for MinGW**: Add to PATH
- [ ] Right-click "This PC" → "Properties"
- [ ] Click "Advanced system settings"
- [ ] Click "Environment Variables..." button
- [ ] Under "System variables" section, select "Path"
- [ ] Click "Edit..."
- [ ] Click "New"
- [ ] Add: `C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`
- [ ] Click "OK" three times
- [ ] Close and reopen PowerShell
- [ ] Test: Type `g++ --version`

---

### STEP 2: Install CMake

Installation steps:
- [ ] Visit: https://cmake.org/download/
- [ ] Find "Windows x64 Installer" section
- [ ] Download: `cmake-3.x.x-windows-x86_64.msi`
- [ ] Run the installer
- [ ] When asked to add to PATH:
  - [ ] ✓ CHECK "Add CMake to system PATH"
- [ ] Select "Install for all users" (recommended)
- [ ] Click "Install"
- [ ] Wait for installation (2-5 minutes)
- [ ] Close installer

Verification:
- [ ] Close any open PowerShell windows
- [ ] Open NEW PowerShell window
- [ ] Type: `cmake --version`
- [ ] Should show: `cmake version 3.x.x` (any version 3.10+)

---

## ✅ Verification Checklist

After installation, verify everything works:

### Test Compiler
```powershell
# Windows MSVC:
cl.exe
# OR
# Windows MinGW:
g++ --version
```
- [ ] **Expected**: Version information (NOT "command not found")

### Test CMake
```powershell
cmake --version
```
- [ ] **Expected**: `cmake version 3.x.x`

### Test Build System
```powershell
cd c:\uet\coding\Cong_tac
cmake --version
cl.exe
```
- [ ] Both show version info ✓

---

## 🏗️ Build the Project

### Using setup.bat (Easiest)
```powershell
cd c:\uet\coding\Cong_tac
.\setup.bat
```
- [ ] Dependency check runs
- [ ] Choose build option (1 or 2)
- [ ] Build completes without errors

### Using Manual CMake
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```
- [ ] CMake configures successfully
- [ ] Build completes without errors
- [ ] Executable created in `Release\` folder

---

## 🚀 Run the Application

### Find Executable
- [ ] Navigate to: `c:\uet\coding\Cong_tac\build\`
- [ ] Look for: `StudentManagement.exe` (or `Release\StudentManagement.exe`)

### Run Program
```powershell
# Windows:
.\StudentManagement.exe
# OR
.\Release\StudentManagement.exe
```
- [ ] Program starts
- [ ] Main menu appears
- [ ] Can add students
- [ ] Can view all students
- [ ] Can search and edit
- [ ] Can exit gracefully

---

## 📁 Project Files Verification

Check that all files are present:

### Documentation Files
- [ ] README.md
- [ ] INSTALL.md ← Good to read
- [ ] SETUP.md
- [ ] ARCHITECTURE.md
- [ ] QUICKSTART.md
- [ ] START_HERE.txt

### Source Code
- [ ] include/student.h
- [ ] include/database.h
- [ ] include/ui_manager.h
- [ ] include/app_controller.h
- [ ] src/main.cpp
- [ ] src/backend/student.cpp
- [ ] src/backend/database.cpp
- [ ] src/frontend/ui_manager.cpp
- [ ] src/frontend/app_controller.cpp

### Build Files
- [ ] CMakeLists.txt
- [ ] build.bat
- [ ] app_controller.bat
- [ ] setup.bat

---

## 🎯 Final Checklist

- [ ] Compiler installed and working
- [ ] CMake installed and in PATH
- [ ] All source files present
- [ ] Project builds successfully
- [ ] Executable runs
- [ ] Application menu appears
- [ ] Can perform all operations:
  - [ ] Add student
  - [ ] View all students
  - [ ] Search student
  - [ ] Edit student
  - [ ] Delete student
  - [ ] Exit program
- [ ] Data saves to file
- [ ] Can restart and see saved data

---

## 🆘 Troubleshooting

If something doesn't work:

| Problem | Solution |
|---------|----------|
| **cmake not found** | Reinstall CMake, check "Add to PATH", restart PowerShell |
| **Compiler not found** | Install Visual Studio or MinGW, restart PowerShell |
| **Build fails** | Delete `build` folder, create new one, try again |
| **CMake can't find compiler** | Install compiler FIRST, then use CMake |
| **Can't find executable** | Check `build/Release/` (MSVC) or `build/` (MinGW) |
| **"Permission denied"** | Close any running instances, delete build folder, try again |

See [SETUP.md](SETUP.md) for more detailed troubleshooting.

---

## 📞 What to Do If Stuck

1. **Can't install?** → Read [SETUP.md](SETUP.md) - detailed instructions
2. **Build fails?** → See troubleshooting section above
3. **What to run?** → Read [QUICKSTART.md](QUICKSTART.md)
4. **How code works?** → Read [ARCHITECTURE.md](ARCHITECTURE.md)

---

## 🎓 Next Steps After Setup

1. ✅ Verify everything works
2. 📖 Read [QUICKSTART.md](QUICKSTART.md) - How to use the app
3. 🏗️ Read [ARCHITECTURE.md](ARCHITECTURE.md) - How the code is structured
4. 💻 Explore source files in editor
5. 🚀 Add new features!

---

## ⏱️ Estimated Timeline

| Task | Time | Done? |
|------|------|-------|
| Download Visual Studio/MinGW | 10-20 min | [ ] |
| Install Visual Studio/MinGW | 20-30 min | [ ] |
| Download & install CMake | 5-10 min | [ ] |
| Verify installation | 2 min | [ ] |
| Build project | 2-5 min | [ ] |
| First run | 1 min | [ ] |
| **TOTAL** | **~45-60 min** | [ ] |

---

## ✨ Success Indicators

You're done when:
- ✅ Can run commands: `cl.exe`, `g++`, `cmake --version`
- ✅ Can build: `cmake ..` succeeds
- ✅ Executable created: `StudentManagement.exe` exists
- ✅ App runs: See main menu
- ✅ Can add/view students
- ✅ Data saves (confirmed on restart)

---

**You're all set! Happy coding! 🚀**

Next: Read [QUICKSTART.md](QUICKSTART.md)
