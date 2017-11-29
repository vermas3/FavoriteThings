#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Music.h"
using namespace std;

Music::Music() // default constructor
{
	SongName = "";
	Artist = "";
	AlbumName = "";
	Rating = 0;
}

Music::Music(string t, string n, string an, int r)  // overloaded constructor
{
	SongName = t;
	Artist = n;
	AlbumName = an;
	Rating = r;
}

int Music::GetMusic() // Ask users for the information
{
	cout << "What is the song name>" << endl;
	cin >> SongName;

	cout << "What is the artists name?" << endl;
	cin >> Artist;

	cout << "What is the album name?" << endl;
	cin >> AlbumName;

	cout << "Rating?" << endl;
	cin >> Rating;

	cin.ignore();
	cin.clear();
	return 0;
}

void Music::ShowMusic() // spits out information
{
	cout << "Song: " << SongName << endl;
	cout << "Artist: " << Artist << endl;
	cout << "Album: " << AlbumName << endl;
	cout << "Rating: " << Rating << endl;
}

ofstream& operator<<(ofstream &fs, Music *item)
{
	fs << item->SongName << "," << item->Artist << "," << item->AlbumName << "," << item->Rating << endl;
	return fs;
}
