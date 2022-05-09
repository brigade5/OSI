#include "ANSI_Encoding.h"
#include <string>

ANSI_Encoding::ANSI_Encoding()
{
	additionalCharacters =
	{ {'�', 192}, {'�', 193}, {'�', 194}, {'�', 195}, {'�', 196}, {'�', 197}, 
	  {'�', 198}, {'�', 199}, {'�', 200}, {'�', 201}, {'�', 202}, {'�', 203}, {'�', 204}, {'�', 205}, {'�', 206}, {'�', 207}, 
	  {'�', 208}, {'�', 209}, {'�', 210}, {'�', 211}, {'�', 212}, {'�', 213}, {'�', 214}, {'�', 215}, {'�', 216}, {'�', 217}, 
	  {'�', 218}, {'�', 219}, {'�', 220}, {'�', 221}, {'�', 222}, {'�', 223}, {'�', 224}, {'�', 225}, {'�', 226}, {'�', 227}, 
	  {'�', 228}, {'�', 229}, {'�', 230}, {'�', 231}, {'�', 232}, {'�', 233}, {'�', 234}, {'�', 235}, {'�', 236}, {'�', 237}, 
	  {'�', 238}, {'�', 239}, {'�', 240}, {'�', 241}, {'�', 242}, {'�', 243}, {'�', 244}, {'�', 245}, {'�', 246}, {'�', 247}, 
	  {'�', 248}, {'�', 249}, {'�', 250}, {'�', 251}, {'�', 252}, {'�', 253}, {'�', 254}, {'�', 255}
	};

	/*{'�', 128}, { '�', 129 }, { '�', 130 }, { '�', 131 }, { '�', 132 }, { '�', 133 }, { '�', 134 }, { '�', 135 }, { '�', 136 }, { '�', 137 },
	{ '�', 138 }, { '�', 139 }, { '�', 140 }, { '�', 141 }, { '�', 142 }, { '�', 143 }, { '�', 144 }, { '�', 145 }, { '�', 146 }, { '�', 147 },
	{ '�', 148 }, { '�', 149 }, { '�', 150 }, { '�', 151 }, { '\0', 152 }, { '�', 153 }, { '�', 154 }, { '�', 155 }, { '�', 156 }, { '�', 157 },
	{ '�', 158 }, { '�', 159 }, { '�', 160 }, { '�', 161 }, { '�', 162 }, { '�', 163 }, { '�', 164 }, { '�', 165 }, { '�', 166 }, { '�', 167 },
	{ '�', 168 }, { '�', 169 }, { '�', 170 }, { '�', 171 }, { '�', 172 }, { ' ', 173 }, { '�', 174 }, { '�', 175 }, { '�', 176 }, { '�', 177 },
	{ '�', 178 }, { '�', 179 }, { '�', 180 }, { '�', 181 }, { '�', 182 }, { '�', 183 }, { '�', 184 }, { '�', 185 }, { '�', 186 }, { '�', 187 },
	{ '�', 188 }, { '�', 189 }, { '�', 190 }, { '�', 191 },*/
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