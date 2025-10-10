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
Jim PHP are going to use AST and not run-time oriented interpreter.
