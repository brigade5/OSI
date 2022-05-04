#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>
#include <vector>
#include "ASCII_Encoding.h"
#include <string>

using namespace std;

int main()
{
	string message;

	/*cout << "Vvedite soobshenie: ";
	getline(cin, message);

	ASCII_Encoding ascii;

	ascii.MessageEncoding(message);

	cout << endl << "Massiv 'symbolAndCode': " << endl;
	ascii.OutputToTheConsole();

	message = ascii.GetEncodedMessage();
	cout << endl << "Cod ASCII soobshenia: " << message;*/




	cout << "Vvedite cod(kajdoe chislo cherez probel): ";
	getline(cin, message);

	ASCII_Encoding ascii;

	ascii.MessageDecoding(message);

	cout << endl << "Massiv 'symbolAndCode': " << endl;
	ascii.OutputToTheConsole();

	message = ascii.GetDecodedMessage();
	cout << endl << "Decod ASCII soobshenia: " << message;
	
}