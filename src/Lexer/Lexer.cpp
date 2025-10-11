/*
 * @context: This is the scan engine that read php code and produce token
 * @problem: Performance and speed may increase
 * @solution:
 * @impact:
 */

#include "Lexer/Lexer.hpp"
#include "Token.hpp"
#include "cctype" //isdigit();
#include <iostream>

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

        // if number creare NUMBER token
        if (std::isdigit(c)) {
            std::string number;
            while (i < source_.length() && std::isdigit(source_[i])) {
                number += source_[i];
                ++i;
            }
            tokens.push_back(Token("NUMBER", number));
            continue;
        }

        // if operator create OPERATOR token
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            std::string op(1, c); // converte il char in stringa
            tokens.push_back(Token("OPERATOR", op));
            ++i;
            continue;
        }

        // Error
        std::cerr << "Unknown character: " << c << std::endl;
        ++i;
    }

    return tokens;

}


