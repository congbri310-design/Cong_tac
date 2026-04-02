#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "student.h"
#include <vector>

/**
 * @class UIManager
 * @brief Handles all user interface operations
 */
class UIManager {
public:
    // Menu display
    static void displayMainMenu();
    static void displayAddStudentForm();
    static void displaySearchMenu();
    static void displayEditMenu();
    static void displayDeleteMenu();

    // Input operations
    static int getMenuChoice();
    static Student getStudentInput();
    static int getStudentId();
    static int getSearchType();
    static std::string getStudentName();

    // Output operations
    static void displayAllStudents(const std::vector<Student*>& students);
    static void displayStudent(const Student* student);
    static void displayMessage(const std::string& message, bool isSuccess = true);
    static void displayError(const std::string& message);
    static void clearScreen();
    static void displayHeader(const std::string& title);
    static void displayFooter();
};

#endif // UI_MANAGER_H
