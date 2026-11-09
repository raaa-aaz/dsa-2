#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// System States using enum
enum MainOption {
    CALCULATOR = 1,
    GRADING_SYSTEM,
    CONVERTER,
    EXIT
};

int main() {
    int mainChoice;
    bool running = true;

    while (running) {
        cout << "\n==========================================" << endl;
        cout << "   SMART UTILITY & MANAGEMENT SYSTEM      " << endl;
        cout << "==========================================" << endl;
        cout << "1. Multi-Functional Calculator" << endl;
        cout << "2. Student Grade & CGPA Calculator" << endl;
        cout << "3. Unit Converter" << endl;
        cout << "4. Exit Program" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> mainChoice;

        switch (mainChoice) {
            case CALCULATOR: {
                int calcChoice;
                cout << "\n--- CALCULATOR MENU ---" << endl;
                cout << "1. Basic Arithmetic (+, -, *, /, %)" << endl;
                cout << "2. Advanced Math (Power, Square Root)" << endl;
                cout << "Enter choice: ";
                cin >> calcChoice;

                switch (calcChoice) {
                    case 1: {
                        double num1, num2;
                        char op;
                        cout << "Enter expression (e.g. 10 + 5): ";
                        cin >> num1 >> op >> num2;

                        switch (op) {
                            case '+':
                                cout << "Result: " << num1 + num2 << endl;
                                break;
                            case '-':
                                cout << "Result: " << num1 - num2 << endl;
                                break;
                            case '*':
                                cout << "Result: " << num1 * num2 << endl;
                                break;
                            case '/':
                                if (num2 != 0) {
                                    cout << "Result: " << (double)num1 / num2 << endl;
                                } else {
                                    cout << "Error: Division by zero!" << endl;
                                }
                                break;
                            case '%':
                                if ((int)num2 != 0) {
                                    cout << "Result: " << (int)num1 % (int)num2 << endl;
                                } else {
                                    cout << "Error: Modulo by zero!" << endl;
                                }
                                break;
                            default:
                                cout << "Invalid operator!" << endl;
                        }
                        break;
                    }
                    case 2: {
                        int advChoice;
                        cout << "1. Power (x^y)\n2. Square Root (sqrt)\nEnter choice: ";
                        cin >> advChoice;

                        switch (advChoice) {
                            case 1: {
                                double base, exp;
                                cout << "Enter base and exponent: ";
                                cin >> base >> exp;
                                cout << "Result: " << pow(base, exp) << endl;
                                break;
                            }
                            case 2: {
                                double val;
                                cout << "Enter number: ";
                                cin >> val;
                                if (val >= 0)
                                    cout << "Result: " << sqrt(val) << endl;
                                else
                                    cout << "Error: Negative number!" << endl;
                                break;
                            }
                            default:
                                cout << "Invalid advanced math selection!" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid Calculator Option!" << endl;
                }
                break;
            }

            case GRADING_SYSTEM: {
                int marks;
                cout << "\n--- STUDENT GRADING SYSTEM ---" << endl;
                cout << "Enter total marks (0-100): ";
                cin >> marks;

                if (marks < 0 || marks > 100) {
                    cout << "Invalid marks entered!" << endl;
                    break;
                }

                // Range categorization using integer division
                switch (marks / 10) {
                    case 10:
                    case 9:
                    case 8:
                        cout << "Grade: A+ | GPA: 4.00 | Remark: Outstanding" << endl;
                        break;
                    case 7:
                        cout << "Grade: A  | GPA: 3.75 | Remark: Excellent" << endl;
                        break;
                    case 6:
                        cout << "Grade: B  | GPA: 3.00 | Remark: Good" << endl;
                        break;
                    case 5:
                        cout << "Grade: C  | GPA: 2.50 | Remark: Average" << endl;
                        break;
                    case 4:
                        cout << "Grade: D  | GPA: 2.00 | Remark: Pass" << endl;
                        break;
                    default:
                        cout << "Grade: F  | GPA: 0.00 | Remark: Fail" << endl;
                }
                break;
            }

            case CONVERTER: {
                int convChoice;
                cout << "\n--- UNIT CONVERTER MENU ---" << endl;
                cout << "1. Temperature (Celsius to Fahrenheit / Kelvin)" << endl;
                cout << "2. Distance (Kilometer to Meter / Mile)" << endl;
                cout << "Enter choice: ";
                cin >> convChoice;

                switch (convChoice) {
                    case 1: {
                        double celsius;
                        int tempSubChoice;
                        cout << "Enter temperature in Celsius: ";
                        cin >> celsius;
                        cout << "Convert to: 1. Fahrenheit  2. Kelvin: ";
                        cin >> tempSubChoice;

                        switch (tempSubChoice) {
                            case 1:
                                cout << "Fahrenheit: " << (celsius * 9/5) + 32 << "°F" << endl;
                                break;
                            case 2:
                                cout << "Kelvin: " << celsius + 273.15 << " K" << endl;
                                break;
                            default:
                                cout << "Invalid temperature unit!" << endl;
                        }
                        break;
                    }
                    case 2: {
                        double km;
                        int distSubChoice;
                        cout << "Enter distance in Kilometers: ";
                        cin >> km;
                        cout << "Convert to: 1. Meters  2. Miles: ";
                        cin >> distSubChoice;

                        switch (distSubChoice) {
                            case 1:
                                cout << "Meters: " << km * 1000 << " m" << endl;
                                break;
                            case 2:
                                cout << "Miles: " << km * 0.621371 << " miles" << endl;
                                break;
                            default:
                                cout << "Invalid distance unit!" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid Converter Option!" << endl;
                }
                break;
            }

            case EXIT:
                cout << "\nExiting Program... Goodbye!" << endl;
                running = false;
                break;

            default:
                cout << "\nInvalid Main Menu choice! Please select 1-4." << endl;
        }
    }

    return 0;
}