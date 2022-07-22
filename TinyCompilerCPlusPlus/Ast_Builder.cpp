#include "Ast_Builder.hpp"

Ast_Builder::Ast_Builder()
{}
Ast_Builder::~Ast_Builder()
{}

AST* Ast_Builder::buildAST(std::string input)
{
	lexer = Lexer(&input);
	currentToken = lexer.get_token();
	tree = AST();
	treeRoot = new AST();
	arguments = vector<string>();
	if (currentToken.tokenType == Token::Error || currentToken.tokenType == Token::End)
		return nullptr; //empty input
	getListArguments(treeRoot);
	if (treeRoot->b == nullptr)
		return treeRoot->a;
	return treeRoot;
}
void Ast_Builder::getListArguments(AST*& root)
{
	if (currentToken.content == "[")
	{
		currentToken = lexer.get_token();
		while (currentToken.content != "]")
		{
			if (currentToken.tokenType == Token::Variable)
				arguments.push_back(currentToken.content);
			else
				return;
			currentToken = lexer.get_token();
		}
		currentToken = lexer.get_token();
	}
	add_sub(root);
}

void Ast_Builder::add_sub(AST*& root)
{
	mul_div(root);
	char oper;
	while ((oper = currentToken.content[0]) == '+' || oper == '-')
	{
		currentToken = lexer.get_token();
		AST* tmpRootPTR = new AST();
		mul_div(tmpRootPTR);
		switch (oper)
		{
		case '+':
		{
			root = root->add(tmpRootPTR, '+');
			break;
		}
		case '-':
		{
			root = root->add(tmpRootPTR, '-');
			break;
		}
		}
	}

}


void Ast_Builder::mul_div(AST*& root)
{
	char oper;
	unarMinus(root);
	while ((oper = currentToken.content[0]) == '*' || oper == '/')
	{
		AST* tmpRootPTR = new AST();
		currentToken = lexer.get_token();
		unarMinus(tmpRootPTR);
		switch (oper)
		{
		case '*':
		{
			root = root->add(tmpRootPTR, '*');
			break;
		}

		case '/':
		{
			root = root->add(tmpRootPTR, '/');
			break;
		}
		}
	}
}

void Ast_Builder::unarMinus(AST*& root)
{
	char oper = '0';
	if (currentToken.tokenType == Token::Delimiter &&
		(currentToken.content == "+" ||
			currentToken.content == "-"))
	{
		oper = currentToken.content[0];
		currentToken = lexer.get_token();
	}
	parentheses(root);
	if (oper == '-')
	{
		;//useless grammar do not support
	}

}
void Ast_Builder::parentheses(AST*& root)
{
	if (currentToken.content[0] == '(')
	{
		currentToken = lexer.get_token();
		add_sub(root);
		if (currentToken.content[0] != ')')
			;//error
		currentToken = lexer.get_token();
	}
	else
	{
		atom(root);
	}
}

void Ast_Builder::atom(AST*& root)
{
	switch (currentToken.tokenType)
	{
	case Token::Number:
		root = root->add("imm", std::stoi(currentToken.content));
		currentToken = lexer.get_token();
		break;
	case Token::Variable:
		root = root->add("arg", getArgumentNumber(currentToken.content));
		currentToken = lexer.get_token();
		break;
	default:
		break;//error
	}
}
int Ast_Builder::getArgumentNumber(std::string arggumentName)
{
	for (unsigned long i = 0; i < arguments.size(); i++)
	{
		if (arguments[i] == arggumentName)
			return i;
	}
	return -1;
}

