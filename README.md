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

Note: Jim PHP uses an AST-based interpreter, not a run-time oriented like Jim Tcl.

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

Yesterday (day one), Jim PHP was tested only with simple expressions like "1+1".
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
SCHAR: $ | CHAR: hello_user | OPER: = | NUM: 5 | PUNCT: . | NUM: 5 | OPER: + |
NUM: 10 | OPER: * | LPAREN: ( | NUM: 3 | OPER: - | NUM: 1 | RPAREN: ) |
PUNCT: ; | OPER: / | OPER: / | CHAR: test | SCHAR: ! | SCHAR: @ | SCHAR: # | 
SCHAR: | | CHAR: _ | SCHAR: \ | SCHAR: "
At this point the Lexer can reconize complex PHP expression.

[DONE] DAY THREE
Today we need to understand how these tokens will be handled in order to
build the AST (Abstract Syntax Tree).
We are now inside the parser stage. After the lexer, the next step is to
build the AST from the generated tokens.

My first question was: what is an Abstract Syntax Tree?
In very simple terms, conceptually, it is like a contract between the human
writing the code and the way that code must be organized and cleaned before
being translated into machine language.
You could also think of this contract as if you were explaining to a child
that operators such as +, -, and others have a specific order of importance.

For example, division has priority first, then multiplication, then
subtraction and addition.
Let's take this expression: 3 + 5 * 2
The tree must first clean the expression by removing unnecessary spaces, and
then represent the operation like this:

First, perform the addition:              +
                                         / \
You need 3 and the the multiplication:  3   *
                                           / \
The multiplication is between:            5   2

Once I understood the general idea behind an AST, I started wondering if ther
e are written and documented rules that an AST must follow, and the answer is yes.

The rules an AST follows are defined by each individual programming language.
- C++ follows the ISO C++ specification.
- Java follows Oracle's official specification.
- PHP follows the PHP Language Specification.

These documents define the grammar of the language, and the AST must be consistent
with that grammar.
Note: Out of curiosity, I also looked into what happens after the AST is
created, and I found two common approaches.
There are languages where the AST is executed directly.
Then there are other languages where the AST is used as a blueprint to generate
bytecode.
In simple terms, bytecode is still a low-level and compact intermediate form of
code that will later be transformed into machine language.
Example 1:
- Lexer, Parser (AST construction), Interpreter (AST execution)
Example 2:
- Lexer, Parser (AST construction), Bytecode generation (intermediate code),
Interpreter (bytecode execution)
As you can see, in the second example an intermediate representation is generated.
The advantages are that bytecode can be shared, is portable across different
environments, and can later be compiled into machine code optimized for the exact
specifications of the target environment.
In contrast, the first approach does not allow you to share an intermediate
representation, and the AST itself cannot be shared either because it is not
portable code. It is only a structural representation.

In my case, generating bytecode would be overkill.
Before writing any code, I believe it is extremely important to spend time, even
a lot of time if necessary, writing proper documentation in order to build solid
foundations on which the architecture of any program can be developed.
At this point, we need to get practical.
We know that an interpreter generally follows 3 or 4 major stages, but what
exactly do we want to allow?
I mean, should our interpreter support if statements, loops such as while or
do-while, arrays?
At the beginning, I want to focus only on the basics.

Here is the initial list:
Variables ($a)
Integer (10)
Float (5.5)
Binary operators (+ - * /)
Assignment
Parentheses
Instructions (echo)

To formally describe these rules and structures, a syntax called EBNF is commonly used.
On day four you will find the EBNF syntax for Jim PHP inside /docs/jim_php_v1.ebnf.


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
