#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("fruit.txt");
    outFile << "Apple\n";
    outFile << "Orange\n";
    outFile << "Banana\n";
    outFile.close();

    ifstream inFile("fruit.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream appendFile("fruit.txt", ios::app);
    appendFile << "Fresh Fruits\n";
    appendFile.close();

    return 0;
}
