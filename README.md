```
The PHP Interpreter
A small-footprint implementation of the PHP programming language.

----------------------------------------------------------
        Jim PHP  
----------------------------------------------------------
The main goal of Jim PHP is to improve my skills in:
Git for repository management
The PHP language, also from a low-level perspective
C++ language and OOP concepts

----------------------------------------------------------
        Architecture  
----------------------------------------------------------
The Jim PHP architecture is divided into three levels.
Each level behaves like an object, and these three objects communicate
with each other.

LEXER - Splits the source code into tokens
PARSER - Builds the AST (Abstract Syntax Tree) from the tokens
INTERPRETER - Analyzes the AST and executes its nodes

----------------------------------------------------------
        Other Details  
----------------------------------------------------------
This project is inspired by Jim Tcl by Salvatore Sanfilippo.
Jim PHP follows a different approach in its architecture.
The Lexer (Tokenizer) follows a similar philosophy, but the Parser and Interpreter
are based on different ideas.

Note: Jim PHP uses an AST-based interpreter, not a run-time oriented one like Jim Tcl.

----------------------------------------------------------
        Daily Goal  
----------------------------------------------------------
[DONE] DAY ZERO
Set up Git and GitHub. Studied the general architecture.
Wrote the README file and the CMakeLists.txt.
Understood the basic structure and goals.

[DONE] DAY ONE
Started studying how PHP code could be executed.
Jim PHP can run code in three ways, similar to Jim Tcl:
- Inline string: std::string php_code = "1+1;"; (for testing only)
- Command line: jimphp -r 'echo 1+1;'
- File execution: jimphp sum.php

Note: To execute shell commands, Jim PHP uses jimphp, while Jim Tcl uses jimsh.

Worked on inline string execution and Lexer implementation with a token structure.
We need tokens because the Parser will operate on individual tokens.
Lexer.cpp can now tokenize expressions — "1+1" becomes "1", "+", "1".

[DONE] DAY TWO
Started fixing issues in Lexer.cpp.
Issue #1:
If you hardcode a PHP expression like:
std::string php_code = "(10.2+0.5*(2-0.4))2+(2.14)";
the Lexer would return "Unknown character" because it didn’t yet recognize
symbols like ), {, * and so on.

Yesterday, Jim PHP was tested only with simple expressions like "1+1".
Obviously, that’s not acceptable. We needed a better Lexer that can
tokenize code more accurately and recognize symbols properly.

Jim PHP now implements these category for token structures:
-Char Tokens: a-z A-Z and _
-Num Tokens: 0-9
-Punct (Punctuation) Tokens: . , : ;
-Oper (Operator) Tokens: + - * / = % ^
-Parent (Parenthesis) Tokens: ()[]{}
-SChar (Special char) Tokens: ! @ # $ & ? < > \ | ' " and == != >= <= && ||

In this way we can write more complex PHP expressions like:
std::string php_code = "$hello = 5.5 + 10 * (3 - 1); // test! @#|_\";

Result:
SCHAR: $ | CHAR: hello_user | OPER: = | NUM: 5 | PUNCT: . | NUM: 5 | OPER: + | NUM: 10 | OPER: * | LPAREN: ( | NUM: 3 | OPER: - | NUM: 1 | RPAREN: ) | PUNCT: ; | OPER: / | OPER: / | CHAR: test | SCHAR: ! | SCHAR: @ | SCHAR: # | SCHAR: | | CHAR: _ | SCHAR: \ | SCHAR: "

----------------------------------------------------------
        File and Folder Structure
----------------------------------------------------------
jimphp/
├── CMakeLists.txt
├── README.md
├── examples/
│ ├── hello.php
│ ├── math.php
│ └── if_else.php
├── include/
│ ├── Token.hpp
│ ├── ASTNode.hpp
│ ├── Value.hpp
│ ├── SymbolTable.hpp
│ ├── Lexer/
│ │ └── Lexer.hpp
│ ├── Parser/
│ │ └── Parser.hpp
│ └── Interpreter/
│ └── Interpreter.hpp
├── src/
│ ├── main.cpp
│ ├── Lexer/
│ │ └── Lexer.cpp
│ ├── Parser/
│ │ └── Parser.cpp
│ └── Interpreter/
│ └── Interpreter.cpp
└── tests/
├── lexer_test.cpp
├── parser_test.cpp
└── interpreter_test.cpp
```
