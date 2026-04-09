#ifndef GRADE_H
#define GRADE_H

/**
 * @class Grade
 * @brief Student grade/score for a course
 */
class Grade {
private:
    int id;
    int studentId;
    int courseId;
    float score;  // 0.0 to 10.0

public:
    // Constructors
    Grade();
    Grade(int id, int studentId, int courseId, float score);

    // Getters
    int getId() const;
    int getStudentId() const;
    int getCourseId() const;
    float getScore() const;

    // Setters
    void setId(int id);
    void setStudentId(int studentId);
    void setCourseId(int courseId);
    void setScore(float score);

    // Utility methods
    void display() const;
    bool isValid() const;  // Check if score is in valid range 0-10
};

#endif // GRADE_H
