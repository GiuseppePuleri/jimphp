/*
 * @context: This file rapresent the hearth of Lexer, Parser and Interpreter communication.
 * @problem: How can we can add rules or defined what is the token?
 * @solution: We will use Token like and object.
 * @impact: Is not necessary that Lexer knows Parser, we only need to include Token.hpp
 */

//pragma once its a preprocessor directive.
//It says to compiler that include this file only one time
//Its useful to avoid ridefinitions errors
#pragma once

#include <string>

struct Token {

    std::string type; //Is it a number or string?
    std::string value; //real value like "2", "=".    
    //obviusly this will be extended...
    
    // Construct that say token will accepter type and value (Token("NUMBER", number))
    Token(const std::string& t, const std::string& v)
        : type(t), value(v) {}

    // Default construct
    Token() = default;
};
