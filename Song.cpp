#include <iostream>
#include <vector>
#include <string>
#include "Song.h"

using namespace std;


Songs::Songs() {
	songTitle = "none";
	firstLine = "none";
	tag = "none";
}

Songs::Songs(string title, string songFirstLine, string songTag) {
	songTitle = title;
	firstLine = songFirstLine;
	tag = songTag;
}

void Songs::SetFirstLine(string songFirstLine) {
	firstLine = songFirstLine;
}

void Songs::PrintList() {

	cout << songTitle << ": " << "\"" << firstLine << "\", " << countPlay << " play(s).";
	cout << endl;
	cout << "Tags: " << tag;
}

void Songs::PrintTitle() {
	cout << songTitle;
}

void Songs::PlaySongs() {
	++countPlay;
	cout << firstLine << endl;
}

string Songs::SongTitle() {
	return songTitle;
}

string Songs::SongTag() {
	return tag;
}

int Songs::PlayCount() {
	return countPlay;
}

void Songs::AddPlayCount(int playCount) {
	countPlay = countPlay + playCount;
}