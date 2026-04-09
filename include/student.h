#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/**
 * @class Student
 * @brief Data model for student information
 */
class Student {
private:
    int id;
    std::string name;
    std::string studentId;  // MSSV - Student ID Code (e.g., "SV001")
    std::string major;
    float gpa;  // Will be calculated from grades

public:
    // Constructors
    Student();
    Student(int id, const std::string& name, const std::string& studentId, 
            const std::string& major, float gpa = 0.0f);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getStudentId() const;  // MSSV getter
    std::string getMajor() const;
    float getGpa() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setStudentId(const std::string& studentId);  // MSSV setter
    void setMajor(const std::string& major);
    void setGpa(float gpa);

    // Utility methods
    void display() const;
};

#endif // STUDENT_H
