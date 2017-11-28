// Assignment 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include"Music.h"

int main()
{

	string filename;
	cout << "Enter the full filepath name where you would like to store it?" << endl;
	getline(cin, filename);

	Music **myMusic;
	int count = 0;
	int i;
	string answer = "Y";

	myMusic = new Music*[ARRAYSIZE];

	ifstream infile(filename);
	if (infile.good())
	{
		while (!infile.eof())
		{
			string t, n, an, r;
			getline(infile, t, ',');
			if (t.length())
			{
				getline(infile, n, '|');
				getline(infile, an, '|');
				getline(infile, r);
				myMusic[count] = new Music(t, n, an, stoi(r));
				count++;
			}
		}
	}


	cout << "You currently have " << count << " Music. Continue with creating a new/add more to list? Y/N -->";
	cin >> answer;

	while (answer == "Y" || answer == "y")
	{

		myMusic[count] = new Music();
		if (myMusic[count]->GetMusic() == 0)
			count++;

		cout << " Would you like to add another one?" << endl;
		cin >> answer;
	}

	ofstream outfile(filename);
	if (!outfile.good())
	{
		cout << "Cannot open file" << endl;
		return -1;
	}

	for (i = 0; i < count; i++)
	{
		outfile << myMusic[i];
	}

	for (i = 0; i < count; i++)
	{
		delete myMusic[i];
	}
	delete myMusic;
	return 0;

}
