#include "user.h"
#include <iostream>

/**
 * Default constructor
 */
User::User() : id(0), username(""), password(""), role(UserRole::STUDENT), relatedStudentId(-1) {}

/**
 * Parameterized constructor
 */
User::User(int id, const std::string& username, const std::string& password, 
           UserRole role, int relatedStudentId)
    : id(id), username(username), password(password), role(role), relatedStudentId(relatedStudentId) {}

// Getters
int User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

UserRole User::getRole() const {
    return role;
}

int User::getRelatedStudentId() const {
    return relatedStudentId;
}

// Setters
void User::setId(int id) {
    this->id = id;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

void User::setRole(UserRole role) {
    this->role = role;
}

void User::setRelatedStudentId(int studentId) {
    this->relatedStudentId = studentId;
}

// Utility methods
std::string User::getRoleString() const {
    return (role == UserRole::ADMIN) ? "Admin" : "Student";
}

bool User::isAdmin() const {
    return role == UserRole::ADMIN;
}

bool User::isStudent() const {
    return role == UserRole::STUDENT;
}
