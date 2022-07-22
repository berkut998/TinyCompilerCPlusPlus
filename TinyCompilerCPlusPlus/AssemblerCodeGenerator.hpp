#pragma once
#include <stack>
#include <vector>
#include <string>
#include "AST.hpp"

class ASM_Generator
{
private:
	static void generateAssemblerCode(std::vector<string>& result, AST* node);
	static void addDataToRegister(AST* node, vector<string>& result);
	static void createCodeForOperation(char operation, vector<string>& result);
public:
	static std::vector<std::string>  generateCode(AST* node);
	ASM_Generator();
	~ASM_Generator();
};


