#include <iostream> //for input/output (cin and cout)
#include <string>  //for using strings (std,string)
#include <cstdlib>  // for rand[currency and string] 
#include <ctime>    //time
#include <cctype>   //for character functions like toupper and isxdigit

using namespace std;


string decToBin(int num) { // converting decimal to binary
    if (num == 0) return "0";
    string result = ""; //when input is 0
    while (num > 0) {
        result = char((num % 2) + '0') + result;
        num /= 2;
    }
    return result; //final ressult
}


int binToDec(const string& binStr) { //convert binary to decimal
    int total = 0;
    for (char ch : binStr) {
        if (ch != '0' && ch != '1') {
            cout << "Error: Not a valid binary number.\n";
            return -1; //loops through each character in the string
        }
        total = total * 2 + (ch - '0'); //any character that is not 0 or 1 is invalid
    }
    return total;
}


string decToHex(int num) { //convert decimal to hexadecimal
    if (num == 0) return "0";
    string hexChars = "0123456789ABCDEF";
    string result = "";
    while (num > 0) {
        result = hexChars[num % 16] + result;
        num /= 16;
    }
    return result;
}


int hexToDec(const string& hexStr) { //convert hexadecimal to decimal
    int total = 0;
    for (char ch : hexStr) {
        ch = toupper(ch);
        if (!isxdigit(ch)) {
            cout << "Error: Not a valid hexadecimal number.\n";
            return -1;
        }
        total = total * 16 + (isdigit(ch) ? ch - '0' : ch - 'A' + 10);
    }
    return total;
}


void displayMenu() { //display menu options
    cout << "\n==== Number Conversion Tool ====\n";
    cout << "1. Decimal to Binary\n";
    cout << "2. Binary to Decimal\n";
    cout << "3. Hexadecimal to Decimal\n";
    cout << "4. Decimal to Hexadecimal\n";
    cout << "5. Random Demo (decimal to binary)\n";
    cout << "6. Quit\n";
    cout << "Select an option (1-6): ";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // random 
    int option;

    while (true) {
        displayMenu();
        cin >> option;

        if (option == 1) {
            int val;
            cout << "Enter decimal number: ";
            cin >> val;
            cout << "Binary: " << decToBin(val) << endl;

        } else if (option == 2) {
            string bin;
            cout << "Enter binary number: ";
            cin >> bin;
            int result = binToDec(bin);
            if (result != -1)
                cout << "Decimal: " << result << endl;

        } else if (option == 3) {
            string hex;
            cout << "Enter hexadecimal number: ";
            cin >> hex;
            int result = hexToDec(hex);
            if (result != -1)
                cout << "Decimal: " << result << endl;

        } else if (option == 4) {
            int val;
            cout << "Enter decimal number: ";
            cin >> val;
            cout << "Hexadecimal: " << decToHex(val) << endl;

        } else if (option == 5) {
            int rnd = rand() % 100;
            cout << "Random number: " << rnd << endl;
            cout << "Binary: " << decToBin(rnd) << endl;

        } else if (option == 6) {
            cout << "Goodbye.\n";
            break;

        } else {
            cout << "Invalid selection. Try again.\n";
        }
    }

    return 0;
}

