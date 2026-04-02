#include "app_controller.h"
#include <iostream>

/**
 * Constructor
 */
AppController::AppController() : running(true) {}

/**
 * Run the application
 */
void AppController::run() {
    while (running) {
        UIManager::displayMainMenu();
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
                stop();
                break;
            default:
                UIManager::displayError("Invalid choice. Please try again.");
                std::cin.ignore();
                system("pause");
                break;
        }
    }

    // Display exit message
    UIManager::clearScreen();
    UIManager::displayHeader("THANK YOU!");
    std::cout << "Student Management System closed successfully.\n";
    std::cout << "Data has been saved.\n";
    UIManager::displayFooter();
}

/**
 * Stop the application
 */
void AppController::stop() {
    running = false;
}

/**
 * Handle adding a new student
 */
void AppController::handleAddStudent() {
    UIManager::displayAddStudentForm();
    Student newStudent = UIManager::getStudentInput();
    newStudent.setId(db.getNextId());
    
    db.addStudent(newStudent);
    UIManager::displayMessage("Student added successfully! ID: " + std::to_string(newStudent.getId()));
    std::cin.ignore();
    system("pause");
}

/**
 * Handle viewing all students
 */
void AppController::handleViewAllStudents() {
    auto students = db.findAllStudents();
    UIManager::displayAllStudents(students);
    std::cin.ignore();
    system("pause");
}

/**
 * Handle searching for a student
 */
void AppController::handleSearchStudent() {
    UIManager::displaySearchMenu();
    int searchType = UIManager::getSearchType();

    if (searchType == 1) {
        // Search by ID
        int id = UIManager::getStudentId();
        Student* student = db.findStudentById(id);
        UIManager::displayStudent(student);
    } else if (searchType == 2) {
        // Search by Name
        std::string name = UIManager::getStudentName();
        Student* student = db.findStudentByName(name);
        UIManager::displayStudent(student);
    } else {
        UIManager::displayError("Invalid search type.");
    }

    std::cin.ignore();
    system("pause");
}

/**
 * Handle editing a student
 */
void AppController::handleEditStudent() {
    UIManager::displayEditMenu();
    int id = UIManager::getStudentId();

    Student* student = db.findStudentById(id);
    if (!student) {
        UIManager::displayError("Student not found.");
        std::cin.ignore();
        system("pause");
        return;
    }

    std::cout << "\nCurrent Information:\n";
    std::cout << "Name:  " << student->getName() << "\n";
    std::cout << "Major: " << student->getMajor() << "\n";
    std::cout << "GPA:   " << student->getGpa() << "\n\n";

    Student updated = UIManager::getStudentInput();
    updated.setId(id);

    if (db.updateStudent(id, updated)) {
        UIManager::displayMessage("Student information updated successfully!");
    } else {
        UIManager::displayError("Failed to update student.");
    }

    std::cin.ignore();
    system("pause");
}

/**
 * Handle deleting a student
 */
void AppController::handleDeleteStudent() {
    UIManager::displayDeleteMenu();
    int id = UIManager::getStudentId();

    Student* student = db.findStudentById(id);
    if (!student) {
        UIManager::displayError("Student not found.");
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
