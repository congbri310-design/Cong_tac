#ifndef USER_H
#define USER_H

#include <string>

/**
 * @enum UserRole
 * @brief Role enumeration for user permissions
 */
enum class UserRole {
    ADMIN = 1,    // Lecturer/Manager - full permissions
    STUDENT = 2   // Student - read-only for personal data
};

/**
 * @class User
 * @brief User account model for authentication
 */
class User {
private:
    int id;
    std::string username;
    std::string password;
    UserRole role;
    int relatedStudentId;  // For student accounts, links to student ID; -1 for admin

public:
    // Constructors
    User();
    User(int id, const std::string& username, const std::string& password, 
         UserRole role, int relatedStudentId = -1);

    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    UserRole getRole() const;
    int getRelatedStudentId() const;

    // Setters
    void setId(int id);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setRole(UserRole role);
    void setRelatedStudentId(int studentId);

    // Utility methods
    std::string getRoleString() const;
    bool isAdmin() const;
    bool isStudent() const;
};

#endif // USER_H
