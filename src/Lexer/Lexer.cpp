/*
 * @context: This is the scan engine that read php code and produce token
 * @problem: Thinking that the lexer should be used for management
 * @solution: Lexer has not management jobs. We have to think in deterministic way.
 * @impact: Reduces the risk of errors on special cases, such as numbers with multiple periods,  *          string concatenations, etc.
 */

#include "Lexer/Lexer.hpp"
#include "Token.hpp"
#include "cctype"
#include <iostream>

/* Jim PHP lexer will create token with Type and Value structure
 * So, Jim PHP categorize the tokens like this:
 * - Char Tokens: a-z A-Z and _ ($hello_hi, $my_var, my_function_name.)
 * - Num Tokens: 0-9
 * - Punct (Punctuation) Tokens: . , : ; 
 * - Oper (Operator) Tokens: + - * / = % ^
 * - Parent (Parenthesis) Tokens: ()[]{}
 * - Scahr (Special char) Tokens: ! @ # $ & ? < > \ | ' " and == != >= <= && ||
 */

//Instanciate the object
//Inizialize the internal member source_ with source (php code)
Lexer::Lexer(const std::string& source)
    : source_(source){} //source_ = source

//Tokenize core
std::vector<Token> Lexer::tokenize(){
    
    //Tokens will be stored here
    std::vector<Token> tokens;
    
    //Lexer index with type size_t.
    //Size_t is (unisgned int) better for indexes. Is more compatible with .size()
    size_t i = 0;

    //scan each letters
    while (i < source_.length()) {
       
        //each letter
        char c = source_[i];

        // Ignore spaces
        if (std::isspace(c)) {
            ++i;
            continue;
        }

        //if char create CHAR token
        if (std::isalpha(c) || c == '_') {
            std::string charStr;
            while (i < source_.length() && (std::isalnum(source_[i]) || source_[i] == '_')) {
                charStr += source_[i];
                ++i;
            }
            tokens.push_back(Token("CHAR", charStr));
            continue;
        }


        // if number creare NUMBER token
        // The double number like 2.0 will be managed in future
        // For now will be two tokens "2" and "0"
        if (std::isdigit(c)) {
            std::string number;
            while (i < source_.length() && std::isdigit(source_[i])) {
                number += source_[i];
                ++i;
            }
            tokens.push_back(Token("NUM", number));
            continue;
        }

        //if punctations creare PUNCT number
        if (c == '.' || c == ',' || c == ';' || c == ':') {
            std::string punct(1, c);
            tokens.push_back(Token("PUNCT", punct));
        
            ++i;
            continue;
        }


        // if operator create OPERATOR token
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '=') {
            std::string op(1, c); // conver char in string
            tokens.push_back(Token("OPER", op));
            ++i;
            continue;
        }

        // if parenthesis create different type for better identify
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
            std::string paren(1, c);
            std::string type;

            if (c == '(') type = "LPAREN";
            else if (c == ')') type = "RPAREN";
            else if (c == '[') type = "LBRACKET";
            else if (c == ']') type = "RBRACKET";
            else if (c == '{') type = "LBRACE";
            else if (c == '}') type = "RBRACE";

            tokens.push_back(Token(type, paren));
            ++i;
            continue;
        }

        // If special two-char use SCHAR
        if (i + 1 < source_.length()) {
            std::string twoChars = source_.substr(i, 2);
            if (twoChars == "==" || twoChars == "!=" || twoChars == ">=" || 
                twoChars == "<=" || twoChars == "&&" || twoChars == "||" || 
                twoChars == "=>" || twoChars == "::") {
                tokens.push_back(Token("SCHAR", twoChars));
                i += 2;
                continue;
            }
        }       

        //If special character use SCHAR
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '&' ||
            c == '?' || c == '<' || c == '>' || c == '\\' ||
            c == '|' || c == '"' || c == '\'') {
            tokens.push_back(Token("SCHAR", std::string(1, c)));
            ++i;
            continue;
        }
 

        // Error
        std::cerr << "Unknown character: " << c << std::endl;
        ++i;
    }

    return tokens;

}


