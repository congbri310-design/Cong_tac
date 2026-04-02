# Installation & Setup Guide

## ⚠️ Current Status

Your system is missing:
- ❌ **CMake** - Build system
- ❌ **C++ Compiler** - (MSVC or GCC)

## 🚀 Installation Options

### Option 1: Visual Studio Community (Recommended - All-in-One)

**Most beginner-friendly. Includes compiler + many tools.**

**Step 1: Download Visual Studio Community**
1. Go to: https://visualstudio.microsoft.com/vs/community/
2. Click "Download Visual Studio Community"
3. Run the installer

**Step 2: Select C++ Workload**
1. When installer opens, select **"Desktop development with C++"**
2. This includes:
   - MSVC Compiler
   - CMake (optional, can be added separately)
   - C++ libraries
3. Click "Install"
4. Wait for installation (15-30 minutes)

**Step 3: Verify Installation**
```powershell
cl.exe
```
Should show MSVC compiler info (not "command not found")

**Step 4: Install CMake**
1. Download from: https://cmake.org/download/
2. Download "Windows x64 Installer" (cmake-3.x.x-windows-x86_64.msi)
3. Run installer
4. ✓ Check "Add CMake to system PATH"
5. Complete installation

**Step 5: Verify CMake**
```powershell
cmake --version
```
Should show version number

---

### Option 2: MinGW + Standalone CMake (Lightweight)

**Smaller download but requires more manual setup.**

**Step 1: Install MinGW-w64 (GCC Compiler)**
1. Go to: https://www.mingw-w64.org/
2. Download "Online Installer"
3. Run installer
4. Settings:
   - Architecture: x86_64
   - Threads: posix
   - Exception: dwarf or seh
   - Build revision: 0
5. Complete installation (installs to `C:\Program Files\mingw-w64` by default)

**Step 2: Add MinGW to PATH**
1. Right-click "This PC" → Properties
2. Click "Advanced system settings"
3. Click "Environment Variables"
4. Under "System variables", select "Path" → Edit
5. Click "New" and add: `C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`
6. Click OK three times

**Step 3: Verify GCC**
```powershell
g++ --version
```
Should show version (e.g., "g++ (x86_64-posix-seh, built by MinGW-w64 project) 8.1.0")

**Step 4: Install CMake**
1. Go to: https://cmake.org/download/
2. Download "Windows x64 Installer" (cmake-3.x.x-windows-x86_64.msi)
3. Run installer
4. ✓ Check "Add CMake to system PATH"
5. Complete installation

**Step 5: Verify CMake**
```powershell
cmake --version
```
Should show version number

---

### Option 3: Automated Installation via Chocolatey (If Installed)

If you have Chocolatey installed:

```powershell
# Run as Administrator in PowerShell
choco install cmake visualstudio2019-community
```

---

## ✅ Verification Checklist

After installation, run these commands to verify:

**Check CMake:**
```powershell
cmake --version
```
Expected output: `cmake version 3.x.x`

**Check C++ Compiler:**
```powershell
# For MSVC:
cl.exe

# For GCC/MinGW:
g++ --version
```

**Check if can build:**
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
# or for MinGW:
cmake .. -G "MinGW Makefiles"
```

---

## 🔧 Build Configuration

### For Visual Studio Users
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

### For MinGW Users
```powershell
cd c:\uet\coding\Cong_tac
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

---

## ⚡ Quick Fix Summary

**Fastest Solution (30-45 min):**
1. Download Visual Studio Community
2. Install with C++ workload
3. Download & install CMake
4. Run: `build.bat`
5. Done! ✓

**Lightweight Solution (15-20 min):**
1. Download MinGW-w64
2. Install and add to PATH
3. Download & install CMake 
4. Run appropriate CMake commands
5. Done! ✓

---

## 🆘 Troubleshooting

### "cmake is not recognized"
- **Solution**: Add CMake to PATH
  - Control Panel → Environment Variables → Add CMake binary folder to Path
  - Restart terminal/PowerShell after adding

### "cl.exe is not recognized" (MSVC)
- **Solution**: Install Visual Studio or MinGW
  - Or use VS Developer Command Prompt (comes with VS)

### "g++ is not recognized" (MinGW)
- **Solution**: Add MinGW bin folder to PATH
  - Path should be: `C:\Program Files\mingw-w64\x86_64-...\mingw64\bin`

### CMake configuration fails
- **Solution**: Make sure you're using correct generator
  - Use `cmake -G` to list available generators
  - For VS: "Visual Studio 16 2019" or "Visual Studio 17 2022"
  - For MinGW: "MinGW Makefiles"

### After installation, still can't find tools
- **Restart PowerShell/Command Prompt** (close and reopen)
- PATH variables only apply to newly opened terminals

---

## 📦 Project Dependencies

Good news! Your C++ project has **NO external library dependencies**:
- ✓ Uses only C++ Standard Library
- ✓ No need for: boost, OpenGL, Qt, etc.
- ✓ Once compiler + CMake installed, you're ready to go!

---

## 🎯 Next Steps

1. Install compiler & CMake using Option 1 or 2 above
2. Verify installation with commands above
3. Navigate to project folder
4. Run: `build.bat` (Windows) or follow build instructions
5. Run executable from `build/bin/StudentManagement.exe`

**Estimated total installation time: 30-60 minutes depending on internet speed**

---

Need help? Check the error message and troubleshooting section above!
