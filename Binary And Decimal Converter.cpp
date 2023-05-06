// Binary And Decimal Converter.cpp : Defines the entry point for the application.
//

#include "Binary And Decimal Converter.h"
using namespace std; //Use Standart Namespace	


int main() //Run On Execute		
{
	setColor("white");
	string mode;
	cout << "\nEnter Mode : ";
	getline(cin, mode);
	if (noSpace(lower(mode)) == "dectobin")
	{
		setColor("green");
		int dec;
		cout << "\nEnter Decimal Number : ";
		cin >> dec;
		vector<int> bin = decToBin(dec);
		size_t size = bin.size();
		cout << "\nBinary : ";
		for (size_t i = 0; i < size; i++)
		{
			cout << bin[i];
		}
		Sleep(500);
	}
	else if (noSpace(lower(mode)) == "bintodec")
	{
		setColor("green");
		string bin;
		cout << "\nEnter Binary : ";
		getline(cin, bin);

		cout << "\nDecimal : ";
		cout << binToDec(bin);
		Sleep(500);
	}
	else
	{
		setColor("red");
		cout << "\nAcces Denied : ";
		cout << "Unavailable Mode.";
		setColor("white");
		Sleep(500);
		abort();
	}
	Sleep(500);
	setColor("white");
	return 0;
}