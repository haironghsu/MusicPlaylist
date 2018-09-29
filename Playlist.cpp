#include <iostream>
#include <vector>
#include <string>
#include "Playlist.h"

using namespace std;

Playlist::Playlist() {
	listName = "none";
}

Playlist::Playlist(string playlistName) {
	listName = playlistName;
}

void Playlist::PrintList() {

	cout << listName;
}

void Playlist::AddSongs(Songs* newSongs) {

	songsPtr.push_back(newSongs);
}

void Playlist::PlaySongsInList() {
	
	for (int i = 0; i < songsPtr.size(); ++i) {
		songsPtr.at(i)->PlaySongs();
	}
}

void Playlist::DeleteSongPlaylist() {

	int pickSongIndex = 0;

	for (int i = 0; i < songsPtr.size(); ++i) {
		cout << i << ": ";
		songsPtr.at(i)->PrintTitle();
		cout << endl;
	}

	cout << "Pick a song index number to delete: ";
	cin >> pickSongIndex;
	cout << endl;


	songsPtr.erase(songsPtr.begin() + pickSongIndex);

}

void Playlist::DelteSongInList(string eraseSong) {

	for (int i = 0; i < songsPtr.size(); ++i) {
		if (eraseSong == songsPtr.at(i)->SongTitle()) {
			songsPtr.erase(songsPtr.begin() + i);
		}
		else {

		}
	}
}

void Playlist::AddPlayCount() {
	vector<Songs*> tempPtr;
	int numPlayCount = 0;
	int addPlayCount = 0;

	tempPtr = songsPtr;

	for (int i = 0; i < tempPtr.size(); ++i) {
		for (int j = i + 1; j < tempPtr.size(); ++j) {
			if (tempPtr.at(i)->SongTitle() == tempPtr.at(j)->SongTitle()) {
				numPlayCount = tempPtr.at(i)->PlayCount();
				addPlayCount = tempPtr.at(j)->PlayCount();

				numPlayCount = numPlayCount + addPlayCount;
				tempPtr.erase(tempPtr.begin() + j);
				--j;

			}
		}
	}
}

/*
void Playlist::DeleteDupSongs() {

	vector<Songs*> tempPtr;

	tempPtr = songsPtr;

	for (int i = 0; i < tempPtr.size(); ++i) {
		for (int j = i + 1; j < tempPtr.size(); ++j) {
			if (songsPtr.at(i)->SongTitle() == tempPtr.at(j)->SongTitle()) {
				cout << "removing a duplicate of " << songsPtr.at(i)->SongTitle();
				cout << endl;
				tempPtr.erase(tempPtr.begin() + j);
				--j;
			}
		}
	}
	for (int i = 0; i < songsPtr.size(); ++i) {
		songsPtr.erase(songsPtr.begin() + i);
	}
	songsPtr = tempPtr;
}
*/