#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);
    char name[20];
    int id;
    float grade;
    char delim = '$';
    char choice;

    do {
        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        outFile << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add more records? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    return 0;
}
