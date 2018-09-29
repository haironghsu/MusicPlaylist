#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Playlist.h"
#include "Song.h"

using namespace std;

void Options(){
	cout << "\nadd      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "autogenp Autogenerate a new playlist (based on tags)" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
	cout << "deldup   Deletes duplicate songs from the library (and all playlists)" << endl;
	cout << "updatesl Update a song in the library" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program\n" << endl;
}



int main() {

	string userInput;
	string songTitle;
	string firstLine;
	string playlistName;
	string tags;
	string songTag;
	string firstTag = "none";
	string secondTag = "none"; 
	string thirdTag = "none";

	string findTag;

	istringstream iSS;
	int playlistIndex = 0;
	int songIndex = 0;
	
	vector<Songs*> songsPtr;
	vector<Playlist*> playlistPtr;
	vector<Songs*> tempPtr;
	

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;

	while (userInput != "quit") {
		
		cout << endl;
		cout << "Enter your selection now: ";
		getline(cin, userInput);
		cout << endl;

		if (userInput == "add") {
			
			cout << "Read in Song names, first lines, and tags (type \"STOP\" when done):" << endl;

			while (songTitle != "STOP") {			
				cout << "Song Name: ";
				getline(cin, songTitle);
				cout << endl;

				if (songTitle == "STOP") {
					songTitle = "none"; // songTitle 값을 초기화 해주어야지 다음 add 할때 while loop 이 실행이 됨.
					break;
				}
				else {
					cout << "Song's first line: ";
					getline(cin, firstLine);
					cout << endl;
					cout << "Tags: ";
					getline(cin, tags);

					songsPtr.push_back(new Songs(songTitle, firstLine, tags));
					cout << endl;
				}	
			}
		}
		else if (userInput == "list") {

			for (int i = 0; i < songsPtr.size(); ++i) {
				songsPtr.at(i)->PrintList();
				cout << endl;
			}
			
			cout << endl;
		}
		else if (userInput == "addp") {
			cout << "Playlist name: ";
			getline(cin, playlistName);

			playlistPtr.push_back(new Playlist(playlistName));
			cout << endl;

		}
		else if (userInput == "autogenp") {
			cout << "Playlist name: ";
			getline(cin, playlistName);
			cout << endl;

			playlistPtr.push_back(new Playlist(playlistName));

			cout << "Tags: ";
			getline(cin, tags);
			iSS.clear();
			iSS.str(tags);
			iSS >> firstTag;
			iSS >> secondTag;
			iSS >> thirdTag;

			for (int i = 0; i < songsPtr.size(); ++i) {
				songTag = songsPtr.at(i)->SongTag();

				if (secondTag == "none") {
					if (songTag.find(firstTag) != string::npos) {
						playlistPtr.at(playlistPtr.size() - 1)->AddSongs(songsPtr.at(i));
					}
				}

				else if (thirdTag == "none") {
					if (songTag.find(firstTag) != string::npos || songTag.find(secondTag) != string::npos) {
						playlistPtr.at(playlistPtr.size() - 1)->AddSongs(songsPtr.at(i));
					}
				}

				else if (thirdTag != "none") {
					if (songTag.find(firstTag) != string::npos || songTag.find(secondTag) != string::npos || songTag.find(thirdTag) != string::npos) {
						playlistPtr.at(playlistPtr.size() - 1)->AddSongs(songsPtr.at(i));
					}
				}
			}
		}

		else if (userInput == "addsp") {

			for (int i = 0; i < playlistPtr.size(); ++i) {
				cout << i << ": ";
				playlistPtr.at(i)->PrintList();
				cout << endl;
			}

			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cout << endl;

			for (int i = 0; i < songsPtr.size(); ++i) {
				cout << i << ": ";
				songsPtr.at(i)->PrintTitle();
				cout << endl;
			}

			cout << "Pick a song index number: ";
			cin >> songIndex;
			cout << endl;
			
			playlistPtr.at(playlistIndex)->AddSongs(songsPtr.at(songIndex));

			cin.ignore();
		}
		else if (userInput == "listp") {

			for (int i = 0; i < playlistPtr.size(); ++i) {
				cout << i << ": ";
				playlistPtr.at(i)->PrintList();
				cout << endl;
			}
		}
		else if (userInput == "play") {
			
			for (int i = 0; i < playlistPtr.size(); ++i) {
				cout << i << ": ";
				playlistPtr.at(i)->PrintList();
				cout << endl;
			}
			cout << endl;

			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cout << endl;

			cout << "Playing first lines of playlist: ";
			playlistPtr.at(playlistIndex)->PrintList();
			cout << endl;

			playlistPtr.at(playlistIndex)->PlaySongsInList();

			cin.ignore();
		}
		else if (userInput == "delp") {

			for (int i = 0; i < playlistPtr.size(); ++i) {
				cout << i << ": ";
				playlistPtr.at(i)->PrintList();
				cout << endl;
			}

			cout << "Pick a playlist index number to delete: ";
			cout << endl;
			cin >> playlistIndex;

			delete playlistPtr.at(playlistIndex); // erase 전에 delete 를 먼저 해줘야 함
			playlistPtr.erase(playlistPtr.begin() + playlistIndex);

			cin.ignore();
		}
		else if (userInput == "delsp") {

			for (int i = 0; i < playlistPtr.size(); ++i) {
				cout << i << ": ";
				playlistPtr.at(i)->PrintList();
				cout << endl;
			}

			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cout << endl;
			
			playlistPtr.at(playlistIndex)->DeleteSongPlaylist();

			cin.ignore();
		}
		else if (userInput == "delsl") {

			for (int i = 0; i < songsPtr.size(); ++i) {
				cout << i << ": ";
				songsPtr.at(i)->PrintTitle();
				cout << endl;
			}

			cout << "Pick a song index number: ";
			cin >> songIndex;
			cout << endl;

			for (int i = 0; i < playlistPtr.size(); ++i) {
				playlistPtr.at(i)->DelteSongInList(songsPtr.at(songIndex)->SongTitle());
			}

			delete songsPtr.at(songIndex);
			songsPtr.erase(songsPtr.begin() + songIndex);


			cin.ignore();
		}
		else if (userInput == "deldup") {
			
			tempPtr = songsPtr;
		
			for (int i = 0; i < tempPtr.size(); ++i) {
				
				for (int j = i + 1; j < tempPtr.size(); ++j) {
					if (tempPtr.at(i)->SongTitle() == tempPtr.at(j)->SongTitle()) {
						cout << "removing a duplicate of " << tempPtr.at(j)->SongTitle();
						cout << endl;
						tempPtr.at(i)->AddPlayCount(tempPtr.at(j)->PlayCount());
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

		else if (userInput == "updatesl") {
			for (int i = 0; i < songsPtr.size(); ++i) {
				cout << i << ": ";
				songsPtr.at(i)->PrintTitle();
				cout << endl;
			}
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			cout << "Song's first line:" << endl;
			cin.ignore();

			getline(cin, firstLine);
			songsPtr.at(songIndex)->SetFirstLine(firstLine);

		}
		else if (userInput == "options") {
			Options();
		}
		else if (userInput == "quit") {
			for (int i = 0; i < songsPtr.size(); ++i) {
				delete songsPtr.at(i);
				songsPtr.erase(songsPtr.begin() + i);
			}
			for (int i = 0; i < playlistPtr.size(); ++i) {
				delete playlistPtr.at(i);
				playlistPtr.erase(playlistPtr.begin() + i);
			}
			cout << "Goodbye!";
			break;
		}
		else {
			Options();
		}

	}

	return 0;
}