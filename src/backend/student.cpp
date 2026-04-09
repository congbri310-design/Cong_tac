#include "student.h"
#include <iostream>
#include <iomanip>

/**
 * Default constructor - initializes empty student
 */
Student::Student() : id(0), name(""), studentId(""), major(""), gpa(0.0f) {}

/**
 * Parameterized constructor
 */
Student::Student(int id, const std::string& name, const std::string& studentId, 
                 const std::string& major, float gpa)
    : id(id), name(name), studentId(studentId), major(major), gpa(gpa) {}

// Getters
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getStudentId() const {
    return studentId;
}

std::string Student::getMajor() const {
    return major;
}

float Student::getGpa() const {
    return gpa;
}

// Setters
void Student::setId(int id) {
    this->id = id;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setStudentId(const std::string& studentId) {
    this->studentId = studentId;
}

void Student::setMajor(const std::string& major) {
    this->major = major;
}

void Student::setGpa(float gpa) {
    this->gpa = (gpa < 0.0f) ? 0.0f : (gpa > 4.0f) ? 4.0f : gpa;
}

/**
 * Display student information
 */
void Student::display() const {
    std::cout << std::left << std::setw(8) << id 
              << std::setw(15) << studentId
              << std::setw(25) << name 
              << std::setw(20) << major 
              << std::fixed << std::setprecision(2) << gpa << "\n";
}
