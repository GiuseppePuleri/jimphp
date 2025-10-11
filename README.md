The PHP Interpreter
A small-footprint implementation of the PHP programming language.

--------------------------------------------------------------------------------
            Jim PHP
--------------------------------------------------------------------------------
Tha main goal of Jim PHP is improve my skills in:
- Git for repository managmen
- PHP language also in low level
- CPP language and OOP


--------------------------------------------------------------------------------
            Architecture
--------------------------------------------------------------------------------
The Jim PHP architecture is divided in 5 level.
Each level will be like an object.
This 5 object will talk to each other.
1) LEXER. Will split the source code in token
2) PARSER. Will build the AST from the token
3) INTERPRETER. Will analyze the AST and execude the node

-------------------------------------------------------------------------------
            Other Details
-------------------------------------------------------------------------------
This project is inspired from Jim TCL by Salvatore Sanfilippo.
Jim PHP follow different approach in the architecture.
Lexer (Tokenizer) follow the same philosophy but Parser and Interpreter
will follow different ideas.
Note: Jim PHP are going to use AST and not run-time oriented interpreter like Jim TCL.

-------------------------------------------------------------------------------
            Daily Goal
-------------------------------------------------------------------------------
[DONE] DAY ZERO
Set up git and Github and general architecture's studying.
Wrote the readme file and cMakeLists.txt setup.
Understand the day after day jobs.

DAY ONE
Starting to studing how the php code could be executed.
Jim PHP can run the code in 3 ways like Jim TCL:
1) String hardcoded / inline [std::string code = "1+1";]. (Only for testing)
2) Command Line like also php [jimphp -r 'echo 1+1;']
3) File jimphp sum.php
Note: To execute shell commands, Jim PHP uses [jimphp], unlike Jim Tcl uses [jimsh].
Starting with

-------------------------------------------------------------------------------
            File and Folder Structure
-------------------------------------------------------------------------------
jimphp/
├── CMakeLists.txt
├── README.md
├── examples/
│   ├── hello.php
│   ├── math.php
│   └── if_else.php
├── include/
│   ├── Token.hpp
│   ├── ASTNode.hpp
│   ├── Value.hpp
│   ├── SymbolTable.hpp
│   ├── Lexer/
│   │   └── Lexer.hpp
│   ├── Parser/
│   │   └── Parser.hpp
│   └── Interpreter/
│       └── Interpreter.hpp
├── src/
│   ├── main.cpp
│   ├── Lexer/
│   │   └── Lexer.cpp
│   ├── Parser/
│   │   └── Parser.cpp
│   └── Interpreter/
│       └── Interpreter.cpp
└── tests/
    ├── lexer_test.cpp
    ├── parser_test.cpp
    └── interpreter_test.cpp

