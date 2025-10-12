/*
 * @context: This is the main file
 * @problem: Complexity of this page probably will increase
 * @solution: We will use constant complexity concept like O(1)
 * @impact: We want to only call function in this page withoud managing complecity
 */

#include <iostream>
#include "Lexer/Lexer.hpp"
//#include "Parser/Parser.hpp"
//#include "Interpreter/Interpreter.hpp"
using namespace std;

int main(){

    std::string php_code = "$hello_user = 5.5 + 10 * (3 - 1);  // test! @#|_\\\"";
   
    //Instantiate Lexer
    Lexer lexer(php_code);
    //Allocate a vector. Inside there are the token saved in dinamic array.
    //In this case compiler can add to vector in easy way new token (push_back).
    vector<Token> tokens = lexer.tokenize();
  
    //In alternative to vector, we can use auto and the compiler will use vector as type
    //auto tokens = lexer.tokenize();

    // Stampiamo i token
    cout << "Tokens:" << endl;
    for (const auto& t : tokens) {
        cout << "" << t.type << ": " << t.value << "" << endl;
    }

    /*
    //Instantiate Parser;
    Parser parser(tokens);
    auto ast = parser.parse();

    //Instantiate Interpreter;
    Interpreter interpreter;
    auto result = interpreter.execute(ast);

    cout << "Result: " << result << endl;
    */

    return 0;

}

