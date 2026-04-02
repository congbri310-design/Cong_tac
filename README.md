# University Student Management System

A simple C++ console application for managing student records. Perfect for demonstration and learning purposes.

## Features

✓ **Add Students** - Create new student records with ID, name, major, and GPA
✓ **View All Students** - Display all registered students in a formatted table
✓ **Search Students** - Find students by ID or name
✓ **Edit Students** - Update student information
✓ **Delete Students** - Remove student records
✓ **Persistent Storage** - Save/load data to file for persistence

## Requirements

- C++17 or higher
- CMake 3.10+ (optional, for easy building)
- A C++ compiler (MSVC, GCC, or Clang)

## Building the Application

### Option 1: Using CMake (Recommended)

**On Windows (Visual Studio):**
```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

**On Windows (MinGW):**
```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

**On Linux/Mac:**
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Option 2: Direct Compilation

**Windows (MSVC):**
```bash
cl /EHsc /W4 main.cpp /Fe:StudentManagement.exe
```

**Windows (MinGW):**
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o StudentManagement.exe
```

**Linux/Mac:**
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o StudentManagement
```

## Running the Application

After building, run the application:

**Windows:**
```bash
StudentManagement.exe
```

**Linux/Mac:**
```bash
./StudentManagement
```

## Usage Example

```
======================== STUDENT MANAGEMENT SYSTEM ========================
1. Add Student
2. View All Students
3. Search Student
4. Edit Student
5. Delete Student
6. Exit
=========================================================================
Please choose an option (1-6): 1

--- Add New Student ---
Enter Student Name: John Doe
Enter Student Major: Computer Science
Enter Student GPA (0.0 - 4.0): 3.85

✓ Student added successfully! ID: 1
```

## Demo Workflow for Presentation

1. **Start the program** - Show the main menu
2. **Add 3-4 students** - Demonstrate data input
```
   - John Doe / Computer Science / 3.85
   - Jane Smith / Information Technology / 3.90
   - Bob Johnson / Software Engineering / 3.75
```
3. **View all students** - Show formatted table output
4. **Search a student** - Demonstrate search functionality
5. **Edit a student** - Show data modification
6. **Delete a student** - Show deletion
7. **Exit program** - Show that data is saved
8. **Restart program** - Show data persistence (students still there)

## Project Structure

```
c:\uet\coding\Cong_tac\
├── main.cpp           # Main application code
├── CMakeLists.txt     # Build configuration
├── README.md          # This file
└── students.dat       # Data file (created at runtime)
```

## Key C++ Concepts Demonstrated

- **STL Containers** - Using `vector` for dynamic storage
- **Structs** - Defining data structure for Student
- **File I/O** - Binary file reading/writing
- **Algorithms** - Using `find_if` for searching
- **String Handling** - C++ string class usage
- **Input/Output** - Stream operations with `cin` and `cout`
- **Menu-Driven Program** - Switch-case flow control

## Compilation Output

- **Executable:** `StudentManagement.exe` (Windows) or `StudentManagement` (Linux/Mac)
- **Data File:** `students.dat` (created automatically)

## Tips for Presentation

- Pre-populate some data for quicker demo
- Show the generated `students.dat` file after program exits
- Explain the binary format used in file I/O
- Demonstrate all features systematically
- Point out STL usage and C++ standard library features

## License

For educational purposes only.
