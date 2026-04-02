#include "ui_manager.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

/**
 * Clear screen (works on Windows and Linux)
 */
void UIManager::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * Display header
 */
void UIManager::displayHeader(const std::string& title) {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << std::setw(40 + title.length() / 2) << title << "\n";
    std::cout << std::string(70, '=') << "\n\n";
}

/**
 * Display footer
 */
void UIManager::displayFooter() {
    std::cout << "\n" << std::string(70, '=') << "\n";
}

/**
 * Display main menu
 */
void UIManager::displayMainMenu() {
    clearScreen();
    displayHeader("STUDENT MANAGEMENT SYSTEM");
    
    std::cout << "1. Add Student\n";
    std::cout << "2. View All Students\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Edit Student\n";
    std::cout << "5. Delete Student\n";
    std::cout << "6. Exit\n";
    std::cout << "\n";
}

/**
 * Display add student form
 */
void UIManager::displayAddStudentForm() {
    displayHeader("ADD NEW STUDENT");
}

/**
 * Display search menu
 */
void UIManager::displaySearchMenu() {
    displayHeader("SEARCH STUDENT");
    std::cout << "1. Search by ID\n";
    std::cout << "2. Search by Name\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "\n";
}

/**
 * Display edit menu
 */
void UIManager::displayEditMenu() {
    displayHeader("EDIT STUDENT");
}

/**
 * Display delete menu
 */
void UIManager::displayDeleteMenu() {
    displayHeader("DELETE STUDENT");
}

/**
 * Get menu choice from user
 */
int UIManager::getMenuChoice() {
    int choice;
    std::cout << "Please choose an option: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

/**
 * Get student input from user
 */
Student UIManager::getStudentInput() {
    std::string name, major;
    float gpa;

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Student Major: ";
    std::getline(std::cin, major);

    std::cout << "Enter Student GPA (0.0 - 4.0): ";
    std::cin >> gpa;
    std::cin.ignore();

    Student student(0, name, major, gpa);
    return student;
}

/**
 * Get student ID from user
 */
int UIManager::getStudentId() {
    int id;
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    std::cin.ignore();
    return id;
}

/**
 * Get search type (1=ID, 2=Name)
 */
int UIManager::getSearchType() {
    int type;
    std::cout << "Choose search type: ";
    std::cin >> type;
    std::cin.ignore();
    return type;
}

/**
 * Get student name from user
 */
std::string UIManager::getStudentName() {
    std::string name;
    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);
    return name;
}

/**
 * Display all students in table format
 */
void UIManager::displayAllStudents(const std::vector<Student*>& students) {
    displayHeader("ALL STUDENTS");

    if (students.empty()) {
        std::cout << "No students found.\n";
        displayFooter();
        return;
    }

    std::cout << std::left << std::setw(8) << "ID" 
              << std::setw(25) << "Name" 
              << std::setw(20) << "Major" 
              << std::setw(10) << "GPA\n";
    std::cout << std::string(63, '-') << "\n";

    for (const auto& student : students) {
        student->display();
    }

    displayFooter();
}

/**
 * Display single student
 */
void UIManager::displayStudent(const Student* student) {
    if (!student) {
        displayError("Student not found!");
        return;
    }

    displayHeader("STUDENT DETAILS");
    std::cout << "ID:    " << student->getId() << "\n";
    std::cout << "Name:  " << student->getName() << "\n";
    std::cout << "Major: " << student->getMajor() << "\n";
    std::cout << "GPA:   " << std::fixed << std::setprecision(2) << student->getGpa() << "\n";
    displayFooter();
}

/**
 * Display success message
 */
void UIManager::displayMessage(const std::string& message, bool isSuccess) {
    std::cout << "\n";
    if (isSuccess) {
        std::cout << "✓ " << message << "\n";
    } else {
        std::cout << "✗ " << message << "\n";
    }
}

/**
 * Display error message
 */
void UIManager::displayError(const std::string& message) {
    displayMessage(message, false);
}
