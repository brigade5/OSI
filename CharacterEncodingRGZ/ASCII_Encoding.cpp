#include "ASCII_Encoding.h"

void ASCII_Encoding::EncodingHelp()
{
	// Info about ASCII
}

void ASCII_Encoding::MessageEncoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	for(int i = 0; i < message.length(); i++)
	{
		data.symbol = message[i];
		data.code = int(message[i]);
		symbolAndCode.push_back(data);
	}

}

void ASCII_Encoding::MessageDecoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	std::istringstream codeFlow(message);

	int n;

	while(codeFlow >> n) 
	{
		data.code = n;
		data.symbol = char(n);
		symbolAndCode.push_back(data);
	}

}

std::string ASCII_Encoding::GetEncodedMessage()
{

	std::string result;

	for(const auto& elem: symbolAndCode)
	{
		result += std::to_string(elem.code);
		result += " ";
	}

	return result;
}

std::string ASCII_Encoding::GetDecodedMessage()
{
	std::string result;

	for (const auto& elem : symbolAndCode)
	{
		result += elem.symbol;
	}

	return result;
}

void ASCII_Encoding::OutputToTheConsole()
{

	for (const auto& elem : symbolAndCode)
	{
		std::cout << elem.symbol << "     " << elem.code << std::endl;
	}

}