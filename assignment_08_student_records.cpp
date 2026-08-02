// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stream>
#include <limits>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Displays the main menu
void displayMenu() {
    cout << "===============================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;    
    cout << "===============================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

//Computes the average of a list of scores. Returns 0 if the list is empty.
double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0; // Avoid division by zero
    }
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// Adds a new student record to the list
void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    getline(cin, newStudent.name); // Use getline to allow spaces in the name

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; ++i) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }
    cin.ignore(); // Clear the newline character from the input buffer

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// Displays all student records in a formatted table
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(25) << "Scores" << setw(10) << "Average" << endl;
    cout << string(65, '-') << endl;

    for (const Student& student : students) {
        ostringstream sstream;
        for (size_t i = 0; i < student.scores.size(); ++i) {
            sstream << student.scores[i];
            if (i < student.scores.size() - 1) {
                sstream << ", ";
            }
        }

        cout << left << setw(20) << student.name << setw(12) << student.id << setw(25) << sstream.str() << fixed << setprecision(2) << setw(10) << calculateAverage(student.scores) << endl;
    }
}

// Calculates and displays the average score for a specific student by ID
void calculateAverageForStudent(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // Clear the newline character from the input buffer

    for (const Student& student : students) {
        if (student.id == id) {
            cout << student.name << "'s average score: " << fixed << setprecision(2) << calculateAverage(student.scores) << endl;
            return;
        }
    }
    cout << "Error: Student with ID " << id << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer
        cout << endl; // Add a blank line for better readability

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateAverageForStudent(students);
        } else if (choice == 4) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << endl; // Add a blank line before showing the menu again

    } while (choice != 4);

    return 0;
}
