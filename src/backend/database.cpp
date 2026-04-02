#include "database.h"
#include <fstream>
#include <algorithm>

/**
 * Constructor - initializes database with filename
 */
Database::Database(const std::string& filename) : filename(filename) {
    loadFromFile();
}

/**
 * Add a new student to database
 */
void Database::addStudent(const Student& student) {
    students.push_back(student);
    saveToFile();
}

/**
 * Find student by ID
 */
Student* Database::findStudentById(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        return &(*it);
    }
    return nullptr;
}

/**
 * Find student by name (first match)
 */
Student* Database::findStudentByName(const std::string& name) {
    auto it = std::find_if(students.begin(), students.end(),
        [&name](const Student& s) { 
            return s.getName().find(name) != std::string::npos; 
        });
    
    if (it != students.end()) {
        return &(*it);
    }
    return nullptr;
}

/**
 * Get all students
 */
std::vector<Student*> Database::findAllStudents() {
    std::vector<Student*> result;
    for (auto& student : students) {
        result.push_back(&student);
    }
    return result;
}

/**
 * Update student information
 */
bool Database::updateStudent(int id, const Student& updated) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        it->setName(updated.getName());
        it->setMajor(updated.getMajor());
        it->setGpa(updated.getGpa());
        saveToFile();
        return true;
    }
    return false;
}

/**
 * Delete student by ID
 */
bool Database::deleteStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        students.erase(it);
        saveToFile();
        return true;
    }
    return false;
}

/**
 * Get next ID for new student
 */
int Database::getNextId() const {
    return students.empty() ? 1 : students.back().getId() + 1;
}

/**
 * Get total number of students
 */
int Database::getTotalStudents() const {
    return students.size();
}

/**
 * Check if student exists
 */
bool Database::studentExists(int id) {
    return findStudentById(id) != nullptr;
}

/**
 * Save all students to binary file
 */
void Database::saveToFile() {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    int size = students.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& student : students) {
        // Write ID
        int id = student.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));

        // Write Name
        std::string name = student.getName();
        int nameLen = name.length();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);

        // Write Major
        std::string major = student.getMajor();
        int majorLen = major.length();
        file.write(reinterpret_cast<const char*>(&majorLen), sizeof(majorLen));
        file.write(major.c_str(), majorLen);

        // Write GPA
        float gpa = student.getGpa();
        file.write(reinterpret_cast<const char*>(&gpa), sizeof(gpa));
    }

    file.close();
}

/**
 * Load all students from binary file
 */
void Database::loadFromFile() {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        return; // File doesn't exist yet, start with empty database
    }

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    students.clear();

    for (int i = 0; i < size; ++i) {
        // Read ID
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));

        // Read Name
        int nameLen;
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        char nameBuf[256];
        file.read(nameBuf, nameLen);
        std::string name(nameBuf, nameLen);

        // Read Major
        int majorLen;
        file.read(reinterpret_cast<char*>(&majorLen), sizeof(majorLen));
        char majorBuf[256];
        file.read(majorBuf, majorLen);
        std::string major(majorBuf, majorLen);

        // Read GPA
        float gpa;
        file.read(reinterpret_cast<char*>(&gpa), sizeof(gpa));

        students.emplace_back(id, name, major, gpa);
    }

    file.close();
}
