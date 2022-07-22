#include "Lexer.hpp"
Lexer::Lexer(std::string* inputString)
{
	this->input = inputString;
}
Token Lexer::get_token()
{
	while (input->length() - 1 < currentPosition || isspace(input->at(currentPosition)))
	{
		if (currentPosition > input->length())
			return Token("", Token::End);
		currentPosition++;
	}
	if (isDelimiter(input->at(currentPosition)) == 1)
	{
		currentPosition++;
		return  Token(std::string(1, input->at(currentPosition - 1)), Token::Delimiter);

	}
	else if (isalpha(input->at(currentPosition)))
	{
		std::string variable;
		while (input->length() > currentPosition && std::isalpha(input->at(currentPosition)))
		{
			variable.push_back(input->at(currentPosition));
			currentPosition++;
		}
		return Token(variable, Token::Variable);

	}
	else if (isdigit(input->at(currentPosition)))
	{
		std::string number;
		while (input->length() > currentPosition && isdigit(input->at(currentPosition)))
		{
			number.push_back(input->at(currentPosition));
			currentPosition++;
		}
		return Token(number, Token::Number);

	}
	return Token("", Token::Error);
}

int Lexer::isDelimiter(char symbol)
{
	if (strchr("+-*/()[]", symbol) || symbol == 9 || symbol == '\r' || symbol == 0)
		return 1;
	return 0;
}


Lexer::~Lexer()
{

}
