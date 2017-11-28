
#pragma once
#include <string>
using namespace std;

const int ARRAYSIZE = 100;

class Music
{
	string SongName;
	string Artist;
	string AlbumName;
	int Rating;

public:
	Music();
	Music(string t, string n, string an, int r);
	int GetMusic();
	void ShowMusic();

	friend ofstream& operator<<(ofstream &fs, Music *item);
};