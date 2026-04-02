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
    std::string major;
    float gpa;

public:
    // Constructors
    Student();
    Student(int id, const std::string& name, const std::string& major, float gpa);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getMajor() const;
    float getGpa() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setMajor(const std::string& major);
    void setGpa(float gpa);

    // Utility methods
    void display() const;
};

#endif // STUDENT_H
