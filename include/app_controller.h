#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include "database.h"
#include "ui_manager.h"
#include "user.h"

/**
 * @class AppController
 * @brief Main application controller - handles business logic and flow
 */
class AppController {
private:
    Database db;
    bool running;
    User* currentUser;  // Currently logged-in user

    // ===== AUTHENTICATION =====
    bool login();
    void logout();
    void handleAdminMenu();
    void handleStudentMenu();

    // ===== ADMIN OPERATIONS =====
    void handleAddStudent();
    void handleViewAllStudents();
    void handleSearchStudent();
    void handleEditStudent();
    void handleDeleteStudent();
    void handleManageCourses();
    void handleInputGrades();
    void handleViewAllGrades();
    void handleAddCourse();
    void handleDeleteCourse();

    // ===== STUDENT OPERATIONS =====
    void handleViewPersonalInfo();
    void handleViewPersonalGrades();

public:
    AppController();
    ~AppController();
    void run();
    void stop();
    User* getCurrentUser() const;
};

#endif // APP_CONTROLLER_H
