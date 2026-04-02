#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include "database.h"
#include "ui_manager.h"

/**
 * @class AppController
 * @brief Main application controller - handles business logic and flow
 */
class AppController {
private:
    Database db;
    bool running;

    // Action handlers
    void handleAddStudent();
    void handleViewAllStudents();
    void handleSearchStudent();
    void handleEditStudent();
    void handleDeleteStudent();

public:
    AppController();
    void run();
    void stop();
};

#endif // APP_CONTROLLER_H
