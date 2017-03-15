#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "lexer/CTCLexer.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    cout << "CookieToastCompiler Version Negative Four" << endl;

    if (argc <= 1) {
        cout << "Usage: ctc <source file>" << endl;
        return -1;
    }

    std::ifstream sourceFile(argv[1]);

    std::string source_code = "";
    std::string l;
    while (std::getline(sourceFile, l))
    {
        source_code += l + "\n";
    }

    CTCLexer lexer(source_code);
    auto tokens = lexer.tokenize_source();

    return 0;
}
