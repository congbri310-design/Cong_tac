#include "ui_manager.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

// ===== SCREEN CONTROL =====

void UIManager::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void UIManager::displayHeader(const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    int padding = (80 - title.length()) / 2;
    std::cout << std::string(padding, ' ') << title << "\n";
    std::cout << std::string(80, '=') << "\n\n";
}

void UIManager::displayFooter() {
    std::cout << "\n" << std::string(80, '=') << "\n";
}

void UIManager::displayPause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
}

// ===== AUTHENTICATION UI =====

void UIManager::displayWelcome() {
    clearScreen();
    displayHeader("STUDENT MANAGEMENT SYSTEM");
    std::cout << "Welcome to the Student Academic Management System\n";
    std::cout << "Designed for tracking student information and grades\n";
    std::cout << "\nDefault Admin Account:\n";
    std::cout << "  Username: admin\n";
    std::cout << "  Password: admin123\n";
    displayFooter();
    std::cout << "\nPress Enter to login...";
    std::cin.ignore();
}

void UIManager::displayLoginForm() {
    displayHeader("LOGIN");
    std::cout << "Please enter your credentials\n\n";
}

bool UIManager::getLoginCredentials(std::string& username, std::string& password) {
    std::cout << "Username: ";
    std::getline(std::cin, username);
    
    std::cout << "Password: ";
    std::getline(std::cin, password);
    
    return !username.empty() && !password.empty();
}

void UIManager::displayLoginSuccess(const User* user) {
    clearScreen();
    displayHeader("LOGIN SUCCESSFUL");
    std::cout << "Welcome, " << user->getUsername() << " (" << user->getRoleString() << ")!\n";
    displayFooter();
}

void UIManager::displayLoginFailed() {
    clearScreen();
    displayError("Invalid username or password. Please try again.");
}

// ===== ADMIN MENU =====

void UIManager::displayAdminMenu() {
    displayHeader("ADMIN MENU");
    std::cout << "=== STUDENT MANAGEMENT ===\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. View All Students\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Edit Student\n";
    std::cout << "5. Delete Student\n";
    
    std::cout << "\n=== COURSE MANAGEMENT ===\n";
    std::cout << "6. Manage Courses\n";
    
    std::cout << "\n=== GRADE MANAGEMENT ===\n";
    std::cout << "7. Input Grades\n";
    std::cout << "8. View All Grades\n";
    
    std::cout << "\n=== EXIT ===\n";
    std::cout << "9. Logout\n\n";
}

void UIManager::displayStudentManagementMenu() {
    displayHeader("STUDENT MANAGEMENT");
    std::cout << "1. Add Student\n";
    std::cout << "2. View All Students\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Edit Student\n";
    std::cout << "5. Delete Student\n";
    std::cout << "0. Back to Main Menu\n\n";
}

void UIManager::displayGradeManagementMenu() {
    displayHeader("GRADE MANAGEMENT");
    std::cout << "1. Input New Grade\n";
    std::cout << "2. View All Grades\n";
    std::cout << "3. Edit Grade\n";
    std::cout << "4. Delete Grade\n";
    std::cout << "0. Back to Main Menu\n\n";
}

void UIManager::displayCourseManagementMenu() {
    displayHeader("COURSE MANAGEMENT");
    std::cout << "1. Add Course\n";
    std::cout << "2. View All Courses\n";
    std::cout << "3. Delete Course\n";
    std::cout << "0. Back to Main Menu\n\n";
}

// ===== STUDENT MENU =====

void UIManager::displayStudentMenu() {
    displayHeader("STUDENT MENU");
    std::cout << "1. View Personal Information\n";
    std::cout << "2. View My Grades\n";
    std::cout << "3. Logout\n\n";
}

// ===== STUDENT OPERATIONS UI =====

void UIManager::displayAddStudentForm() {
    displayHeader("ADD NEW STUDENT");
}

void UIManager::displayEditForm() {
    displayHeader("EDIT STUDENT");
}

void UIManager::displayDeleteConfirmation() {
    displayHeader("DELETE CONFIRMATION");
}

Student UIManager::getStudentInput() {
    std::string name, studentId, major;
    
    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Student ID Code (MSSV): ";
    std::getline(std::cin, studentId);
    
    std::cout << "Enter Student Major: ";
    std::getline(std::cin, major);
    
    Student student(0, name, studentId, major, 0.0f);
    return student;
}

