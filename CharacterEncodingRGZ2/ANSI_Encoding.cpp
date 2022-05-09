#include "ANSI_Encoding.h"
#include <string>

ANSI_Encoding::ANSI_Encoding()
{
	additionalCharacters =
	{ {'А', 192}, {'Б', 193}, {'В', 194}, {'Г', 195}, {'Д', 196}, {'Е', 197}, 
	  {'Ж', 198}, {'З', 199}, {'И', 200}, {'Й', 201}, {'К', 202}, {'Л', 203}, {'М', 204}, {'Н', 205}, {'О', 206}, {'П', 207}, 
	  {'Р', 208}, {'С', 209}, {'Т', 210}, {'У', 211}, {'Ф', 212}, {'Х', 213}, {'Ц', 214}, {'Ч', 215}, {'Ш', 216}, {'Щ', 217}, 
	  {'Ъ', 218}, {'Ы', 219}, {'Ь', 220}, {'Э', 221}, {'Ю', 222}, {'Я', 223}, {'а', 224}, {'б', 225}, {'в', 226}, {'г', 227}, 
	  {'д', 228}, {'е', 229}, {'ж', 230}, {'з', 231}, {'и', 232}, {'й', 233}, {'к', 234}, {'л', 235}, {'м', 236}, {'н', 237}, 
	  {'о', 238}, {'п', 239}, {'р', 240}, {'с', 241}, {'т', 242}, {'у', 243}, {'ф', 244}, {'х', 245}, {'ц', 246}, {'ч', 247}, 
	  {'ш', 248}, {'щ', 249}, {'ъ', 250}, {'ы', 251}, {'ь', 252}, {'э', 253}, {'ю', 254}, {'я', 255}
	};
	
}

void ANSI_Encoding::EncodingHelp()
{
	// Info about ANSI
}

void ANSI_Encoding::MessageEncoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	for (int i = 0; i < message.length(); i++)
	{
		data.symbol = message[i];

		if(int(message[i] >= 0))
		{
			data.code = int(message[i]);
		}
		else
		{

			if(int(message[i]) + 16 > -17)
			{
				data.code = additionalCharacters[message[i] + 16];
			}
			else
			{
				data.code = additionalCharacters[message[i] + 64];
			}

		}

		symbolAndCode.push_back(data);
	}

}

void ANSI_Encoding::MessageDecoding(std::string message)
{
	symbolAndCode.clear();

	Data data;

	std::istringstream codeFlow(message);

	int n;

	while (codeFlow >> n)
	{
		data.code = n;

		if(n < 192)
		{
			data.symbol = char(n);
		}
		else
		{

			for(const auto& elem: additionalCharacters)
			{

				if(elem.second == n)
				{
					data.symbol = elem.first;
					break;
				}

			}

		}

		symbolAndCode.push_back(data);
	}

}

std::string ANSI_Encoding::GetEncodedMessage()
{

	std::string result;

	for (const auto& elem : symbolAndCode)
	{
		result += std::to_string(elem.code);
		result += " ";
	}

	return result;
}

std::string ANSI_Encoding::GetDecodedMessage()
{
	std::string result;

	for (const auto& elem : symbolAndCode)
	{
		result += elem.symbol;
	}

	return result;
}

void ANSI_Encoding::OutputToTheConsole()
{

	for (const auto& elem : symbolAndCode)
	{
		std::cout << elem.symbol << "     " << elem.code << std::endl;
	}

}
