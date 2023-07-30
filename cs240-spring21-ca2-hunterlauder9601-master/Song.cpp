#include "Song.h"
#include <iostream>
#include <sstream>
#include <string>

void Song::getArtist()
{
    cout << "Enter artist name: " << endl;
    cin >> name;
}
void Song::getTitle()
{
    cout << "Enter song title: " << endl;
    cin >> title;
}
void Song::getDuration()
{
    cout << "Enter song duration: " << endl;
    cin >> duration;
}
void Song::getDateAdded()
{
    cout << "Enter the date: " << endl;
    cin >> dateAdded;
}
void Song::getTimeAdded()
{
    cout << "Enter the time: " << endl;
    cin >> timeAdded;
}
void Song::getExplicit()
{
    cout << "Enter 0 if the song is not explicit, or 1 if it is explicit: " << endl;
    string s;
    cin >> s;
//    getline(cin, s);
    std::istringstream(s) >> isExplicit;
}
void Song::displayInfo()
{
    cout << "Artist: " << name << endl;
    cout << "Title: " << title << endl;
    cout << "Duration: " << duration << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "Time Added: " << timeAdded << endl;
    if(isExplicit) {
        cout << "Explicit: Yes" << endl;
    }
    else {
        cout << "Explicit: No" << endl;
    }
}

string Song::returnTitle() {
    return title;
}

bool operator==(Song const &song1, Song const &song2) {
    return song1.title==song2.title;
}
bool operator==(string const &name, Song const &song2) {
    cout << "== overloader called for " << name << endl;
    return name==song2.title;
}
