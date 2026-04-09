#include "grade.h"
#include <iostream>
#include <iomanip>

/**
 * Default constructor
 */
Grade::Grade() : id(0), studentId(0), courseId(0), score(0.0f) {}

/**
 * Parameterized constructor
 */
Grade::Grade(int id, int studentId, int courseId, float score)
    : id(id), studentId(studentId), courseId(courseId), score(score) {}

// Getters
int Grade::getId() const {
    return id;
}

int Grade::getStudentId() const {
    return studentId;
}

int Grade::getCourseId() const {
    return courseId;
}

float Grade::getScore() const {
    return score;
}

// Setters
void Grade::setId(int id) {
    this->id = id;
}

void Grade::setStudentId(int studentId) {
    this->studentId = studentId;
}

void Grade::setCourseId(int courseId) {
    this->courseId = courseId;
}

void Grade::setScore(float score) {
    this->score = (score < 0.0f) ? 0.0f : (score > 10.0f) ? 10.0f : score;
}

/**
 * Display grade information
 */
void Grade::display() const {
    std::cout << std::left << std::setw(8) << studentId
              << std::setw(8) << courseId
              << std::fixed << std::setprecision(2) << score << "\n";
}

/**
 * Check if score is valid
 */
bool Grade::isValid() const {
    return score >= 0.0f && score <= 10.0f;
}
