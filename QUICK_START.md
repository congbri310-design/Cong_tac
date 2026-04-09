# Quick Start Guide

## First Run

### 1. Launch Application
```bash
StudentManagement.exe
```

### 2. Welcome Screen
You'll see:
- Welcome message  
- Default credentials shown
- Instructions to login

### 3. Login As Admin
- **Username:** admin
- **Password:** admin123

## Admin Menu Options

### Option 1: Student Management

#### Add Student
- Click "1. Add Student"
- Enter student name
- Enter Student ID Code (MSSV) - e.g., "SV20220001"
- Enter major - e.g., "Information Technology"
- System auto-generates internal ID

#### View All Students  
- Click "2. View All Students"
- See table of all students with names, MSSV, majors, and current GPA

#### Search Student
- Click "3. Search Student"
- Choose search by MSSV or Name
- View student details

#### Edit Student
- Click "4. Edit Student"
- Enter student internal ID
- Change name, MSSV, or major
- GPA is automatically calculated (not manually editable)

#### Delete Student
- Click "5. Delete Student"
- Enter student internal ID
- Confirm deletion
- All associated grades are automatically deleted

### Option 2: Course Management

#### Add Course
- Click "6. Manage Courses"
- Then "1. Add Course"
- Enter course name - e.g., "Programming in C++"
- Enter credit hours - e.g., "3"

#### View Courses
- Click "6. Manage Courses"  
- Then "2. View All Courses"
- See all courses with credits

### Option 3: Grade Management

#### Input Grades
- Click "7. Input Grades"
- Enter student internal ID
- Choose course from list
- Enter score (0.0 to 10.0)
- Student's GPA is automatically recalculated

#### View All Grades
- Click "8. View All Grades"
- See grade table showing:
  - Student names
  - Course names
  - Scores

## Student Menu Options

### Option 1: View Personal Information
- See your name, MSSV, major
- View your current GPA

### Option 2: View My Grades
- See detailed grade report
- Courses you're enrolled in
- Individual scores for each course
- Your average and GPA (4.0 scale)

## Common Tasks

### Task 1: Add Students and Courses

1. Login as admin
2. Add 3 students:
   - Student Name, MSSV (SV0001-0003), Major
3. Add 2 courses:
   - Course names with credits (3 or 4)

### Task 2: Input Grades for Students

1. Select "7. Input Grades"
2. Choose student ID
3. Pick a course
4. Enter score (e.g., 8.5 out of 10)
5. Repeat for different student/course combinations

### Task 3: View Student Grade Report

1. Select "8. View All Grades"
2. See all grades in table format
3. Or select "3. Search Student" then view individual student

### Task 4: Create Student Account

1. Add a student first (e.g., "Nguyen Van A")
2. While in admin menu, have admin add a user account
3. Create user account linking to that student ID
4. Student can now login and view their grades

## Example Session

```
=== Welcome ===
Username: admin
Password: admin123

=== Admin Menu ===
Choose: 1 (Add Student)
Name: Nguyen Van A
MSSV: SV202200001
Major: Computer Science

Choose: 1 (Add Student)
Name: Tran Thi B
MSSV: SV202200002
Major: Information Technology

Choose: 6 (Manage Courses)
→ Choose: 1 (Add Course)
  Name: Programming in C++
  Credits: 3
  
→ Choose: 1 (Add Course)
  Name: Data Structures
  Credits: 4

Choose: 7 (Input Grades)
Student ID: 1
Course: 1 (Programming in C++)
Score: 8.5

Choose: 8 (View All Grades)
[See grade table]

Choose: 9 (Logout)
```

## Tips

- **GPA Auto-Calculation:** Enter a grade and see GPA update automatically
- **MSSV:** Use format like "SV202200001" for student codes
- **Courses:** Add credits before inputting grades (affects weighted GPA)
- **Scores:** 0-10 scale (7.0+ is generally passing)
- **Data Safety:** All data saves automatically to data/*.dat files

## Keyboard Shortcuts
- When asked for input, press **Enter** to submit
- When asked for confirmation, type **yes** to confirm deletion
- **Ctrl+C** in terminal to force exit (not recommended)

## Troubleshooting Quick Tips

| Issue | Solution |
|-------|----------|
| Login fails | Use `admin` / `admin123` |
| No students | Add students first (Menu option 1) |
| Calculator error in grades | Make sure course exists before adding grades |
| GPA not updating | Add more grades for more accurate calculation |
| Data lost | Check if `data/` folder exists with `.dat` files |
| Can't search | Try searching by exact MSSV first |

## Default Data Files Created

After first run, these files appear in `data/` folder:
- `students.dat` - Your student records
- `users.dat` - Login accounts  
- `courses.dat` - Course information
- `grades.dat` - All student grades

These are binary files (don't edit manually).

## Common Scores/GPA Guide

| 0-10 Scale | 4.0 Scale | Meaning |
|-----------|-----------|---------|
| 0.0-3.9   | 0.0-1.56  | Fail |
| 4.0-5.9   | 1.6-2.36  | Poor |
| 6.0-6.9   | 2.4-2.76  | Satisfactory |
| 7.0-7.9   | 2.8-3.16  | Good |
| 8.0-8.9   | 3.2-3.56  | Very Good |
| 9.0-10.0  | 3.6-4.0   | Excellent |

## Next Steps

1. ✓ Build the application
2. ✓ Run it for the first time
3. ✓ Login as admin
4. ✓ Add students and courses
5. ✓ Input some grades
6. ✓ View the grades
7. → Create a student account
8. → Have student login to view their grades
9. → Read SYSTEM_OVERVIEW.md for detailed features

For more information, see [SYSTEM_OVERVIEW.md](SYSTEM_OVERVIEW.md)
