#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Token.hpp"
using namespace std;

class Lexer
{
public:
	Token get_token();
	Lexer(std::string* inputString);
	Lexer() = default;
	~Lexer();
private:
	std::string* input;
	int isDelimiter(char symbol);
	unsigned long currentPosition = 0;

};