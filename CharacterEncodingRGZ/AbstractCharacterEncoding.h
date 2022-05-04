#pragma once
#ifndef AbstractCharacterEncoding_h
#define AbstractCharacterEncoding_h

#include <vector>
#include <iostream>
#include <sstream>

class AbstractCharacterEncoding
{
protected:
	struct Data
	{
		char symbol;
		int code;
	};

	// Massiv xranit posimvolno poslednee poluchenoe na vxod soobshenie i ego cod
	std::vector<Data> symbolAndCode;

public:
	// Spravka
	virtual void EncodingHelp() = 0;

	// Zacodirovatb i Decodirovatb soobshenie
	virtual void MessageEncoding(std::string message) = 0;
	virtual void MessageDecoding(std::string message) = 0;

	// Poluchitb codirovanoe i decodirovanoe soobshenie
	virtual std::string GetEncodedMessage() = 0;
	virtual std::string GetDecodedMessage() = 0;

};

#endif