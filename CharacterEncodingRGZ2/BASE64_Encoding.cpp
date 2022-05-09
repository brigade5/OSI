#include "BASE64_Encoding.h"
#include <string>

BASE64_Encoding::BASE64_Encoding()
{
	base64Table =
	{ {'A',  0}, {'B',  1}, {'C',  2}, {'D',  3}, {'E',  4}, {'F',  5}, {'G',  6}, {'H',  7}, {'I',  8}, {'J',  9}, 
	  {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
	  {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29}, 
	  {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39},
	  {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49},
	  {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54}, {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59},
	  {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}
	};
}

void BASE64_Encoding::EncodingHelp()
{
	// Info about ANSI
}

void BASE64_Encoding::MessageEncoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	for (int i = 0; i < message.length(); i++)
	{
		data.symbol = message[i];
		data.code = base64Table[message[i]];
		symbolAndCode.push_back(data);
	}

}

void BASE64_Encoding::MessageDecoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	std::istringstream codeFlow(message);

	int n;

	while (codeFlow >> n)
	{
		data.code = n;

		for (const auto& elem : base64Table)
		{

			if (elem.second == n)
			{
				data.symbol = elem.first;
				break;
			}

		}

		symbolAndCode.push_back(data);
	}

}

std::string BASE64_Encoding::GetEncodedMessage()
{

	std::string result;

	for (const auto& elem : symbolAndCode)
	{
		result += std::to_string(elem.code);
		result += " ";
	}

	return result;
}

std::string BASE64_Encoding::GetDecodedMessage()
{
	std::string result;

	for (const auto& elem : symbolAndCode)
	{
		result += elem.symbol;
	}

	return result;
}

void BASE64_Encoding::OutputToTheConsole()
{

	for (const auto& elem : symbolAndCode)
	{
		std::cout << elem.symbol << "     " << elem.code << std::endl;
	}

}