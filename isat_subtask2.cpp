#include <iostream>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal) {
    string binary = "";
    if (decimal == 0) return "0";

    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }

    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;

    for (char bit : binary) {
        if (bit != '0' && bit != '1') {
            cout << "Invalid binary input.\n";
            return -1;
        }
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int decimal) {
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";

    if (decimal == 0) return "0";

    while (decimal > 0) {
        int remainder = decimal % 16;
        hex = hexDigits[remainder] + hex;
        decimal /= 16;
    }

    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    for (char ch : hex) {
        decimal *= 16;
        if (ch >= '0' && ch <= '9')
            decimal += ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            decimal += ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            decimal += ch - 'a' + 10;
        else {
            cout << "Invalid hexadecimal input.\n";
            return -1;
        }
    }

    return decimal;
}

// Display menu and get user choice
void displayMenu() {
    cout << "\n===== Number Converter Menu =====\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Decimal to Hexadecimal\n";
    cout << "4. Convert Hexadecimal to Decimal\n";
    cout << "5. Demo (Random number to Binary)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}


int main() {
    int choice;

    srand(time(0));  // random seed generation

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int decimal;
                cout << "Enter a decimal number: ";
                cin >> decimal;
                if (decimal < 0) {
                    cout << "Please enter a non-negative number.\n";
                    break;
                }
                cout << "Binary equivalent: " << decimalToBinary(decimal) << endl;
                break;
            }

            case 2: {
                string binary;
                cout << "Enter a binary number: ";
                cin >> binary;
                int decimal = binaryToDecimal(binary);
                if (decimal != -1)
                    cout << "Decimal equivalent: " << decimal << endl;
                break;
            }

            case 3: {
                int decimal;
                cout << "Enter a decimal number: ";
                cin >> decimal;
                if (decimal < 0) {
                    cout << "Please enter a non-negative number.\n";
                    break;
                }
                cout << "Hexadecimal equivalent: " << decimalToHexadecimal(decimal) << endl;
                break;
            }

            case 4: {
                string hex;
                cout << "Enter a hexadecimal number: ";
                cin >> hex;
                int decimal = hexadecimalToDecimal(hex);
                if (decimal != -1)
                    cout << "Decimal equivalent: " << decimal << endl;
                break;
            }

            case 5: {
                int randomNum = rand() % 100;
                cout << "Random number: " << randomNum << endl;
                cout << "Binary: " << decimalToBinary(randomNum) << endl;
                break;
            }

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}

