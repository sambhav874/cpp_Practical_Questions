#include <iostream>

using namespace std;

// Function to show address of each character in a string
void showAddress(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Address of " << str[i] << ": " << (void*)&str[i] << endl;
    }
}

// Function to calculate the length of a string
int calculateLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to compare two strings
bool compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

// Function to convert all lowercase characters to uppercase
void convertToUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

// Function to reverse a string
void reverseString(char* str) {
    int length = calculateLength(str);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str1[100];
    char str2[100];
    int choice;

    cout << "Enter string 1: ";
    cin.getline(str1, 100);

    cout << "Enter string 2: ";
    cin.getline(str2, 100);

    cout << "Menu:\n";
    cout << "1. Show address of each character in string\n";
    cout << "2. Concatenate two strings\n";
    cout << "3. Compare two strings\n";
    cout << "4. Calculate length of the string\n";
    cout << "5. Convert all lowercase characters to uppercase\n";
    cout << "6. Reverse the string\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "String 1:\n";
            showAddress(str1);
            cout << "String 2:\n";
            showAddress(str2);
            break;
        case 2:
            strcat(str1, str2);
            cout << "Concatenated string: " << str1 << endl;
            break;
        case 3:
            if (compareStrings(str1, str2)) {
                cout << "Strings are equal\n";
            } else {
                cout << "Strings are not equal\n";
            }
            break;
        case 4:
            cout << "Length of string 1: " << calculateLength(str1) << endl;
            cout << "Length of string 2: " << calculateLength(str2) << endl;
            break;
        case 5:
            convertToUppercase(str1);
            convertToUppercase(str2);
            cout << "Uppercase string 1: " << str1 << endl;
            cout << "Uppercase string 2: " << str2 << endl;
            break;
        case 6:
            reverseString(str1);
            reverseString(str2);
            cout << "Reversed string 1: " << str1 << endl;
            cout << "Reversed string 2: " << str2 << endl;
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
