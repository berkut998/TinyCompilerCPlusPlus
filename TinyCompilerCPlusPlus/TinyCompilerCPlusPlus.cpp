#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Ast_Builder.hpp"
#include "Ast_Reducer.hpp"
#include "AssemblerCodeGenerator.hpp"
#include "Simulator.hpp"

int main()
{

	std::cout << "input an expression \n";
	std::string input;
	getline(cin, input);

	std::cout << "input argument value \n";
	std::string argumentsStr;
	getline(cin, argumentsStr);
	vector<int> arguments;
	std::string tmpStr;
	for (unsigned long i = 0; i < argumentsStr.size(); i++)
	{
		if (!tmpStr.empty() && (argumentsStr[i] == ' ' || argumentsStr[i] == '\n'))
		{
			arguments.push_back(std::stoi(tmpStr));
			tmpStr.clear();
			continue;
		}
		tmpStr.push_back(argumentsStr[i]);
		if (i == argumentsStr.size() - 1 && !tmpStr.empty())
			arguments.push_back(std::stoi(tmpStr));
	}


	Ast_Builder astBuilder = Ast_Builder();
	AST* rootTree = astBuilder.buildAST("[ x y z ] ( 2*3*x + 5*y - 3*z ) / (1 + 3 + 2*2)"); //"[ x y z ] ( 2*3*x + 5*y - 3*z ) / (1 + 3 + 2*2)"
	AST* reducedTree = Ast_Reducer::reducAst(rootTree);
	vector<string> result3 = ASM_Generator::generateCode(reducedTree);

	int calculationResult = Simulator::simulate(result3, arguments);
	std::cout << "Result:" << "\n";
	std::cout << calculationResult << "\n";
	std::cout << "Assembler code: \n";
	for (unsigned long i = 0; i < result3.size(); i++)
	{
		std::cout << result3[i] << "\n";
	}
	std::cin >> argumentsStr;
}
