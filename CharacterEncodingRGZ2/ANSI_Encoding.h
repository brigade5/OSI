#pragma once
#ifndef ANSI_Encoding_h
#define ANSI_Encoding_h

#include "AbstractCharacterEncoding.h"
#include <map>

class ANSI_Encoding : protected AbstractCharacterEncoding
{
private:
	std::map<char, int> additionalCharacters;

public:
	ANSI_Encoding();

	void EncodingHelp();

	void MessageEncoding(std::string message);
	void MessageDecoding(std::string message);

	std::string GetEncodedMessage();
	std::string GetDecodedMessage();

	void OutputToTheConsole();

};


#endif