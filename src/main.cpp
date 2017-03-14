#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "lexer/ctc_lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "CookieToastCompiler Version Negative Four" << endl;

    if (argc <= 1) {
        cout << "Usage: ctc <source file>" << endl;
        return -1;
    }

    ifstream sourceFile(argv[1]);

    string source_code = "";
    string l;
    while (std::getline(sourceFile, l))
    {
        source_code += l + "\n";
    }

    CTCLexer lexer(source_code);
    lexer.tokenize_source();

    return 0;
}