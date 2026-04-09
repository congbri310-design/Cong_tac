#ifndef COURSE_H
#define COURSE_H

#include <string>

/**
 * @class Course
 * @brief Course information model
 */
class Course {
private:
    int id;
    std::string name;
    int credits;  // Number of credit hours

public:
    // Constructors
    Course();
    Course(int id, const std::string& name, int credits);

    // Getters
    int getId() const;
    std::string getName() const;
    int getCredits() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setCredits(int credits);

    // Utility methods
    void display() const;
};

#endif // COURSE_H