Student UIManager::getStudentEditInput(const Student& original) {
    std::string name, studentId, major;
    
    std::cout << "\nCurrent Name: " << original.getName() << "\n";
    std::cout << "New Name (press Enter to keep current): ";
    std::getline(std::cin, name);
    if (name.empty()) name = original.getName();
    
    std::cout << "\nCurrent Student ID: " << original.getStudentId() << "\n";
    std::cout << "New Student ID (press Enter to keep current): ";
    std::getline(std::cin, studentId);
    if (studentId.empty()) studentId = original.getStudentId();
    
    std::cout << "\nCurrent Major: " << original.getMajor() << "\n";
    std::cout << "New Major (press Enter to keep current): ";
    std::getline(std::cin, major);
    if (major.empty()) major = original.getMajor();
    
    Student student(original.getId(), name, studentId, major, original.getGpa());
    return student;
}

int UIManager::getStudentId() {
    return getNumericInput("Enter Student ID: ");
}

std::string UIManager::getStudentIdCode() {
    return getStringInput("Enter Student ID Code (MSSV): ");
}

std::string UIManager::getStudentName() {
    return getStringInput("Enter Student Name: ");
}

void UIManager::displayAllStudents(const std::vector<Student*>& students) {
    displayHeader("LIST OF ALL STUDENTS");
    
    if (students.empty()) {
        std::cout << "No students found.\n";
        displayFooter();
        return;
    }
    
    std::cout << std::left 
              << std::setw(6) << "ID" 
              << std::setw(15) << "MSSV"
              << std::setw(25) << "Name" 
              << std::setw(20) << "Major" 
              << std::setw(8) << "GPA\n";
    std::cout << std::string(80, '-') << "\n";
    
    for (const auto& student : students) {
        std::cout << std::left 
                  << std::setw(6) << student->getId()
                  << std::setw(15) << student->getStudentId()
                  << std::setw(25) << student->getName()
                  << std::setw(20) << student->getMajor()
                  << std::fixed << std::setprecision(2) << student->getGpa() << "\n";
    }
    
    displayFooter();
}

void UIManager::displayStudent(const Student* student) {
    if (!student) {
        clearScreen();
        displayError("Student not found!");
        return;
    }
    
    clearScreen();
    displayHeader("STUDENT DETAILS");
    std::cout << "ID:         " << student->getId() << "\n";
    std::cout << "MSSV:       " << student->getStudentId() << "\n";
    std::cout << "Name:       " << student->getName() << "\n";
    std::cout << "Major:      " << student->getMajor() << "\n";
    std::cout << "GPA:        " << std::fixed << std::setprecision(2) << student->getGpa() << "\n";
    displayFooter();
}

bool UIManager::confirmDelete(const std::string& name) {
    std::string confirm;
    std::cout << "\nAre you sure you want to delete '" << name << "'? (yes/no): ";
    std::getline(std::cin, confirm);
    return (confirm == "yes" || confirm == "YES" || confirm == "y" || confirm == "Y");
}

// ===== COURSE OPERATIONS UI =====

void UIManager::displayCourseList(const std::vector<Course*>& courses) {
    clearScreen();
    displayHeader("LIST OF COURSES");
    
    std::cout << std::left 
              << std::setw(6) << "ID" 
              << std::setw(45) << "Course Name" 
              << std::setw(10) << "Credits\n";
    std::cout << std::string(60, '-') << "\n";
    
    for (const auto& course : courses) {
        std::cout << std::left 
                  << std::setw(6) << course->getId()
                  << std::setw(45) << course->getName()
                  << std::setw(10) << course->getCredits() << "\n";
    }
    
    displayFooter();
}

void UIManager::displayCourse(const Course* course) {
    if (!course) {
        displayError("Course not found!");
        return;
    }
    
    clearScreen();
    displayHeader("COURSE DETAILS");
    std::cout << "ID:      " << course->getId() << "\n";
    std::cout << "Name:    " << course->getName() << "\n";
    std::cout << "Credits: " << course->getCredits() << "\n";
    displayFooter();
}

Course UIManager::getCourseInput() {
    std::string name;
    int credits;
    
    std::cout << "Enter Course Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Credit Hours: ";
    std::cin >> credits;
    std::cin.ignore();
    
    return Course(0, name, credits);
}

Course UIManager::getCourseEditInput(const Course& original) {
    std::string name;
    int credits;
    
    std::cout << "\nCurrent Name: " << original.getName() << "\n";
    std::cout << "New Name (press Enter to keep): ";
    std::getline(std::cin, name);
    if (name.empty()) name = original.getName();
    
    std::cout << "\nCurrent Credits: " << original.getCredits() << "\n";
    std::cout << "New Credits (enter 0 to keep): ";
    std::cin >> credits;
    std::cin.ignore();
    if (credits == 0) credits = original.getCredits();
    
    return Course(original.getId(), name, credits);
}

