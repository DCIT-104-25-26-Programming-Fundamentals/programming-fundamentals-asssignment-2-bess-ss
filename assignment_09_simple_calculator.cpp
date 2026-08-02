// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Adds two numbers and returns the result
double add(double a, double b) {
    return a + b;
}

// Subtracts b from a
double subtract(double a, double b) {
    return a - b;
}

// Multiplies two numbers
double multiply(double a, double b) {  
    return a * b;
}

// Divides a by b, returns 0 if b is 0 (caller should handle this case)
double divide(double a, double b) {
    return a/b;
}

// Computes the remainder of a divided by b. Caller checks b != 0 first.
double modulus(double a, double b) {
    return fmod(a, b);
}

// Raises a to the power of b using a loop ( handles negative examples)
double exponentiate(double base, int exponent) {
    double result = 1.0;
    int n = (exponent < 0) ? -exponent : exponent; // Handle negative exponents
    for (int i = 0; i < n; ++i) {
        result *= base;
    }
    if (exponent < 0) {
        return 1.0 / result; // Return reciprocal for negative exponent
    }
    return result;
}

int main() {
    int choice;
    
    do {
        // Display the menu
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number." << endl << endl;
        continue;
    }
    cout << endl; // Add a blank line for better readability

    if (choice == 7) {
        cout << "Goodbye!" << endl;
        break;
    }

    if (choice < 1 || choice > 7) {
        cout << "Invalid choice. Please select a number between 1 and 7." << endl << endl;
        continue;
    }

    // Exponentiation reads its second value as an integer exponent.
    if (choice == 6) {
        double base;
        int exponent;
        cout << "Enter first number : ";
        cin >> base;
        cout << "Enter second number: ";
        cin >> exponent;

        double result = exponentiate(base, exponent);
        cout << " Result: " << base << " ^ " << exponent << " = " << fixed << setprecision(2) << result << endl << endl;
        cout << defaultfloat; // Reset to default formatting
        continue;
    }

    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    double result = 0.0;
    char symbol = '?';

    switch (choice) {
        case 1:
            result = add(num1, num2);
            symbol = '+';
            break;
        case 2:
            result = subtract(num1, num2);
            symbol = '-';
            break;
        case 3:
            result = multiply(num1, num2);
            symbol = '*';
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error: Cannot divide by zero." << endl << endl;
                continue;
            }
            result = divide(num1, num2);
            symbol = '/';
            break;
        case 5:
            if (num2 == 0) {
                cout << "Error: Cannot perform modulus by zero." << endl << endl;
                continue;
            }
            result = ::modulus(num1, num2);
            symbol = '%';
            break;
    }

    cout << "Result: " << num1 << " " << symbol << " " << num2 << " = " << fixed << setprecision(2) << result << endl << endl;
    cout << defaultfloat; // Reset to default formatting

} while (choice != 7);

    return 0;
}
