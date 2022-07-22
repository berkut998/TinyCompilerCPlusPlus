#pragma once
#include <iostream>
#include "AST.hpp"
#include "Lexer.hpp"
#include <vector>
#include <string>

class Ast_Builder
{
private:
	std::vector<std::string> arguments;
	Token currentToken;
	Lexer lexer;
	AST tree;
	AST* treeRoot;;
	void getListArguments(AST*& root);
	void add_sub(AST*& root);
	void mul_div(AST*& root);
	void unarMinus(AST*& root);
	void parentheses(AST*& root);
	void atom(AST*& root);
	int getArgumentNumber(std::string argumentName);


public:
	Ast_Builder();
	~Ast_Builder();
	AST* buildAST(std::string input);


};


