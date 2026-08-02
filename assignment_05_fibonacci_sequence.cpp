// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// PART A: Prints the first N terms of the Fibonacci sequence
void printFibonacci(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a ;
        if (i < n - 1) {
            cout << " ";
        }
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// PART B: Checks if a number belongs to the Fibonacci sequence
bool isFibonacci(int num) {
    if (num < 0) {
        return false; // Negative numbers are not in the Fibonacci sequence
    }
    int a = 0, b = 1;
    while (a < num) {
        if (a <= num) {
            return true; // Found the number in the sequence
        }
        int next = a + b;
        a = b;
        b = next;
    }
    return false; // Number is not in the sequence
}

int main() {
    // PART A
    int n;
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
    } else {
        printFibonacci(n);
    }

    // PART B
    int numberToCheck;
    cout << "Enter a number to check: ";
    cin >> numberToCheck;

    if (isFibonacci(numberToCheck)) {
        cout << numberToCheck << " is a Fibonacci number." << endl;
    } else {
        cout << numberToCheck << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
