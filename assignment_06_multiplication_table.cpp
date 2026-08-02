// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// PART A: Prints the multiplication table for a given number
void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

// PART B: Prints multiplication tables for all numbers from 1 to N
void printTablesUpToN(int n) {
    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num < n) {
            cout << "---------------------------" << endl; // Separator line between tables
        }
    }
}

int main() {
    // Part A
    int number;
    cout << "Enter a number: ";
    cin >> number;

    printTable(number);

    cout << endl; // Add a blank line before Part B

    // Part B
    int n;
    cout << "Enter a number N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
    } else {
        printTablesUpToN(n);
    }

    return 0;
}
