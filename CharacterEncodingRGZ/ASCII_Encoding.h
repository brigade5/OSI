#pragma once
#ifndef ASCII_Encoding_h
#define ASCII_Encoding_h

#include "AbstractCharacterEncoding.h"


class ASCII_Encoding : protected AbstractCharacterEncoding
{
public:
	void EncodingHelp();

	void MessageEncoding(std::string message);
	void MessageDecoding(std::string message);

	std::string GetEncodedMessage();
	std::string GetDecodedMessage();

	void OutputToTheConsole();

};


#endif