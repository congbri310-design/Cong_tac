#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"
#include "user.h"
#include "course.h"
#include "grade.h"
#include <vector>
#include <string>

/**
 * @class Database
 * @brief Manages student, user, course, and grade data persistence and operations
 */
class Database {
private:
    std::vector<Student> students;
    std::vector<User> users;
    std::vector<Course> courses;
    std::vector<Grade> grades;
    
    std::string studentFile;
    std::string userFile;
    std::string courseFile;
    std::string gradeFile;

public:
    // Constructor
    Database(const std::string& dataFolder = "data/");

    // ===== STUDENT CRUD =====
    void addStudent(const Student& student);
    Student* findStudentById(int id);
    Student* findStudentByStudentId(const std::string& studentId);  // Search by MSSV
    std::vector<Student*> findStudentsByName(const std::string& name);
    std::vector<Student*> findAllStudents();
    bool updateStudent(int id, const Student& updated);
    bool deleteStudent(int id);
    int getNextStudentId() const;
    int getTotalStudents() const;
    bool studentExists(int id);

    // ===== USER CRUD =====
    void addUser(const User& user);
    User* findUserById(int id);
    User* findUserByUsername(const std::string& username);
    std::vector<User*> findAllUsers();
    bool updateUser(int id, const User& updated);
    bool deleteUser(int id);
    bool authenticateUser(const std::string& username, const std::string& password);
    int getNextUserId() const;
    bool userExists(const std::string& username);

    // ===== COURSE CRUD =====
    void addCourse(const Course& course);
    Course* findCourseById(int id);
    Course* findCourseByName(const std::string& name);
    std::vector<Course*> findAllCourses();
    bool updateCourse(int id, const Course& updated);
    bool deleteCourse(int id);
    int getNextCourseId() const;
    int getTotalCourses() const;

    // ===== GRADE CRUD & OPERATIONS =====
    void addGrade(const Grade& grade);
    Grade* findGradeById(int id);
    std::vector<Grade*> findGradesByStudentId(int studentId);
    std::vector<Grade*> findGradesByStudentAndCourse(int studentId, int courseId);
    std::vector<Grade*> findAllGrades();
    bool updateGrade(int id, const Grade& updated);
    bool deleteGrade(int id);
    int getNextGradeId() const;
    
    // Calculate GPA for a student
    float calculateStudentGPA(int studentId);
    float calculateStudentGPAWithCredits(int studentId);  // Weighted GPA with credits

    // Get grades for a student in a readable format
    void displayStudentGrades(int studentId);

    // ===== FILE OPERATIONS =====
    void saveAllData();
    void loadAllData();

private:
    void saveStudentsToFile();
    void saveUsersToFile();
    void saveCoursesToFile();
    void saveGradesToFile();
    
    void loadStudentsFromFile();
    void loadUsersFromFile();
    void loadCoursesFromFile();
    void loadGradesFromFile();
};

#endif // DATABASE_H
