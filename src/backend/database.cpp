#include "database.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <direct.h>

/**
 * Constructor - initializes database with filenames
 */
Database::Database(const std::string& dataFolder) 
    : studentFile(dataFolder + "students.dat"),
      userFile(dataFolder + "users.dat"),
      courseFile(dataFolder + "courses.dat"),
      gradeFile(dataFolder + "grades.dat") {
    
    // Create data folder if it doesn't exist
    _mkdir(dataFolder.c_str());
    
    loadAllData();
}

// ===== STUDENT CRUD =====

void Database::addStudent(const Student& student) {
    students.push_back(student);
    saveStudentsToFile();
}

Student* Database::findStudentById(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        return &(*it);
    }
    return nullptr;
}

Student* Database::findStudentByStudentId(const std::string& studentId) {
    auto it = std::find_if(students.begin(), students.end(),
        [&studentId](const Student& s) { return s.getStudentId() == studentId; });
    
    if (it != students.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<Student*> Database::findStudentsByName(const std::string& name) {
    std::vector<Student*> result;
    for (auto& student : students) {
        if (student.getName().find(name) != std::string::npos) {
            result.push_back(&student);
        }
    }
    return result;
}

std::vector<Student*> Database::findAllStudents() {
    std::vector<Student*> result;
    for (auto& student : students) {
        result.push_back(&student);
    }
    return result;
}

bool Database::updateStudent(int id, const Student& updated) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        it->setName(updated.getName());
        it->setStudentId(updated.getStudentId());
        it->setMajor(updated.getMajor());
        // GPA is calculated, not manually set
        saveStudentsToFile();
        return true;
    }
    return false;
}

bool Database::deleteStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        students.erase(it);
        // Also delete associated grades
        auto gradeIt = grades.begin();
        while (gradeIt != grades.end()) {
            if (gradeIt->getStudentId() == id) {
                gradeIt = grades.erase(gradeIt);
            } else {
                ++gradeIt;
            }
        }
        saveStudentsToFile();
        saveGradesToFile();
        return true;
    }
    return false;
}

int Database::getNextStudentId() const {
    return students.empty() ? 1 : students.back().getId() + 1;
}

int Database::getTotalStudents() const {
    return students.size();
}

bool Database::studentExists(int id) {
    return findStudentById(id) != nullptr;
}

// ===== USER CRUD =====

void Database::addUser(const User& user) {
    users.push_back(user);
    saveUsersToFile();
}

User* Database::findUserById(int id) {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const User& u) { return u.getId() == id; });
    
    if (it != users.end()) {
        return &(*it);
    }
    return nullptr;
}

User* Database::findUserByUsername(const std::string& username) {
    auto it = std::find_if(users.begin(), users.end(),
        [&username](const User& u) { return u.getUsername() == username; });
    
    if (it != users.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<User*> Database::findAllUsers() {
    std::vector<User*> result;
    for (auto& user : users) {
        result.push_back(&user);
    }
    return result;
}

bool Database::updateUser(int id, const User& updated) {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const User& u) { return u.getId() == id; });
    
    if (it != users.end()) {
        it->setUsername(updated.getUsername());
        it->setPassword(updated.getPassword());
        it->setRole(updated.getRole());
        it->setRelatedStudentId(updated.getRelatedStudentId());
        saveUsersToFile();
        return true;
    }
    return false;
}

bool Database::deleteUser(int id) {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const User& u) { return u.getId() == id; });
    
    if (it != users.end()) {
        users.erase(it);
        saveUsersToFile();
        return true;
    }
    return false;
}

bool Database::authenticateUser(const std::string& username, const std::string& password) {
    User* user = findUserByUsername(username);
    if (user && user->getPassword() == password) {
        return true;
    }
    return false;
}

int Database::getNextUserId() const {
    return users.empty() ? 1 : users.back().getId() + 1;
}

bool Database::userExists(const std::string& username) {
    return findUserByUsername(username) != nullptr;
}

// ===== COURSE CRUD =====

