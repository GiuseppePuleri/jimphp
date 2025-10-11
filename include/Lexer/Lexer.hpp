/*
 * @context: This file contains only the Lexer interface
 * @problem: 
 * @solution:
 * @impact: We split interface and implementations
 */

//include only one time
#pragma once
#include <string>
#include <vector>
#include "../Token.hpp" //Token structure

class Lexer {

    public:
        //costruct that will riceve source code
        //use explicit to avoid background compiler conversion
        //call by reference, so read source withut copying
        explicit Lexer(const std::string& source);

        //Main function for return all token
        std::vector<Token> tokenize();

    private:
        //source code string
        //we use private because its impossible in other parts of code broke the string and lexer
        //Only here source string could be managed
        //Inside source_ there is a php code copy passed in private member
        std::string source_;

};
