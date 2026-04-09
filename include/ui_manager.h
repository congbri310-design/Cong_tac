#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "student.h"
#include "user.h"
#include "course.h"
#include "grade.h"
#include <vector>

/**
 * @class UIManager
 * @brief Handles all user interface operations
 */
class UIManager {
public:
    // ===== SCREEN CONTROL =====
    static void clearScreen();
    static void displayHeader(const std::string& title);
    static void displayFooter();
    static void displayPause();

    // ===== AUTHENTICATION UI =====
    static void displayWelcome();
    static void displayLoginForm();
    static bool getLoginCredentials(std::string& username, std::string& password);
    static void displayLoginSuccess(const User* user);
    static void displayLoginFailed();

    // ===== ADMIN MENU =====
    static void displayAdminMenu();
    static void displayStudentManagementMenu();
    static void displayGradeManagementMenu();
    static void displayCourseManagementMenu();

    // ===== STUDENT MENU =====
    static void displayStudentMenu();

    // ===== STUDENT OPERATIONS UI =====
    static void displayAddStudentForm();
    static void displayEditForm();
    static void displayDeleteConfirmation();
    static Student getStudentInput();
    static Student getStudentEditInput(const Student& original);
    static int getStudentId();
    static std::string getStudentIdCode();  // Get MSSV
    static std::string getStudentName();
    static void displayAllStudents(const std::vector<Student*>& students);
    static void displayStudent(const Student* student);
    static bool confirmDelete(const std::string& name);

    // ===== COURSE OPERATIONS UI =====
    static void displayCourseList(const std::vector<Course*>& courses);
    static void displayCourse(const Course* course);
    static Course getCourseInput();
    static Course getCourseEditInput(const Course& original);
    static int getCourseIdForGrade(const std::vector<Course*>& courses);
    static std::string getCourseName();

    // ===== GRADE OPERATIONS UI =====
    static void displayGradeList(const std::vector<Grade*>& grades, 
                                  const std::vector<Course*>& courses, 
                                  const std::vector<Student*>& students);
    static void displayStudentGradeTable(const Student* student, 
                                         const std::vector<Grade*>& grades,
                                         const std::vector<Course*>& courses);
    static Grade getGradeInput();
    static float getScoreInput();

    // ===== SEARCH & FILTER UI =====
    static void displaySearchMenu();
    static int getSearchType();

    // ===== INPUT UTILITIES =====
    static int getMenuChoice();
    static int getNumericInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);

    // ===== OUTPUT MESSAGES =====
    static void displayMessage(const std::string& message, bool isSuccess = true);
    static void displayError(const std::string& message);
    static void displayWarning(const std::string& message);
    static void displaySuccess(const std::string& message);
};

#endif // UI_MANAGER_H
