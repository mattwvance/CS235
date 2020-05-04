#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    // cout << "Hello world" << endl;
    cout << "Reading file" << endl;
    if (argc != 2) {
        cout << "please provide a file name" << endl;
    } else {
        ifstream fileHandle(argv[1]);
        if (!fileHandle.is_open()) {
            cout << "could not open file" << endl;
        } else {
            vector<string> lines;
            string line;
            while(fileHandle >> line) {
                lines.push_back(line);
            }
            cout << lines.size() << ": " << lines[0] << endl;
        }
    }
}