#pragma once
#include "AST.hpp"
#include<string.h>

class Ast_Reducer
{
private:

	static int calculate(int a, int b, char operation);
	static void reduce(AST*& node);
public:
	Ast_Reducer();
	~Ast_Reducer();
	static AST* reducAst(AST* root);
};


