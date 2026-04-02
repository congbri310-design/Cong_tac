# Student Management System - Project Architecture

## 📁 Project Structure

```
c:\uet\coding\Cong_tac\
├── include/
│   ├── student.h           # Student data model
│   ├── database.h          # Database layer
│   ├── ui_manager.h        # UI management
│   └── app_controller.h    # Application controller
│
├── src/
│   ├── main.cpp            # Application entry point
│   ├── backend/
│   │   ├── student.cpp     # Student model implementation
│   │   └── database.cpp    # Database implementation
│   └── frontend/
│       ├── ui_manager.cpp  # UI implementation
│       └── app_controller.cpp  # Business logic
│
├── build/                  # Build output (generated)
│   └── bin/
│       └── StudentManagement.exe
│
├── CMakeLists.txt          # CMake build configuration
├── README.md               # Main documentation
├── ARCHITECTURE.md         # This file
├── QUICKSTART.md           # Quick start guide
├── build.bat               # Windows build script
├── build.sh                # Linux/Mac build script
└── students.dat            # Data file (generated at runtime)
```

## 🏗️ Architecture Overview

### Three-Layer Architecture

```
┌─────────────────────────────────────────────┐
│          PRESENTATION LAYER (FE)            │
│  - UIManager (Display & Input)              │
│  - AppController (Application Flow)         │
└────────────────┬────────────────────────────┘
                 │
┌────────────────┴────────────────────────────┐
│          BUSINESS LOGIC LAYER               │
│  - AppController (Request Handling)         │
│  - Validation & Processing                  │
└────────────────┬────────────────────────────┘
                 │
┌────────────────┴────────────────────────────┐
│         DATA ACCESS LAYER (BE)              │
│  - Database (CRUD Operations)               │
│  - Student (Data Model)                     │
│  - File I/O (Persistence)                   │
└─────────────────────────────────────────────┘
```

## 📦 Component Breakdown

### Backend (Data Layer)

#### `include/student.h` & `src/backend/student.cpp`
- **Purpose**: Student data model
- **Responsibilities**:
  - Store student attributes (ID, name, major, GPA)
  - Provide getters/setters with validation
  - Display formatted student data
- **Key Methods**:
  - `getId()`, `getName()`, `getMajor()`, `getGpa()`
  - `setId()`, `setName()`, `setMajor()`, `setGpa()`
  - `display()` - formatted output

#### `include/database.h` & `src/backend/database.cpp`
- **Purpose**: Data persistence & CRUD operations
- **Responsibilities**:
  - Manage student collection in memory
  - Perform CRUD operations (Create, Read, Update, Delete)
  - Handle file I/O (binary format)
  - Query operations
- **Key Methods**:
  - `addStudent()` - Add new student
  - `findStudentById()` - Search by ID
  - `findStudentByName()` - Search by name
  - `updateStudent()` - Modify student data
  - `deleteStudent()` - Remove student
  - `saveToFile()` - Persist to binary file
  - `loadFromFile()` - Load from file

### Frontend (Presentation Layer)

#### `include/ui_manager.h` & `src/frontend/ui_manager.cpp`
- **Purpose**: User interface management
- **Responsibilities**:
  - Display menus and student information
  - Handle user input
  - Format and present data
  - Display messages and errors
- **Key Methods**:
  - `displayMainMenu()` - Show main options
  - `displayAddStudentForm()` - Show add form
  - `displayAllStudents()` - Show student table
  - `getMenuChoice()` - Get user input
  - `getStudentInput()` - Get student form data
  - `displayMessage()` - Show success/error messages

#### `include/app_controller.h` & `src/frontend/app_controller.cpp`
- **Purpose**: Application control & business logic
- **Responsibilities**:
  - Control application flow
  - Handle user actions
  - Coordinate between UI and Database
  - Process business logic
- **Key Methods**:
  - `run()` - Main application loop
  - `handleAddStudent()` - Process add action
  - `handleViewAllStudents()` - Process view action
  - `handleSearchStudent()` - Process search action
  - `handleEditStudent()` - Process edit action
  - `handleDeleteStudent()` - Process delete action

### Entry Point

#### `src/main.cpp`
- **Purpose**: Application entry point
- **Responsibilities**:
  - Create and run AppController
  - Handle global exceptions

## 🔄 Data Flow

### Adding a Student
```
1. User selects "Add Student" → AppController.handleAddStudent()
2. AppController calls UIManager.displayAddStudentForm()
3. User enters data → UIManager.getStudentInput()
4. AppController creates Student object with next ID
5. AppController calls Database.addStudent()
6. Database saves to memory and file
7. Success message displayed
```

### Viewing Students
```
1. User selects "View All" → AppController.handleViewAllStudents()
2. AppController calls Database.findAllStudents()
3. Returns vector of Student pointers
4. AppController calls UIManager.displayAllStudents()
5. UIManager formats and displays data
```

### Searching Student
```
1. User selects "Search" → AppController.handleSearchStudent()
2. UIManager shows search options (ID or Name)
3. User enters search criteria
4. AppController calls appropriate Database method
5. Database searches in-memory collection
6. Result displayed via UIManager
```

## 📋 Design Patterns Used

### 1. **Model-View-Controller (MVC)**
- **Model**: Student + Database
- **View**: UIManager
- **Controller**: AppController

### 2. **Separation of Concerns**
- Backend: Data management (Student, Database)
- Frontend: User interaction (UIManager, AppController)
- Clear boundaries between layers

### 3. **Encapsulation**
- Private data members with public getters/setters
- Validation in setter methods
- Hidden implementation details

### 4. **Single Responsibility Principle**
- Each class has one clear purpose
- Student: Data storage and validation
- Database: Persistence and queries
- UIManager: Display and input
- AppController: Business logic and flow

## 🔐 Key Features

### Data Validation
- GPA clamped to 0.0-4.0 range
- Student ID auto-generated
- String validation for names/majors

### Error Handling
- File I/O exception handling
- Student not found checks
- Invalid input handling

### Modularity
- Easy to extend with new features
- Clean interfaces between components
- Testable code structure

## 🚀 Building & Running

### Using CMake
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd bin
StudentManagement.exe
```

### Direct Compilation
```bash
g++ -std=c++17 -I./include src/main.cpp src/backend/student.cpp \
    src/backend/database.cpp src/frontend/ui_manager.cpp \
    src/frontend/app_controller.cpp -o StudentManagement
```

## 📊 File Organization Benefits

✓ **Clarity**: Easy to navigate and understand project structure
✓ **Scalability**: Simple to add new features or modules
✓ **Maintainability**: Changes isolated to specific components
✓ **Reusability**: Backend can be used with different UI
✓ **Testing**: Easier to unit test individual components
✓ **Collaboration**: Multiple developers can work on different layers

## 🔧 Extending the Project

### Adding New Feature Example: GPA Sorting

1. Add method to `Database`:
```cpp
std::vector<Student*> getAllStudentsSortedByGPA();
```

2. Implement in `database.cpp`

3. Add option to `AppController`:
```cpp
case 7:
    handleViewStudentsByGPA();
    break;
```

4. Implement in `app_controller.cpp`

5. Add UI method to `UIManager` if needed

## 💡 Best Practices Implemented

- **Header Guards**: Prevent multiple inclusions
- **Const Correctness**: Immutable operations marked as const
- **Reference Parameters**: Avoid unnecessary copying
- **Exception Safety**: Try-catch for file operations
- **Documentation**: Clear comments and docstrings
- **Naming Conventions**: Clear, descriptive names
- **Code Organization**: Related code grouped together

---

This architecture makes the code professional, maintainable, and ready for extension!
