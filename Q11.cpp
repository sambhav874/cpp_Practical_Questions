//Copy the contents of one text file to another file, after removing all whitespaces. 

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    string inputFile, outputFile;
    cout << "Enter the input file name: ";
    cin >> inputFile;
    cout << "Enter the output file name: ";
    cin >> outputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Failed to create output file." << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        if (!isspace(ch)) {
            outFile.put(ch);
        }
    }

    inFile.close();
    outFile.close();

    cout << "File copy with whitespaces removed successfully." << std::endl;

    return 0;
}
