#include "app_controller.h"

/**
 * Main entry point
 */
int main() {
    try {
        AppController app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
