#include "app_controller.h"
#include <iostream>

/**
 * Constructor
 */
AppController::AppController() : running(true), currentUser(nullptr) {}

/**
 * Destructor
 */
AppController::~AppController() {
    if (currentUser) {
        currentUser = nullptr;
    }
}

/**
 * Run the application
 */
void AppController::run() {
    UIManager::displayWelcome();
    
    if (!login()) {
        UIManager::clearScreen();
        UIManager::displayError("Login failed! Application will close.");
        std::cin.ignore();
        system("pause");
        return;
    }
    
    while (running) {
        if (currentUser->isAdmin()) {
            handleAdminMenu();
        } else if (currentUser->isStudent()) {
            handleStudentMenu();
        }
    }
    
    // Display exit message
    UIManager::clearScreen();
    UIManager::displayHeader("THANK YOU!");
    std::cout << "Data has been saved. Goodbye " << currentUser->getUsername() << "!\n";
    UIManager::displayFooter();
}

/**
 * Stop the application
 */
void AppController::stop() {
    running = false;
}

/**
 * Get current user
 */
User* AppController::getCurrentUser() const {
    return currentUser;
}

// ===== AUTHENTICATION =====

bool AppController::login() {
    UIManager::clearScreen();
    UIManager::displayLoginForm();
    
    std::string username, password;
    if (!UIManager::getLoginCredentials(username, password)) {
        return false;
    }
    
    if (!db.authenticateUser(username, password)) {
        UIManager::displayLoginFailed();
        std::cin.ignore();
        system("pause");
        return false;
    }
    
    currentUser = db.findUserByUsername(username);
    if (currentUser) {
        UIManager::displayLoginSuccess(currentUser);
        std::cin.ignore();
        system("pause");
        return true;
    }
    
    return false;
}

void AppController::logout() {
    currentUser = nullptr;
    running = false;
}

// ===== ADMIN MENU =====

void AppController::handleAdminMenu() {
    UIManager::clearScreen();
    UIManager::displayAdminMenu();
    
    int choice = UIManager::getMenuChoice();
    
    switch (choice) {
        case 1:
            handleAddStudent();
            break;
        case 2:
            handleViewAllStudents();
            break;
        case 3:
            handleSearchStudent();
            break;
        case 4:
            handleEditStudent();
            break;
        case 5:
            handleDeleteStudent();
            break;
        case 6:
            handleManageCourses();
            break;
        case 7:
            handleInputGrades();
            break;
        case 8:
            handleViewAllGrades();
            break;
        case 9:
            logout();
            break;
        default:
            UIManager::displayError("Invalid choice. Please try again.");
            std::cin.ignore();
            system("pause");
            break;
    }
}

// ===== STUDENT MENU =====

void AppController::handleStudentMenu() {
    UIManager::clearScreen();
    UIManager::displayStudentMenu();
    
    int choice = UIManager::getMenuChoice();
    
    switch (choice) {
        case 1:
            handleViewPersonalInfo();
            break;
        case 2:
            handleViewPersonalGrades();
            break;
        case 3:
            logout();
            break;
        default:
            UIManager::displayError("Invalid choice. Please try again.");
            std::cin.ignore();
            system("pause");
            break;
    }
}

// ===== ADMIN OPERATIONS =====

void AppController::handleAddStudent() {
    UIManager::clearScreen();
    UIManager::displayAddStudentForm();
    Student newStudent = UIManager::getStudentInput();
    newStudent.setId(db.getNextStudentId());
    
    db.addStudent(newStudent);
    UIManager::displaySuccess("Student added successfully! ID: " + std::to_string(newStudent.getId()));
    std::cin.ignore();
    system("pause");
}

