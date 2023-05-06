#pragma once

//Libraries Used
#include <iostream> //Input/Output Stream For Console
#include <string>   //For String
#include <fstream>  //File Stream 
#include <vector>   //Changable Index Structure
#include <Windows.h>//For System Commands
#include <algorithm>//Easy Sorting For Arrays/Vectors ...
#include <iomanip>  //For Outputting With Given Precision
#include <cmath>    //Easy Math Functions
#include <stdio.h>  //Standart Input/Output For Given Types
#include <conio.h>  //For Getting Key Presses
#include <filesystem>
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <chrono>
#include <regex>
#include <thread>

using namespace std;//Standart Namespace



//Set Text Color For Console
void setColor(string color)
{
	HANDLE col;
	col = GetStdHandle(STD_OUTPUT_HANDLE); //Command Will Be Used
	int col_code = 7; //Default White Code
	//Check Colors
	if (color == "blue")
	{
		col_code = 1;
	}
	else if (color == "green")
	{
		col_code = 2;
	}
	else if (color == "cyan")
	{
		col_code = 3;
	}
	else if (color == "red")
	{
		col_code = 4;
	}
	else if (color == "purple")
	{
		col_code = 5;
	}
	else if (color == "darkYellow")
	{
		col_code = 6;
	}
	else if (color == "white")
	{
		col_code = 7;
	}
	else if (color == "grey")
	{
		col_code = 8;
	}
	else if (color == "brightBlue")
	{
		col_code = 9;
	}
	else if (color == "brightGreen")
	{
		col_code = 10;
	}
	else if (color == "brightCyan")
	{
		col_code = 11;
	}
	else if (color == "brightRed")
	{
		col_code = 12;
	}
	else if (color == "pink")
	{
		col_code = 13;
	}
	else if (color == "yellow")
	{
		col_code = 14;
	}
	else if (color == "brightWhite")
	{
		col_code = 15;
	}
	else
	{
		//Set Default White If Given Colour Is Unknown 
		col_code = 7;
	}
	//SetColor
	SetConsoleTextAttribute(col, col_code);
}

//Make String's All Char's To LowerCase
string lower(string input)
{
	size_t size = input.size();//Get Size Of String
	char symbol; // Char For Every Index
	string ans = ""; //Set Answer to Empty String
	for (size_t i = 0; i < size; i++) //Loop To Extract String
	{
		symbol = tolower(input[i]); //Set Char To It's Lowercase
		ans += symbol; //Add It To Answer String
	}
	return ans;//Give Answer
}

//Delete Every Space In String
string noSpace(string input)
{
	size_t size = input.size(); //Get Size Of String
	char symbol; // Get A Char For Every Index
	string ans = ""; //Set Answer To Empty String
	for (size_t i = 0; i < size; i++) //Loop For Extracting Char From String
	{
		symbol = input[i]; //set Symbol To Given Index's Char
		if (symbol != ' ')//If Symbol Is Not Space
		{
			ans += symbol; //Add It To Ansewr
		}
	}
	return ans; //Give Answer
}

//Get Char As Int
int getInt(char symbol)
{
	//Note:
	//Same Rule Works On This One Too:
	//getInt('9') = 9
	//Only Works With 1 digit

	int ans = int(symbol) - 48;
	//0's Value Is 48 On ASCII Table
	return ans; //Give Answer
}

//Get Bin
vector<int> decToBin(int dec)
{
	vector<int> bin;
	string res = "";
	bin.push_back(dec % 2);
	while (dec / 2 != 0)
	{
		dec /= 2;
		bin.push_back(dec % 2);
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

//Get Dec
int binToDec(string bin)
{
	bin = noSpace(bin);
	size_t size = bin.size();
	char symbol;
	int number;
	int ans = 0;
	int c = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		symbol = bin[i];
		if (symbol != '1' && symbol != '0')
		{
			setColor("red");
			cout << "\nAcces Denied : ";
			cout << "Symbol Is Both Different Than 1 And 0.";
			setColor("white");
			abort();
		}
		else
		{
			number = getInt(symbol);
			ans += pow(2, c) * number;
		}
		c += 1;
	}
	return ans;
}