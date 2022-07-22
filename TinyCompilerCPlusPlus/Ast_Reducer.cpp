#include"Ast_Reducer.hpp"


Ast_Reducer::Ast_Reducer()
{
}

Ast_Reducer::~Ast_Reducer()
{
}

AST* Ast_Reducer::reducAst(AST* root)
{
	reduce(root);
	return root;
}

void Ast_Reducer::reduce(AST*& node)
{
	if (node->a == nullptr || node->b == nullptr)
		return;
	reduce(node->a);
	reduce(node->b);
	if (node->a->op == "imm" && node->b->op == "imm")
	{
		int result = calculate(node->a->n, node->b->n, node->op.at(0));
		delete  node->a;
		delete  node->b;
		node->a = nullptr;
		node->b = nullptr;
		node->n = result;
		node->op = "imm";
	}

}

int Ast_Reducer::calculate(int a, int b, char operation)
{
	switch (operation)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		break;
	}
	return 0;
}