void AppController::handleViewAllStudents() {
    UIManager::clearScreen();
    auto students = db.findAllStudents();
    
    if (students.empty()) {
        UIManager::displayMessage("No students found.", true);
    } else {
        UIManager::displayAllStudents(students);
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleSearchStudent() {
    UIManager::clearScreen();
    UIManager::displaySearchMenu();
    int searchType = UIManager::getSearchType();
    
    Student* student = nullptr;
    
    if (searchType == 1) {
        // Search by Student ID (MSSV)
        std::string studentId = UIManager::getStudentIdCode();
        student = db.findStudentByStudentId(studentId);
    } else if (searchType == 2) {
        // Search by Name
        std::string name = UIManager::getStudentName();
        student = db.findStudentByStudentId(name);
        if (!student) {
            auto results = db.findStudentsByName(name);
            if (!results.empty()) {
                student = results[0];
            }
        }
    } else {
        UIManager::displayError("Invalid search type.");
        std::cin.ignore();
        system("pause");
        return;
    }
    
    UIManager::displayStudent(student);
    std::cin.ignore();
    system("pause");
}

void AppController::handleEditStudent() {
    UIManager::clearScreen();
    int id = UIManager::getStudentId();
    
    Student* student = db.findStudentById(id);
    if (!student) {
        UIManager::displayError("Student not found.");
        std::cin.ignore();
        system("pause");
        return;
    }
    
    std::cout << "\nCurrent Information:\n";
    student->display();
    
    Student updated = UIManager::getStudentEditInput(*student);
    updated.setId(id);
    
    if (db.updateStudent(id, updated)) {
        UIManager::displaySuccess("Student information updated successfully!");
    } else {
        UIManager::displayError("Failed to update student.");
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleDeleteStudent() {
    UIManager::clearScreen();
    int id = UIManager::getStudentId();
    
    Student* student = db.findStudentById(id);
    if (!student) {
        UIManager::displayError("Student not found.");
        std::cin.ignore();
        system("pause");
        return;
    }
    
    if (UIManager::confirmDelete(student->getName())) {
        if (db.deleteStudent(id)) {
            UIManager::displaySuccess("Student deleted successfully!");
        } else {
            UIManager::displayError("Failed to delete student.");
        }
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleManageCourses() {
    UIManager::clearScreen();
    UIManager::displayCourseManagementMenu();
    
    int choice = UIManager::getMenuChoice();
    
    switch (choice) {
        case 1:
            handleAddCourse();
            break;
        case 2: {
            auto courses = db.findAllCourses();
            if (!courses.empty()) {
                UIManager::displayCourseList(courses);
            } else {
                UIManager::displayMessage("No courses found.", true);
            }
            std::cin.ignore();
            system("pause");
            break;
        }
        case 3:
            handleDeleteCourse();
            break;
        default:
            UIManager::displayError("Invalid choice.");
            break;
    }
}

void AppController::handleAddCourse() {
    UIManager::clearScreen();
    UIManager::displayHeader("ADD NEW COURSE");
    
    Course newCourse = UIManager::getCourseInput();
    newCourse.setId(db.getNextCourseId());
    
    db.addCourse(newCourse);
    UIManager::displaySuccess("Course added successfully!");
    std::cin.ignore();
    system("pause");
}

void AppController::handleDeleteCourse() {
    UIManager::clearScreen();
    UIManager::displayHeader("DELETE COURSE");
    
    int id = UIManager::getNumericInput("Enter Course ID: ");
    Course* course = db.findCourseById(id);
    
    if (!course) {
        UIManager::displayError("Course not found.");
    } else if (UIManager::confirmDelete(course->getName())) {
        if (db.deleteCourse(id)) {
            UIManager::displaySuccess("Course deleted successfully!");
        } else {
            UIManager::displayError("Failed to delete course.");
        }
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleInputGrades() {
    UIManager::clearScreen();
    UIManager::displayGradeManagementMenu();
    
   int choice = UIManager::getMenuChoice();
    
    if (choice == 1) {
        // Input new grade
        int studentId = UIManager::getStudentId();
        Student* student = db.findStudentById(studentId);
        if (!student) {
            UIManager::displayError("Student not found.");
            std::cin.ignore();
            system("pause");
            return;
        }
        
        auto courses = db.findAllCourses();
        if (courses.empty()) {
            UIManager::displayError("No courses available. Please add courses first.");
            std::cin.ignore();
            system("pause");
            return;
        }
        
        int courseId = UIManager::getCourseIdForGrade(courses);
        float score = UIManager::getScoreInput();
        
        Grade newGrade(db.getNextGradeId(), studentId, courseId, score);
        db.addGrade(newGrade);
        
        // Update student GPA
        float newGpa = db.calculateStudentGPAWithCredits(studentId);
        student->setGpa(newGpa);
        
        UIManager::displaySuccess("Grade added successfully!");
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleViewAllGrades() {
    UIManager::clearScreen();
    UIManager::displayHeader("ALL GRADES");
    
    auto grades = db.findAllGrades();
    auto students = db.findAllStudents();
    auto courses = db.findAllCourses();
    
    if (grades.empty()) {
        UIManager::displayMessage("No grades recorded yet.", true);
    } else {
        UIManager::displayGradeList(grades, courses, students);
    }
    
    std::cin.ignore();
    system("pause");
}

// ===== STUDENT OPERATIONS =====

void AppController::handleViewPersonalInfo() {
    UIManager::clearScreen();
    UIManager::displayHeader("PERSONAL INFORMATION");
    
    if (currentUser->getRelatedStudentId() != -1) {
        Student* student = db.findStudentById(currentUser->getRelatedStudentId());
        if (student) {
            UIManager::displayStudent(student);
        } else {
            UIManager::displayError("Student information not found.");
        }
    } else {
        UIManager::displayError("You are not linked to a student account.");
    }
    
    std::cin.ignore();
    system("pause");
}

void AppController::handleViewPersonalGrades() {
    UIManager::clearScreen();
    UIManager::displayHeader("MY GRADES");
    
    if (currentUser->getRelatedStudentId() != -1) {
        db.displayStudentGrades(currentUser->getRelatedStudentId());
    } else {
        UIManager::displayError("You are not linked to a student account.");
    }
    
    std::cin.ignore();
    system("pause");
}
        std::cin.ignore();
        system("pause");
        return;
    }

    std::cout << "\nDeleting student: " << student->getName() << "\n";
    std::cout << "Are you sure? (y/n): ";
    char confirm;
    std::cin >> confirm;
    std::cin.ignore();

    if (confirm == 'y' || confirm == 'Y') {
        if (db.deleteStudent(id)) {
            UIManager::displayMessage("Student deleted successfully!");
        } else {
            UIManager::displayError("Failed to delete student.");
        }
    } else {
        UIManager::displayMessage("Deletion cancelled.", false);
    }

    system("pause");
}
