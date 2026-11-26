
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter name and age: ";
        cin >> name >> age;
        outFile << name << " " << age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");
    vector<Person> persons;
    Person p;
    while (inFile >> p.name >> p.age) {
        persons.push_back(p);
    }
    inFile.close();

    if (!persons.empty()) {
        Person youngest = persons[0];
        Person oldest = persons[0];

        for (size_t i = 1; i < persons.size(); i++) {
            if (persons[i].age < youngest.age) {
                youngest = persons[i];
            }
            if (persons[i].age > oldest.age) {
                oldest = persons[i];
            }
        }

        ofstream resFile("results.txt");
        resFile << "Youngest: " << youngest.name << " (" << youngest.age << ")" << endl;
        resFile << "Oldest: " << oldest.name << " (" << oldest.age << ")" << endl;
        resFile.close();

        cout << "Youngest: " << youngest.name << " (" << youngest.age << ")" << endl;
        cout << "Oldest: " << oldest.name << " (" << oldest.age << ")" << endl;
    }

    return 0;
}
