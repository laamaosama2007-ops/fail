
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("welcome.txt");
    outFile << "Hello Everybody";
    outFile.close();

    ifstream inFile("welcome.txt");
    string text;
    getline(inFile, text);
    inFile.close();

    size_t pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one");
    }

    ofstream finalFile("welcome.txt");
    finalFile << text;
    finalFile.close();

    return 0;
}
