#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "CookieToastCompiler Version Negative Four" << endl;

    if (argc <= 1) {
        cout << "Usage: ctc <source file>" << endl;
        return -1;
    }

    vector<string> sourceCode;
    ifstream sourceFile(argv[1]);

    string l;
    while (std::getline(sourceFile, l))
    {
        sourceCode.push_back(l);
    }
    return 0;
}