void Database::addCourse(const Course& course) {
    courses.push_back(course);
    saveCoursesToFile();
}

Course* Database::findCourseById(int id) {
    auto it = std::find_if(courses.begin(), courses.end(),
        [id](const Course& c) { return c.getId() == id; });
    
    if (it != courses.end()) {
        return &(*it);
    }
    return nullptr;
}

Course* Database::findCourseByName(const std::string& name) {
    auto it = std::find_if(courses.begin(), courses.end(),
        [&name](const Course& c) { return c.getName().find(name) != std::string::npos; });
    
    if (it != courses.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<Course*> Database::findAllCourses() {
    std::vector<Course*> result;
    for (auto& course : courses) {
        result.push_back(&course);
    }
    return result;
}

bool Database::updateCourse(int id, const Course& updated) {
    auto it = std::find_if(courses.begin(), courses.end(),
        [id](const Course& c) { return c.getId() == id; });
    
    if (it != courses.end()) {
        it->setName(updated.getName());
        it->setCredits(updated.getCredits());
        saveCoursesToFile();
        return true;
    }
    return false;
}

bool Database::deleteCourse(int id) {
    auto it = std::find_if(courses.begin(), courses.end(),
        [id](const Course& c) { return c.getId() == id; });
    
    if (it != courses.end()) {
        courses.erase(it);
        // Also delete associated grades
        auto gradeIt = grades.begin();
        while (gradeIt != grades.end()) {
            if (gradeIt->getCourseId() == id) {
                gradeIt = grades.erase(gradeIt);
            } else {
                ++gradeIt;
            }
        }
        saveCoursesToFile();
        saveGradesToFile();
        return true;
    }
    return false;
}

int Database::getNextCourseId() const {
    return courses.empty() ? 1 : courses.back().getId() + 1;
}

int Database::getTotalCourses() const {
    return courses.size();
}

// ===== GRADE CRUD & OPERATIONS =====

void Database::addGrade(const Grade& grade) {
    grades.push_back(grade);
    saveGradesToFile();
}

Grade* Database::findGradeById(int id) {
    auto it = std::find_if(grades.begin(), grades.end(),
        [id](const Grade& g) { return g.getId() == id; });
    
    if (it != grades.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<Grade*> Database::findGradesByStudentId(int studentId) {
    std::vector<Grade*> result;
    for (auto& grade : grades) {
        if (grade.getStudentId() == studentId) {
            result.push_back(&grade);
        }
    }
    return result;
}

std::vector<Grade*> Database::findGradesByStudentAndCourse(int studentId, int courseId) {
    std::vector<Grade*> result;
    for (auto& grade : grades) {
        if (grade.getStudentId() == studentId && grade.getCourseId() == courseId) {
            result.push_back(&grade);
        }
    }
    return result;
}

std::vector<Grade*> Database::findAllGrades() {
    std::vector<Grade*> result;
    for (auto& grade : grades) {
        result.push_back(&grade);
    }
    return result;
}

bool Database::updateGrade(int id, const Grade& updated) {
    auto it = std::find_if(grades.begin(), grades.end(),
        [id](const Grade& g) { return g.getId() == id; });
    
    if (it != grades.end()) {
        it->setScore(updated.getScore());
        saveGradesToFile();
        
        // Update student GPA
        Student* student = findStudentById(it->getStudentId());
        if (student) {
            float newGpa = calculateStudentGPAWithCredits(it->getStudentId());
            student->setGpa(newGpa);
            saveStudentsToFile();
        }
        
        return true;
    }
    return false;
}

bool Database::deleteGrade(int id) {
    auto it = std::find_if(grades.begin(), grades.end(),
        [id](const Grade& g) { return g.getId() == id; });
    
    if (it != grades.end()) {
        int studentId = it->getStudentId();
        grades.erase(it);
        saveGradesToFile();
        
        // Update student GPA
        Student* student = findStudentById(studentId);
        if (student) {
            float newGpa = calculateStudentGPAWithCredits(studentId);
            student->setGpa(newGpa);
            saveStudentsToFile();
        }
        
        return true;
    }
    return false;
}

int Database::getNextGradeId() const {
    return grades.empty() ? 1 : grades.back().getId() + 1;
}

/**
 * Calculate simple GPA (average of all scores)
 */
float Database::calculateStudentGPA(int studentId) {
    auto studentGrades = findGradesByStudentId(studentId);
    if (studentGrades.empty()) {
        return 0.0f;
    }
    
    float total = 0.0f;
    for (const auto grade : studentGrades) {
        // Convert 0-10 scale to 4.0 scale
        float gpa_value = grade->getScore() / 10.0f * 4.0f;
        total += gpa_value;
    }
    
    return total / studentGrades.size();
}

/**
 * Calculate weighted GPA with credit hours
 */
float Database::calculateStudentGPAWithCredits(int studentId) {
    auto studentGrades = findGradesByStudentId(studentId);
    if (studentGrades.empty()) {
        return 0.0f;
    }
    
    float totalWeightedScore = 0.0f;
    int totalCredits = 0;
    
    for (const auto grade : studentGrades) {
        Course* course = findCourseById(grade->getCourseId());
        if (course) {
            // Convert 0-10 score to 4.0 scale
            float gpa_value = grade->getScore() / 10.0f * 4.0f;
            int credits = course->getCredits();
            totalWeightedScore += gpa_value * credits;
            totalCredits += credits;
        }
    }
    
    if (totalCredits == 0) return 0.0f;
    return totalWeightedScore / totalCredits;
}

void Database::displayStudentGrades(int studentId) {
    Student* student = findStudentById(studentId);
    if (!student) {
        std::cout << "Student not found!\n";
        return;
    }
    
    auto studentGrades = findGradesByStudentId(studentId);
    
    std::cout << "\n=== Grade Report for: " << student->getName() << " ===\n";
    std::cout << "Student ID (MSSV): " << student->getStudentId() << "\n";
    std::cout << "Major: " << student->getMajor() << "\n\n";
    
    if (studentGrades.empty()) {
        std::cout << "No grades recorded yet.\n";
        return;
    }
    
    std::cout << "Courses and Grades:\n";
    std::cout << std::string(80, '-') << "\n";
    
    float totalScore = 0.0f;
    for (const auto grade : studentGrades) {
        Course* course = findCourseById(grade->getCourseId());
        if (course) {
            printf("%-40s Credits: %2d  |  Score: %5.2f\n", 
                   course->getName().c_str(), course->getCredits(), grade->getScore());
            totalScore += grade->getScore();
        }
    }
    
    std::cout << std::string(80, '-') << "\n";
    float avgScore = totalScore / studentGrades.size();
    float currentGpa = calculateStudentGPAWithCredits(studentId);
    
    printf("Average Score: %.2f  |  GPA (4.0 scale): %.2f\n", avgScore, currentGpa);
    std::cout << std::string(80, '-') << "\n";
}

// ===== FILE OPERATIONS =====

void Database::saveAllData() {
    saveStudentsToFile();
    saveUsersToFile();
    saveCoursesToFile();
    saveGradesToFile();
}

void Database::loadAllData() {
    loadStudentsFromFile();
    loadUsersFromFile();
    loadCoursesFromFile();
    loadGradesFromFile();
}

// Helper: Write string to file
void writeString(std::ofstream& file, const std::string& str) {
    int len = str.length();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(str.c_str(), len);
}

// Helper: Read string from file
std::string readString(std::ifstream& file) {
    int len;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    char buffer[256];
    file.read(buffer, len);
    return std::string(buffer, len);
}

// ===== STUDENT FILE I/O =====

void Database::saveStudentsToFile() {
    std::ofstream file(studentFile, std::ios::binary);
    if (!file) return;
    
    int size = students.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const auto& student : students) {
        int id = student.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        writeString(file, student.getName());
        writeString(file, student.getStudentId());
        writeString(file, student.getMajor());
        
        float gpa = student.getGpa();
        file.write(reinterpret_cast<const char*>(&gpa), sizeof(gpa));
    }
    
    file.close();
}

void Database::loadStudentsFromFile() {
    std::ifstream file(studentFile, std::ios::binary);
    if (!file) return;
    
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    students.clear();
    
    for (int i = 0; i < size; ++i) {
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        std::string name = readString(file);
        std::string studentId = readString(file);
        std::string major = readString(file);
        
        float gpa;
        file.read(reinterpret_cast<char*>(&gpa), sizeof(gpa));
        
        students.emplace_back(id, name, studentId, major, gpa);
    }
    
    file.close();
}

// ===== USER FILE I/O =====

void Database::saveUsersToFile() {
    std::ofstream file(userFile, std::ios::binary);
    if (!file) return;
    
    int size = users.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const auto& user : users) {
        int id = user.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        writeString(file, user.getUsername());
        writeString(file, user.getPassword());
        
        int role = static_cast<int>(user.getRole());
        file.write(reinterpret_cast<const char*>(&role), sizeof(role));
        
        int studentId = user.getRelatedStudentId();
        file.write(reinterpret_cast<const char*>(&studentId), sizeof(studentId));
    }
    
    file.close();
}

void Database::loadUsersFromFile() {
    std::ifstream file(userFile, std::ios::binary);
    if (!file) {
        // Create default admin account if no users exist
        if (users.empty()) {
            users.emplace_back(1, "admin", "admin123", UserRole::ADMIN, -1);
            saveUsersToFile();
        }
        return;
    }
    
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    users.clear();
    
    for (int i = 0; i < size; ++i) {
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        std::string username = readString(file);
        std::string password = readString(file);
        
        int roleInt;
        file.read(reinterpret_cast<char*>(&roleInt), sizeof(roleInt));
        UserRole role = static_cast<UserRole>(roleInt);
        
        int studentId;
        file.read(reinterpret_cast<char*>(&studentId), sizeof(studentId));
        
        users.emplace_back(id, username, password, role, studentId);
    }
    
    file.close();
}

// ===== COURSE FILE I/O =====

void Database::saveCoursesToFile() {
    std::ofstream file(courseFile, std::ios::binary);
    if (!file) return;
    
    int size = courses.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const auto& course : courses) {
        int id = course.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        writeString(file, course.getName());
        
        int credits = course.getCredits();
        file.write(reinterpret_cast<const char*>(&credits), sizeof(credits));
    }
    
    file.close();
}

void Database::loadCoursesFromFile() {
    std::ifstream file(courseFile, std::ios::binary);
    if (!file) return;
    
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    courses.clear();
    
    for (int i = 0; i < size; ++i) {
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        std::string name = readString(file);
        
        int credits;
        file.read(reinterpret_cast<char*>(&credits), sizeof(credits));
        
        courses.emplace_back(id, name, credits);
    }
    
    file.close();
}

// ===== GRADE FILE I/O =====

void Database::saveGradesToFile() {
    std::ofstream file(gradeFile, std::ios::binary);
    if (!file) return;
    
    int size = grades.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const auto& grade : grades) {
        int id = grade.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        int studentId = grade.getStudentId();
        file.write(reinterpret_cast<const char*>(&studentId), sizeof(studentId));
        
        int courseId = grade.getCourseId();
        file.write(reinterpret_cast<const char*>(&courseId), sizeof(courseId));
        
        float score = grade.getScore();
        file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }
    
    file.close();
}

void Database::loadGradesFromFile() {
    std::ifstream file(gradeFile, std::ios::binary);
    if (!file) return;
    
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    grades.clear();
    
    for (int i = 0; i < size; ++i) {
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        int studentId;
        file.read(reinterpret_cast<char*>(&studentId), sizeof(studentId));
        
        int courseId;
        file.read(reinterpret_cast<char*>(&courseId), sizeof(courseId));
        
        float score;
        file.read(reinterpret_cast<char*>(&score), sizeof(score));
        
        grades.emplace_back(id, studentId, courseId, score);
    }
    
    file.close();
}
