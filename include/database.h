#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"
#include <vector>
#include <string>

/**
 * @class Database
 * @brief Manages student data persistence and operations
 */
class Database {
private:
    std::vector<Student> students;
    std::string filename;

public:
    // Constructor
    Database(const std::string& filename = "students.dat");

    // CRUD Operations
    void addStudent(const Student& student);
    Student* findStudentById(int id);
    Student* findStudentByName(const std::string& name);
    std::vector<Student*> findAllStudents();
    bool updateStudent(int id, const Student& updated);
    bool deleteStudent(int id);

    // File operations
    void saveToFile();
    void loadFromFile();

    // Query operations
    int getNextId() const;
    int getTotalStudents() const;
    bool studentExists(int id);
};

#endif // DATABASE_H
