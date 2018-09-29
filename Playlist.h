#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Song.h"

using namespace std;


class Playlist {
public:

	Playlist();
	Playlist(string listName);

	void PrintList();
	void AddSongs(Songs* songsPtr);
	void PlaySongsInList();
	void DeleteSongPlaylist();
	void DelteSongInList(string songsPtr);
	void DeleteDupSongs();
	
	void AddPlayCount();
	string PrintListName();

private:
	string listName;
	string songTitle;
	string tags;
	vector<Songs*> songsPtr;
};
