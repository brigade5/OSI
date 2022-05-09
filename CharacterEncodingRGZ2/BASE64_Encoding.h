#pragma once
#ifndef BASE64_Encoding_h
#define BASE64_Encoding_h

#include "AbstractCharacterEncoding.h"
#include <map>

class BASE64_Encoding : protected AbstractCharacterEncoding
{
private:
	std::map<char, int> base64Table;

public:
	BASE64_Encoding();

	void EncodingHelp();

	void MessageEncoding(std::string message);
	void MessageDecoding(std::string message);

	std::string GetEncodedMessage();
	std::string GetDecodedMessage();

	void OutputToTheConsole();
};


#endif