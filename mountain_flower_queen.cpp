#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <cmath>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

// Define the data structure 
struct Song {
	string title;
	string artist;
	int tempo;
	int duration;
	string genre;
	string mood;
	int year;
};

// Function declaration
void menu();
void addSong(Song& song);
void showSong(Song& song);
void editSong(Song& song);
void deleteSong(Song& song);
void saveChanges();

// Global variable 
bool is_editing = false;
Song current_song;
string filename;

// Main 
int main(){
	cout<<"Welcome to Music for Healing Project"<<endl;
	cout<<"Choose your action"<<endl;

	while(true){
		menu();
		int choice;
		cin>>choice;

		// Check for valid input
		if(choice > 0 && choice <= 7){
			switch (choice){
				case 1:
					cout<<"Add new song to the list"<<endl;
					addSong(current_song);
					break;
				case 2:
					cout<<"Show current song"<<endl;
					showSong(current_song);
					break;
				case 3:
					cout<<"Edit current song"<<endl;
					editSong(current_song);
					break;
				case 4:
					cout<<"Delete current song"<<endl;
					deleteSong(current_song);
					break;
				case 5:
					cout<<"Save changes"<<endl;
					saveChanges();
					break;
				case 6:
					cout<<"Exit"<<endl;
					return 0;
				case 7:
					cout<<"Help"<<endl;
					break;
				default:
					break;
			}
		}
		else{
			cout<<"Error!!! Invalid Choice"<<endl;
		}
	}
	return 0;
}

// Function definition
void menu() {
	cout<<"1. Add new song"<<endl;
	cout<<"2. Show current song"<<endl;
	cout<<"3. Edit current song"<<endl;
	cout<<"4. Delete current song"<<endl;
	cout<<"5. Save changes"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"7. Help"<<endl;
	
}

void addSong(Song& song) {
	cout<<"Enter the song title: ";
	cin.ignore();
	getline(cin, song.title);
	cout<<"Enter the artist name: ";
	getline(cin, song.artist);
	cout<<"Enter the tempo of the song: ";
	cin>>song.tempo;
	cout<<"Enter the duration of the song: ";
	cin>>song.duration;
	cout<<"Enter the genre of the song: ";
	cin.ignore();
	getline(cin, song.genre);
	cout<<"Enter the mood of the song: ";
	getline(cin, song.mood);
	cout<<"Enter the year of the song: ";
	cin>>song.year;
	cout<<"Song added successfully!"<<endl;
}

void showSong(Song& song) {
	cout<<"Title: "<<song.title<<endl;
	cout<<"Artist: "<<song.artist<<endl;
	cout<<"Tempo: "<<song.tempo<<endl;
	cout<<"Duration: "<<song.duration<<endl;
	cout<<"Genre: "<<song.genre<<endl;
	cout<<"Mood: "<<song.mood<<endl;
	cout<<"Year: "<<song.year<<endl;
	cout<<endl;
}

void editSong(Song& song) {
	cout<<"Choose the element to edit"<<endl;
	cout<<"1. Title"<<endl;
	cout<<"2. Artist"<<endl;
	cout<<"3. Tempo"<<endl;
	cout<<"4. Duration"<<endl;
	cout<<"5. Genre"<<endl;
	cout<<"6. Mood"<<endl;
	cout<<"7. Year"<<endl;
	cout<<"8. Save"<<endl;
	int choice;
	cin>>choice;

	// Check for valid input
	if(choice > 0 && choice <= 8){
		switch(choice){
			case 1:
				cout<<"Enter the new title: ";
				cin.ignore();
				getline(cin, song.title);
				is_editing = true;
				break;
			case 2:
				cout<<"Enter the new artist name: ";
				getline(cin, song.artist);
				is_editing = true;
				break;
			case 3:
				cout<<"Enter the new tempo: ";
				cin>>song.tempo;
				is_editing = true;
				break;
			case 4:
				cout<<"Enter the new duration: ";
				cin>>song.duration;
				is_editing = true;
				break;
			case 5:
				cout<<"Enter the new genre: ";
				cin.ignore();
				getline(cin, song.genre);
				is_editing = true;
				break;
			case 6:
				cout<<"Enter the new mood: ";
				getline(cin, song.mood);
				is_editing = true;
				break;
			case 7:
				cout<<"Enter the new year: ";
				cin>>song.year;
				is_editing = true;
				break;
			case 8:
				if(is_editing){
					cout<<"Changes saved successfully!"<<endl;
					is_editing = false;
				}
				else{
					cout<<"No changes to save"<<endl;
				}
				break;
			default:
				break;
		}
	}
	else{
		cout<<"Error!!! Invalid Choice"<<endl;
	}
	
}

void deleteSong(Song& song) {
	cout<<"Are you sure you want to delete this song? (y/n)"<<endl;
	char choice;
	cin>>choice;

	if(choice == 'y'){
		cout<<"Song deleted successfully!"<<endl;
		song.title = "";
		song.artist = "";
		song.tempo = 0;
		song.duration = 0;
		song.genre = "";
		song.mood = "";
		song.year = 0;
	}
	else if(choice == 'n') {
		cout<<"Deletion cancelled"<<endl;
	}
	else {
		cout<<"Error!!! Invalid Choice"<<endl;
	}
}

void saveChanges(){
	stringstream ss;
	ss<<current_song.title<<"_"<<current_song.artist<<".txt";
	filename = ss.str();
	
	// Convert the string to lowercase
	transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
	ofstream save_file(filename);
	
	if(save_file.is_open()) {
		save_file<<"Title: "<<current_song.title<<endl;
		save_file<<"Artist: "<<current_song.artist<<endl;
		save_file<<"Tempo: "<<current_song.tempo<<endl;
		save_file<<"Duration: "<<current_song.duration<<endl;
		save_file<<"Genre: "<<current_song.genre<<endl;
		save_file<<"Mood: "<<current_song.mood<<endl;
		save_file<<"Year: "<<current_song.year<<endl;
		save_file.close();
		
		cout<<"Changes saved to "<<filename<<" successfully!"<<endl;
	}
	else {
		cout<<"Error!!! Could not save the file"<<endl;
	}
}