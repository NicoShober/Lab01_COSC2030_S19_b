// NumberProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

int main()
{
	string input, first, last= "initial_last", pen= "initial_last",txt_file; //pen is the second to last
	cout << "Enter a text file to read from: "; //prompting user for input file name
	cin >> txt_file; //reads the user input and stores it into the txt_file variable
	ifstream myfile; //crating teh ifstream
	myfile.open(txt_file); //opening the text file
	myfile >> first; //reads the first number and stores it in the first variable
	while (myfile >> input)//goes through the text file until it reaches the end
	{
		pen = last; //assigning the pen to the last variable to achieve the second to last
		last = input;//whatever the text file reads back set as the last variable 
	}
	myfile.close(); //close the read stream
	cout << "First: " << first << "\nPenultimate: " << pen <<"\nLast: " << last  << endl; //print results
}


