#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "lexer/CTCLexer.h"
#include "parser/Parser.h"
#include "preprocessor/Preprocessor.h"
#include "optimizer/PreOptimizer.h"
#include "emit/SyntaxTreeLinearizer.h"

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

    cout << "source file: " << argv[1] << endl;

    std::ifstream sourceFile(argv[1]);

    std::string source_code = "";
    std::string l;
    while (std::getline(sourceFile, l))
    {
        source_code += l;
        source_code += '\n';
    }

    Preprocessor preprocessor(source_code);
    source_code = preprocessor.preprocess_source();

    CTCLexer lexer(source_code);
    std::vector<Token> tokens = lexer.tokenize_source();

    Parser parser(tokens);
    std::shared_ptr<ProgramNode> program_ast = parser.parse_to_ast();

    PreOptimizer pre_optimizer(program_ast.get());
    pre_optimizer.optimize_syntax_tree();

    CodeEmitter emitter(InstructionSet::TI_Z80, program_ast);
    SyntaxTreeLinearizer linearizer(emitter);

    return 0;
}
