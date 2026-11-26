#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("Students.txt");
    outFile << "Ali Ahmed\n";
    outFile << "Mohamed Rady\n";
    outFile << "Youssef Zaki\n";
    outFile.close();

    ifstream inFile("Students.txt");
    ofstream temp("temp.txt");
    int c_line = 1;
    string text;

    while (getline(inFile, text)) {
        if (c_line != 1) {
            temp << text << endl;
        }
        c_line++;
    }

    inFile.close();
    temp.close();

    remove("Students.txt");
    rename("temp.txt", "Students.txt");

    return 0;
}
