#include <iostream>
#include <string>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <cctype>    // for toupper()

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = char((decimal % 2) + '0') + binary;
        decimal /= 2;
    }
    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(const string &binary) {
    int decimal = 0;
    for (char digit : binary) {
        if (digit != '0' && digit != '1') {
            cout << "Invalid binary number.\n";
            return -1;
        }
        decimal = decimal * 2 + (digit - '0');
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal
string decimalToHex(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    const string hexDigits = "0123456789ABCDEF";
    while (decimal > 0) {
        hex = hexDigits[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexToDecimal(const string &hex) {
    int decimal = 0;
    for (char digit : hex) {
        digit = toupper(digit);
        if (!isxdigit(digit)) {
            cout << "Invalid hexadecimal number.\n";
            return -1;
        }
        decimal = decimal * 16 + (isdigit(digit) ? digit - '0' : digit - 'A' + 10);
    }
    return decimal;
}

// Menu System
void showMenu() {
    cout << "\nConversion Menu:\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Hexadecimal to Decimal\n";
    cout << "4. Convert Decimal to Hexadecimal\n";
    cout << "5. Demo (Generate and convert random integers to binary)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    int choice;
    srand(time(0)); // Seed random number generator

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Binary representation: " << decimalToBinary(decimal) << endl;

        } else if (choice == 2) {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            int result = binaryToDecimal(binary);
            if (result != -1)
                cout << "Decimal representation: " << result << endl;

        } else if (choice == 3) {
            string hex;
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            int result = hexToDecimal(hex);
            if (result != -1)
                cout << "Decimal representation: " << result << endl;

        } else if (choice == 4) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Hexadecimal representation: " << decimalToHex(decimal) << endl;

        } else if (choice == 5) {
            int randomNumber = rand() % 100; // 0-99
            cout << "Generated random integer: " << randomNumber << endl;
            cout << "Binary representation: " << decimalToBinary(randomNumber) << endl;

        } else if (choice == 6) {
            cout << "Exiting the program.\n";
            break;

        } else {
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
