#include "course.h"
#include <iostream>
#include <iomanip>

/**
 * Default constructor
 */
Course::Course() : id(0), name(""), credits(0) {}

/**
 * Parameterized constructor
 */
Course::Course(int id, const std::string& name, int credits)
    : id(id), name(name), credits(credits) {}

// Getters
int Course::getId() const {
    return id;
}

std::string Course::getName() const {
    return name;
}

int Course::getCredits() const {
    return credits;
}

// Setters
void Course::setId(int id) {
    this->id = id;
}

void Course::setName(const std::string& name) {
    this->name = name;
}

void Course::setCredits(int credits) {
    this->credits = (credits < 0) ? 0 : credits;
}

/**
 * Display course information
 */
void Course::display() const {
    std::cout << std::left << std::setw(5) << id
              << std::setw(40) << name
              << std::setw(10) << credits << "\n";
}
