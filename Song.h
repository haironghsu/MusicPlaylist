#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Songs {
public:

	Songs();
	Songs(string songTitle, string firstLine, string tag);

	void SetFirstLine(string firstLine);

	void PrintList();
	void PrintTitle();
	
	void PlaySongs();
	string SongTitle();
	string SongTag();

	int PlayCount();
	void AddPlayCount(int countPlay);
	

private:
	string songTitle;
	string firstLine;
	string tag;
	int countPlay = 0;
};
