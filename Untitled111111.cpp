#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Subject {
    string name;
    int credits;
};

struct Score {
    Subject sub;
    float grade;
};

class Student {
public:
    string id;
    string name;
    string password;
    vector<Score> scores;

    Student(string i, string n, string p) : id(i), name(n), password(p) {}

    float calculateGPA() const {
        if (scores.empty()) return 0.0;
        float totalPoints = 0;
        int totalCredits = 0;
        for (const auto& s : scores) {
            totalPoints += s.grade * s.sub.credits;
            totalCredits += s.sub.credits;
        }
        return totalCredits == 0 ? 0 : totalPoints / totalCredits;
    }

    void displayTranscript() const {
        cout << "\nMSSV: " << id << " | Ten: " << name << "\n";
        cout << "----------------------------------------------\n";
        cout << left << setw(20) << "Mon hoc" << setw(10) << "Tin chi" << "Diem\n";
        for (const auto& s : scores) {
            cout << left << setw(20) << s.sub.name << setw(10) << s.sub.credits << s.grade << "\n";
        }
        cout << "----------------------------------------------\n";
        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << "\n\n";
    }
};

class SystemManager {
private:
    vector<Student> students;
    vector<Subject> subjects;
    string adminPass = "PTIT.administrator";

public:
    SystemManager() {
        subjects.push_back({"Toan Cao Cap", 3});
        subjects.push_back({"Lap Trinh C++", 4});
        subjects.push_back({"Vat Ly Dai Cuong", 3});
        subjects.push_back({"Cau Truc Du Lieu", 3});
    }

    void run() {
        while (true) {
            cout << "===== HE THONG QUAN LY SINH VIEN =====\n";
            cout << "1. Dang nhap Admin\n2. Dang nhap Sinh vien\n0. Thoat\nChon: ";
            int choice;
            cin >> choice;
            if (choice == 0) break;
            if (choice == 1) loginAdmin();
            else if (choice == 2) loginStudent();
        }
    }

private:
    void loginAdmin() {
        string pass;
        cout << "Mat khau Admin: ";
        cin >> pass;
        if (pass == adminPass) adminMenu();
        else cout << "Sai mat khau!\n\n";
    }

    void loginStudent() {
        string id, pass;
        cout << "MSSV: "; cin >> id;
        cout << "Mat khau: "; cin >> pass;
        for (auto& st : students) {
            if (st.id == id && st.password == pass) {
                studentMenu(st);
                return;
            }
        }
        cout << "Sai thong tin dang nhap!\n\n";
    }

    void adminMenu() {
        while (true) {
            cout << "\n--- ADMIN MENU ---\n";
            cout << "1. Danh sach sinh vien\n2. Them sinh vien\n3. Sua thong tin\n4. Xoa sinh vien\n5. Tim kiem\n6. Nhap diem\n0. Dang xuat\nChon thao tac: ";
            int choice;
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: displayAllStudents(); break;
                case 2: addStudent(); break;
                case 3: editStudent(); break;
                case 4: deleteStudent(); break;
                case 5: searchStudent(); break;
                case 6: enterGrade(); break;
            }
        }
    }

    void studentMenu(const Student& st) {
        while (true) {
            cout << "\n--- STUDENT MENU ---\n";
            cout << "1. Xem thong tin & Bang diem\n0. Dang xuat\nChon thao tac: ";
            int choice;
            cin >> choice;
            if (choice == 0) break;
            if (choice == 1) st.displayTranscript();
        }
    }

    void displayAllStudents() {
        cout << "\n" << left << setw(15) << "MSSV" << setw(25) << "Ten" << "GPA\n";
        cout << "----------------------------------------------\n";
        for (const auto& st : students) {
            cout << left << setw(15) << st.id << setw(25) << st.name << fixed << setprecision(2) << st.calculateGPA() << "\n";
        }
        cout << "\n";
    }

    void addStudent() {
        string id, name, pass;
        cout << "MSSV: "; cin >> id;
        cout << "Ten: "; cin.ignore(); getline(cin, name);
        cout << "Mat khau: "; cin >> pass;
        students.push_back(Student(id, name, pass));
        cout << "Da them sinh vien thanh cong.\n";
    }

    void editStudent() {
        string id;
        cout << "Nhap MSSV can sua: "; cin >> id;
        for (auto& st : students) {
            if (st.id == id) {
                cout << "Ten moi: "; cin.ignore(); getline(cin, st.name);
                cout << "Mat khau moi: "; cin >> st.password;
                cout << "Da cap nhat thong tin.\n";
                return;
            }
        }
        cout << "Khong tim thay MSSV.\n";
    }

    void deleteStudent() {
        string id;
        cout << "Nhap MSSV can xoa: "; cin >> id;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Da xoa sinh vien.\n";
                return;
            }
        }
        cout << "Khong tim thay MSSV.\n";
    }

    void searchStudent() {
        string keyword;
        cout << "Nhap MSSV hoac Ten: "; cin.ignore(); getline(cin, keyword);
        cout << "\nKet qua tim kiem:\n";
        for (const auto& st : students) {
            if (st.id == keyword || st.name.find(keyword) != string::npos) {
                cout << "-> " << st.id << " | " << st.name << " | GPA: " << fixed << setprecision(2) << st.calculateGPA() << "\n";
            }
        }
    }

    void enterGrade() {
        string id;
        cout << "Nhap MSSV: "; cin >> id;
        for (auto& st : students) {
            if (st.id == id) {
                cout << "Danh sach mon hoc:\n";
                for (size_t i = 0; i < subjects.size(); ++i) {
                    cout << i + 1 << ". " << subjects[i].name << " (" << subjects[i].credits << " TC)\n";
                }
                int subChoice;
                cout << "Chon mon hoc (1-" << subjects.size() << "): "; cin >> subChoice;
                
                if (subChoice > 0 && subChoice <= subjects.size()) {
                    float grade;
                    cout << "Nhap diem (hệ 10): "; cin >> grade;
                    st.scores.push_back({subjects[subChoice - 1], grade});
                    cout << "Da luu diem thanh cong.\n";
                } else {
                    cout << "Lua chon khong hop le.\n";
                }
                return;
            }
        }
        cout << "Khong tim thay MSSV.\n";
    }
};

int main() {
    SystemManager app;
    app.run();
    return 0;
}