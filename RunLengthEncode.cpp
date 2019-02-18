// RunLengthEncode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprsFrank.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open.";
	// Read into pix_list.
	i = 0;
	
	
	while (getline(pixf_full,line)) //1.)getline(pixf_full,line)
	{
		cout << line;
		//2.) this prints out each line as it goes thorugh the text file
		pix_list.push_back(line);
		i = i + 1;
	}
	
	n = pix_list.size();
	cout << "\n\nLength of pix_list is " << n << " ; i = " << i << "\n\n";
	
	// Go through list, testing whether next pixel is the same.
	for (i = 0; n>i; i++) //3.)n>i
	{
		
		
		
		if (pix_list[i + 1] != pix_list[i]) //4.)!=    pix_list[i]
			pixf_cmpr << pix_list[i];
		
		else
		{
			// Pixels same.

			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			pixf_cmpr << "\n -rep- " << pix_list[i].substr(0, pix_list[i].find_last_not_of(whitespace));
			// 5. (Explain loop below.)
			count = 1;
			while (i < n - 1 &&  pix_list[i] == pix_list[i + 1]) //6.) pix_lisst[i]
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}

	return 0;
}

