// AS4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include"Music.h"

int main()
{
	// Ask users to input the filepath where they would like to store the file
	string filename;
	cout << "Enter the full filepath where you would like to store it?" << endl;
	getline(cin, filename);

	Music **myMusic;
	int count = 0;
	int i;
	string answer = "Y";

	myMusic = new Music*[ARRAYSIZE];

	ifstream infile(filename);
	if (infile.good())
	{
		// get music items from user
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

	// Tells them how many movies they have listed and if they would like to add more
	cout << "You currently have" << count << "Music. Continue with creating a new/add more to list? Y/N -->";
	cin >> answer;

	while (answer == "Y" || answer == "y")
	{
	
		myMusic[count] = new Music();
		if (myMusic[count]->GetMusic() == 0)
			count++;
		
		// Ask the user if they want to add more
		cout << " Would you like to add another one?" << endl;
		cin >> answer;
	}
	//Save to a File

	ofstream outfile(filename);
	if (!outfile.good())
	{
		cout << "Cannot open file" << endl;
		return -1;
	}

	// printing to console
	for (i = 0; i < count; i++)
	{
		outfile << myMusic[i];
	}


	// cleaning up
	for (i = 0; i < count; i++)
	{
		delete myMusic[i];
	}
	delete myMusic;
	return 0;

}