int UIManager::getCourseIdForGrade(const std::vector<Course*>& courses) {
    displayHeader("SELECT COURSE");
    
    std::cout << std::left 
              << std::setw(6) << "ID" 
              << std::setw(45) << "Course Name" 
              << std::setw(10) << "Credits\n";
    std::cout << std::string(60, '-') << "\n";
    
    for (const auto& course : courses) {
        std::cout << std::left 
                  << std::setw(6) << course->getId()
                  << std::setw(45) << course->getName()
                  << std::setw(10) << course->getCredits() << "\n";
    }
    
    return getNumericInput("\nEnter Course ID: ");
}

std::string UIManager::getCourseName() {
    return getStringInput("Enter Course Name: ");
}

// ===== GRADE OPERATIONS UI =====

void UIManager::displayGradeList(const std::vector<Grade*>& grades,
                                 const std::vector<Course*>& courses,
                                 const std::vector<Student*>& students) {
    clearScreen();
    displayHeader("ALL GRADES");
    
    std::cout << std::left 
              << std::setw(15) << "Student"
              << std::setw(40) << "Course"
              << std::setw(10) << "Score\n";
    std::cout << std::string(65, '-') << "\n";
    
    for (const auto& grade : grades) {
        Student* student = nullptr;
        Course* course = nullptr;
        
        for (auto st : students) {
            if (st->getId() == grade->getStudentId()) {
                student = st;
                break;
            }
        }
        
        for (auto co : courses) {
            if (co->getId() == grade->getCourseId()) {
                course = co;
                break;
            }
        }
        
        if (student && course) {
            std::cout << std::left 
                      << std::setw(15) << student->getName()
                      << std::setw(40) << course->getName()
                      << std::fixed << std::setprecision(2) << grade->getScore() << "\n";
        }
    }
    
    displayFooter();
}

void UIManager::displayStudentGradeTable(const Student* student,
                                        const std::vector<Grade*>& grades,
                                        const std::vector<Course*>& courses) {
    clearScreen();
    displayHeader("STUDENT GRADES: " + student->getName());
    
    std::cout << "Student ID: " << student->getId() << "\n";
    std::cout << "MSSV: " << student->getStudentId() << "\n";
    std::cout << "Major: " << student->getMajor() << "\n\n";
    
    std::cout << std::left 
              << std::setw(45) << "Course"
              << std::setw(10) << "Credits"
              << std::setw(10) << "Score\n";
    std::cout << std::string(65, '-') << "\n";
    
    for (const auto& grade : grades) {
        if (grade->getStudentId() == student->getId()) {
            for (auto course : courses) {
                if (course->getId() == grade->getCourseId()) {
                    std::cout << std::left 
                              << std::setw(45) << course->getName()
                              << std::setw(10) << course->getCredits()
                              << std::fixed << std::setprecision(2) << grade->getScore() << "\n";
                    break;
                }
            }
        }
    }
    
    displayFooter();
}

Grade UIManager::getGradeInput() {
    int studentId, courseId;
    float score;
    
    std::cout << "Enter Student ID: ";
    std::cin >> studentId;
    
    std::cout << "Enter Course ID: ";
    std::cin >> courseId;
    
    score = getScoreInput();
    std::cin.ignore();
    
    return Grade(0, studentId, courseId, score);
}

float UIManager::getScoreInput() {
    float score;
    std::cout << "Enter Score (0.0 - 10.0): ";
    std::cin >> score;
    std::cin.ignore();
    return score;
}

// ===== SEARCH & FILTER UI =====

void UIManager::displaySearchMenu() {
    displayHeader("SEARCH STUDENT");
    std::cout << "1. Search by Student ID (MSSV)\n";
    std::cout << "2. Search by Name\n";
    std::cout << "0. Back to Main Menu\n\n";
}

int UIManager::getSearchType() {
    return getMenuChoice();
}

// ===== INPUT UTILITIES =====

int UIManager::getMenuChoice() {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

int UIManager::getNumericInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore();
    return value;
}

std::string UIManager::getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

// ===== OUTPUT MESSAGES =====

void UIManager::displayMessage(const std::string& message, bool isSuccess) {
    std::cout << "\n";
    if (isSuccess) {
        std::cout << "✓ " << message << "\n";
    } else {
        std::cout << "✗ " << message << "\n";
    }
}

void UIManager::displayError(const std::string& message) {
    clearScreen();
    displayHeader("ERROR");
    std::cout << message << "\n";
    displayFooter();
}

void UIManager::displayWarning(const std::string& message) {
    clearScreen();
    displayHeader("WARNING");
    std::cout << message << "\n";
    displayFooter();
}

void UIManager::displaySuccess(const std::string& message) {
    clearScreen();
    displayHeader("SUCCESS");
    std::cout << message << "\n";
    displayFooter();
}
