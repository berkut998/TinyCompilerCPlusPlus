#include "AssemblerCodeGenerator.hpp"
static int stackCount;
ASM_Generator::ASM_Generator()
{
}

ASM_Generator::~ASM_Generator()
{
}

vector<std::string> ASM_Generator::generateCode(AST* node)
{
	stackCount = 0;
	vector<std::string> result;
	generateAssemblerCode(result, node);
	if (result.size() == 0)
	{
		result.push_back("IM" + std::to_string(node->n));
	}
	return result;
}

void ASM_Generator::generateAssemblerCode(std::vector<string>& result, AST* node)
{
	if (node->a == nullptr || node->b == nullptr)
		return;
	generateAssemblerCode(result, node->a);
	generateAssemblerCode(result, node->b);
	addDataToRegister(node->b, result);
	result.push_back("SW");
	addDataToRegister(node->a, result);
	createCodeForOperation(node->op.at(0), result);
}

void ASM_Generator::addDataToRegister(AST* node, vector<string>& result)
{
	if (node->op == "arg")
	{
		result.push_back("AR " + to_string(node->n));
	}
	else if (node->op == "imm")
	{
		result.push_back("IM " + to_string(node->n));
	}
	else if (stackCount > 0)
	{
		result.push_back("PO");
	}
}

void ASM_Generator::createCodeForOperation(char operation, vector<string>& result)
{
	switch (operation)
	{
	case '+':
		result.push_back("AD");
		break;
	case '-':
		result.push_back("SU");
		break;
	case '*':
		result.push_back("MU");
		break;
	case '/':
		result.push_back("DI");
		break;
	default:
		break;
	}
	result.push_back("PU");
	stackCount++;
}