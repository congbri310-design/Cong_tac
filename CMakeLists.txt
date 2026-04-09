cmake_minimum_required(VERSION 3.10)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/backend/student.cpp
    src/backend/user.cpp
    src/backend/course.cpp
    src/backend/grade.cpp
    src/backend/database.cpp
    src/frontend/ui_manager.cpp
    src/frontend/app_controller.cpp
)

# Create executable
add_executable(StudentManagement ${SOURCES})

# For Windows
if(MSVC)
    target_compile_options(StudentManagement PRIVATE /W4)
else()
    target_compile_options(StudentManagement PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Set output directory
set_target_properties(StudentManagement PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
