# Student Management System - Updated Documentation

## Overview
This is a comprehensive Student Management System with three main features:
1. **Student Profile Management** - CRUD operations with search/filter
2. **Grade & Academic Management** - Course management and GPA calculation
3. **Account & Permission System** - Role-based access control

## New Features

### 1. Authentication & Role-Based Access
- **Admin Account** (Default: `admin` / `admin123`)
  - Full permissions to manage students, courses, and grades
  - Can create and edit student accounts
  - Can input and modify grades
  
- **Student Account** (Read-only access)
  - Can only view own personal information
  - Can only view own grades
  - Cannot modify any data

### 2. Student Profile Management
- **Fields:**
  - Student ID (Internal ID)
  - Student ID Code (MSSV) - Student identification code
  - Name
  - Major/Program
  - GPA (Calculated automatically from grades)

- **Operations:**
  - Add new student
  - View all students (table format)
  - Search by MSSV or Name
  - Edit student information
  - Delete student (cascades to delete associated grades)

### 3. Course Management
- **Fields:**
  - Course ID
  - Course Name
  - Credit Hours

- **Operations:**
  - Add courses
  - View all courses
  - Delete courses (cascades to delete associated grades)

### 4. Grade Management
- **Features:**
  - Input grades for students in specific courses
  - Score range: 0.0 - 10.0
  - Automatic GPA calculation:
    - Simple GPA: Average of all scores (0-10 scale converted to 4.0 scale)
    - Weighted GPA: Credit-hour weighted calculation
  - View all grades in table format
  - View individual student grades

### 5. GPA Calculation
- **Formula:** GPA = (Score / 10.0) × 4.0 for each course
- **Weighted GPA:** (Sum of (Adjusted_Score × Credits)) / Total_Credits
- GPA is automatically updated when grades are added or modified

## File Structure

```
include/
  ├── student.h        - Student class with MSSV field
  ├── user.h          - User/Account class with roles
  ├── course.h        - Course class
  ├── grade.h         - Grade/Score class
  ├── database.h      - Database management class
  ├── app_controller.h - Application controller
  └── ui_manager.h    - User interface manager

src/
  ├── main.cpp
  ├── backend/
  │   ├── student.cpp
  │   ├── user.cpp
  │   ├── course.cpp
  │   ├── grade.cpp
  │   └── database.cpp
  └── frontend/
      ├── app_controller.cpp
      └── ui_manager.cpp

data/
  ├── students.dat
  ├── users.dat
  ├── courses.dat
  └── grades.dat
```

## Data Storage
All data is stored in binary format in the `data/` folder for persistence:
- `students.dat` - Student records
- `users.dat` - User accounts and authentication
- `courses.dat` - Course information
- `grades.dat` - Student grades

## Default Admin Account
- Username: `admin`
- Password: `admin123`

## Usage Flow

### For Admin Users:
1. Login with admin credentials
2. Choose from admin menu:
   - Manage Students (CRUD operations)
   - Manage Courses (Add/Delete courses)
   - Input Grades (Assign scores to students)
   - View All Grades (Review grade records)
   - Logout

### For Student Users:
1. Login with student credentials
2. Choose from student menu:
   - View Personal Information (Read-only)
   - View My Grades (With GPA calculation)
   - Logout

## Technical Details

### Class Hierarchy
- **User** - Manages authentication with roles (ADMIN/STUDENT)
- **Student** - Core student data model
- **Course** - Course information with credits
- **Grade** - Relationship between students and courses with scores
- **Database** - Central data management for all entities
- **AppController** - Application logic and flow
- **UIManager** - All user interface operations

### Key Methods

#### Database
- `addStudent()`, `findStudentById()`, `updateStudent()`, `deleteStudent()`
- `addUser()`, `findUserByUsername()`, `authenticateUser()`
- `addCourse()`, `findCourseById()`, `deleteCourse()`
- `addGrade()`, `findGradesByStudentId()`, `calculateStudentGPAWithCredits()`
- `saveAllData()`, `loadAllData()`

#### AppController
- `login()` - Authentication
- `handleAdminMenu()` - Admin operations
- `handleStudentMenu()` - Student operations
- `handleInputGrades()` - Grade management

## Building and Running

### Prerequisites
- CMake 3.10 or higher
- C++17 compiler
- Windows (primary), Linux/macOS compatible

### Build Instructions

#### Windows (using build.bat):
```batch
build.bat
```

#### Manual build:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

#### Run:
```bash
./bin/StudentManagement.exe
```

## Sample Workflow

1. **Start Application**
   - See welcome screen with default credentials

2. **Login as Admin** (admin/admin123)
   - Access admin menu

3. **Add Students**
   - Input: Name, MSSV, Major
   - System auto-generates internal ID

4. **Add Courses**
   - Input: Course Name, Credit Hours

5. **Input Grades**
   - Select Student → Select Course → Enter Score (0-10)
   - GPA auto-calculated and updated

6. **View Report**
   - View all students with current GPA
   - View individual student grades with weighted GPA

7. **Create Student Account** (Optional)
   - Add user with STUDENT to related student ID
   - Student can login and view own grades

## Security Notes
- Passwords stored in binary format (plaintext - for demo purposes)
- Role-based access control enforced at application level
- Student accounts can only access own data

## Future Enhancements
- Encryption for password storage
- More sophisticated GPA calculation methods
- Transcript generation
- Email notifications
- Web interface
- Database backend (SQL)
- User management interface for admins

## Support
For issues or questions, please refer to the main README.md file.
