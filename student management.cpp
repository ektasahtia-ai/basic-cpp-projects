#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (auto s : students) {
        cout << "Roll No: " << s.rollNo
             << " | Name: " << s.name
             << " | Marks: " << s.marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    for (auto s : students) {
        if (s.rollNo == roll) {
            cout << "Student Found!\n";
            cout << "Name: " << s.name
                 << "\nMarks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student Not Found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            students.erase(students.begin() + i);
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}