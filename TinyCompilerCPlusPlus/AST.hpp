#pragma once
#include <iostream>

using namespace std;

struct AST
{
public:
	AST* a;
	AST* b;
	std::string op;
	int n;
	AST()
	{
		a = nullptr;
		b = nullptr;
	}
	AST(string op, AST* a, AST* b)
	{
		this->op = op;
		this->a = a;
		this->b = b;
	}

	AST(string op, int n)
	{
		this->op = op;
		this->n = n;
	}
	AST* add(std::string content, int value)
	{
		AST* tmpTree = new AST();

		if (a == nullptr)
		{
			tmpTree->op = content;
			tmpTree->n = value;
			a = tmpTree;
		}
		else if (b == nullptr)
		{
			tmpTree->op = content;
			tmpTree->n = value;
			b = tmpTree;
		}
		else
		{
			tmpTree->a = this;
			tmpTree->b = new AST();
			tmpTree->b->op = content;
			tmpTree->b->n = value;
			return tmpTree;

		}
		return this;
	}
	AST* add(AST* secondTree, char symbol)
	{
		AST* tmpTree = new AST();
		if (secondTree->b == nullptr)
			secondTree = secondTree->a;
		if (this->op.empty())
		{
			this->b = secondTree;
			this->op.push_back(symbol);
		}

		else if (this->a == nullptr)
		{
			this->a = secondTree;
			this->op.push_back(symbol);
		}
		else if (this->b == nullptr)
		{
			this->b = secondTree;
			this->op.push_back(symbol);

		}
		else
		{
			tmpTree->a = this;
			tmpTree->b = secondTree;
			tmpTree->op.push_back(symbol);
			return tmpTree;
		}
		return this;
	}

	std::string NLR(AST* node, std::string& result)
	{
		if (node == nullptr)
		{
			return result;
		}
		if (!node->op.empty())
			result.append(node->op);
		NLR(node->a, result);
		NLR(node->b, result);
		return result;
	}
};





