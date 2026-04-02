# QUICK START GUIDE

## For Windows Users - Fastest Way to Run

### Step 1: Double-click `build.bat`
This will automatically:
- Create a build folder
- Generate build files
- Compile the program
- Run the application

### Step 2: Follow the on-screen menu
The application has 6 main options:
1. Add Student - Enter new student data
2. View All Students - See all records in table format
3. Search Student - Find by ID or name
4. Edit Student - Modify student information
5. Delete Student - Remove a student record
6. Exit - Close the program

### Example Demo Flow (2-3 minutes)

```
1. Press 1 → Add 3 students:
   - Name: John Doe, Major: Computer Science, GPA: 3.85
   - Name: Jane Smith, Major: IT, GPA: 3.90
   - Name: Bob Johnson, Major: Software Eng, GPA: 3.75

2. Press 2 → View all students (shows formatted table)

3. Press 3 → Search for "John" (demonstrates search)

4. Press 4 → Edit John's GPA to 3.95

5. Press 2 → View again to show updated data

6. Press 6 → Exit program

7. Run build.bat again → Press 2 → Show data is saved!
```

## For Linux/Mac Users

### Step 1: Make script executable
```bash
chmod +x build.sh
```

### Step 2: Run the script
```bash
./build.sh
```

## Manual Compilation (All Platforms)

If CMake is not available:

**Windows (using MSVC):**
```bash
cl /EHsc main.cpp /Fe:StudentManagement.exe
StudentManagement.exe
```

**Linux/Mac (using g++):**
```bash
g++ -std=c++17 -Wall main.cpp -o StudentManagement
./StudentManagement
```

## Features Demonstrated

✓ Menu-driven interface
✓ Data structures (struct/vector)
✓ File I/O (binary format)
✓ String manipulation
✓ Formatted output (setw, setprecision)
✓ Search algorithms (find_if)
✓ Standard C++ libraries (algorithm, fstream, iostream)

## Presentation Tips

1. **Prepare data** - Have a quick list of 3-4 students to add
2. **Show the code** - Open main.cpp to explain key features
3. **Demonstrate persistence** - Show that data survives program restart
4. **Highlight C++ features** - Point out STL usage
5. **Interactive** - Let audience see the menu and features

## Troubleshooting

**Build fails?**
- Install CMake: https://cmake.org/download/
- Ensure C++ compiler is installed (MSVC, GCC, or Clang)

**Program won't compile?**
- Use C++17 standard: `-std=c++17`
- Check file path is correct

**Can't find executable?**
- After build, check `build/` or `build/Release/` folder
- On Windows: Look for `StudentManagement.exe`
- On Linux/Mac: Look for `StudentManagement` (no extension)

## Project Files Explained

| File | Purpose |
|------|---------|
| `main.cpp` | Source code - all functionality |
| `CMakeLists.txt` | Build configuration |
| `build.bat` | Windows build & run script |
| `build.sh` | Linux/Mac build & run script |
| `README.md` | Full documentation |
| `QUICKSTART.md` | This file |
| `students.dat` | Data file (created auto) |

---

**Ready to present?** Just run `build.bat` and start adding students!
