#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Struct to store student information
struct Student {
    int id;
    string name;
    float gpa;
    string major;
};

// Global vector to store students
vector<Student> students;
const string FILENAME = "students.dat";

// Function prototypes
void displayMenu();
void addStudent();
void viewAllStudents();
void searchStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();
void editStudent();

// Display main menu
void displayMenu() {
    cout << "\n======================== STUDENT MANAGEMENT SYSTEM ========================\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Edit Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "=========================================================================\n";
    cout << "Please choose an option (1-6): ";
}

// Add a new student
void addStudent() {
    cout << "\n--- Add New Student ---\n";
    Student newStudent;
    
    // Find the next ID
    newStudent.id = students.empty() ? 1 : students.back().id + 1;
    
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    
    cout << "Enter Student Major: ";
    getline(cin, newStudent.major);
    
    cout << "Enter Student GPA (0.0 - 4.0): ";
    cin >> newStudent.gpa;
    
    students.push_back(newStudent);
    cout << "\n✓ Student added successfully! ID: " << newStudent.id << "\n";
    saveToFile();
}

// View all students
void viewAllStudents() {
    cout << "\n--- All Students ---\n";
    
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }
    
    cout << left << setw(8) << "ID" << setw(25) << "Name" 
         << setw(20) << "Major" << setw(10) << "GPA\n";
    cout << string(63, '-') << "\n";
    
    for (const auto& student : students) {
        cout << left << setw(8) << student.id 
             << setw(25) << student.name 
             << setw(20) << student.major 
             << fixed << setprecision(2) << student.gpa << "\n";
    }
}

// Search for a student by ID or name
void searchStudent() {
    cout << "\n--- Search Student ---\n";
    cout << "Search by (1) ID or (2) Name? (1/2): ";
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        int searchId;
        cout << "Enter Student ID: ";
        cin >> searchId;
        
        auto it = find_if(students.begin(), students.end(), 
            [searchId](const Student& s) { return s.id == searchId; });
        
        if (it != students.end()) {
            cout << "\n✓ Student Found:\n";
            cout << "ID: " << it->id << "\nName: " << it->name 
                 << "\nMajor: " << it->major << "\nGPA: " 
                 << fixed << setprecision(2) << it->gpa << "\n";
        } else {
            cout << "\n✗ Student not found.\n";
        }
    } else if (choice == 2) {
        string searchName;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, searchName);
        
        int found = 0;
        for (const auto& student : students) {
            if (student.name.find(searchName) != string::npos) {
                cout << "\n✓ Student Found:\n";
                cout << "ID: " << student.id << "\nName: " << student.name 
                     << "\nMajor: " << student.major << "\nGPA: " 
                     << fixed << setprecision(2) << student.gpa << "\n";
                found++;
            }
        }
        if (found == 0) {
            cout << "\n✗ No student found with that name.\n";
        }
    }
}

// Edit student information
void editStudent() {
    cout << "\n--- Edit Student ---\n";
    int editId;
    cout << "Enter Student ID to edit: ";
    cin >> editId;
    
    auto it = find_if(students.begin(), students.end(), 
        [editId](const Student& s) { return s.id == editId; });
    
    if (it != students.end()) {
        cout << "\nCurrent Information:\n";
        cout << "Name: " << it->name << "\nMajor: " << it->major 
             << "\nGPA: " << fixed << setprecision(2) << it->gpa << "\n";
        
        cout << "\nEnter new Name: ";
        cin.ignore();
        getline(cin, it->name);
        
        cout << "Enter new Major: ";
        getline(cin, it->major);
        
        cout << "Enter new GPA: ";
        cin >> it->gpa;
        
        cout << "\n✓ Student information updated successfully!\n";
        saveToFile();
    } else {
        cout << "\n✗ Student not found.\n";
    }
}

// Delete a student
void deleteStudent() {
    cout << "\n--- Delete Student ---\n";
    int deleteId;
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;
    
    auto it = find_if(students.begin(), students.end(), 
        [deleteId](const Student& s) { return s.id == deleteId; });
    
    if (it != students.end()) {
        cout << "Deleting: " << it->name << "\n";
        students.erase(it);
        cout << "✓ Student deleted successfully!\n";
        saveToFile();
    } else {
        cout << "✗ Student not found.\n";
    }
}

// Save students to file
void saveToFile() {
    ofstream file(FILENAME, ios::binary);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    
    int size = students.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    
    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student.id), sizeof(student.id));
        
        int nameLen = student.name.length();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(student.name.c_str(), nameLen);
        
        int majorLen = student.major.length();
        file.write(reinterpret_cast<const char*>(&majorLen), sizeof(majorLen));
        file.write(student.major.c_str(), majorLen);
        
        file.write(reinterpret_cast<const char*>(&student.gpa), sizeof(student.gpa));
    }
    
    file.close();
}

// Load students from file
void loadFromFile() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        return; // File doesn't exist yet
    }
    
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    
    students.clear();
    for (int i = 0; i < size; i++) {
        Student student;
        file.read(reinterpret_cast<char*>(&student.id), sizeof(student.id));
        
        int nameLen;
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        char nameBuf[256];
        file.read(nameBuf, nameLen);
        student.name = string(nameBuf, nameLen);
        
        int majorLen;
        file.read(reinterpret_cast<char*>(&majorLen), sizeof(majorLen));
        char majorBuf[256];
        file.read(majorBuf, majorLen);
        student.major = string(majorBuf, majorLen);
        
        file.read(reinterpret_cast<char*>(&student.gpa), sizeof(student.gpa));
        
        students.push_back(student);
    }
    
    file.close();
}

// Main program
int main() {
    loadFromFile();
    
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                editStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                cout << "Thank you for using Student Management System!\n";
                cout << "Goodbye!\n";
                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                return 0;
            default:
                cout << "\n✗ Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
