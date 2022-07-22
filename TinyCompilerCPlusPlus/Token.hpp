#pragma once
#include <iostream>

struct Token
{

public:
	enum token_type
	{
		Variable,
		Number,
		Delimiter,
		Error,
		End
	};
	std::string content;
	token_type tokenType;
	Token(std::string _content, token_type typeOfToken)
	{
		content = _content;
		tokenType = typeOfToken;
	}
	Token()
	{
		content = "";
		tokenType = Token::Error;
	}

};