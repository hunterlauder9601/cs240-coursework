#include "Song.h"
#include <iostream>
#include <sstream>
#include <string>

Song::Song() {
};
void Song::cleanSong() {
    lyricsDLL.cleanLyrics();
}
void Song::play(bool censor) {
    lyricsDLL.showLyrics(censor);
}
bool Song::playN(int cur, int prev, bool censor) {
    if(cur+prev > lyricsDLL.getSize()) {
        std::cout << "Specified limit is higher than the song length; playing entire song!\n";
        play(censor);
        return true;
    } else {
        lyricsDLL.showSomeLyrics(cur, prev, censor);
        return false;
    }
}
int Song::getLyricsSize() {
    return lyricsDLL.getSize();
}

bool operator == (Song const &s1, Song const &s2) {
    return s1.title == s2.title;
}
std::ostream& operator << (std::ostream& out , Song& obj) {
    out << obj.title;
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
    cout << "lyrics (word size): " << lyricsDLL.getSize() << endl;
    cout << "------------------ " << endl;
}
void Song::displayForFileWrite()
{
    std::stringbuf buf;
    //= new std::stringbuf();
    cout << title << endl;
    cout << name << endl;
    cout << duration << endl;
    if(isExplicit) {
        cout << "y" << endl;
    }
    else {
        cout << "n" << endl;
    }
    cout << timeAdded << endl;
    cout << dateAdded << endl;

}

string Song::returnTitle() {
    return title;
}

string Song::getName()  {
    return name;
}

string Song::getDuration()
{
    return duration;
}
string Song::getDateAdded()
{
    return dateAdded;
}
string Song::getTimeAdded() {
    return timeAdded;
}
bool Song::getExplicit() {
    return isExplicit;
}

void Song::setName(const string &name) {
    Song::name = name;
}

void Song::setTitle(const string &title) {
    Song::title = title;
}

void Song::setDuration(const string &duration) {
    Song::duration = duration;
}

void Song::setDateAdded(const string &dateAdded) {
    Song::dateAdded = dateAdded;
}

void Song::setTimeAdded(const string &timeAdded) {
    Song::timeAdded = timeAdded;
}

void Song::setIsExplicit(bool isExplicit) {
    Song::isExplicit = isExplicit;
}

void Song::setLyricsDll(const DoubleLinkedList<string> &lyricsDll) {
    lyricsDLL = lyricsDll;
}

Song::~Song() {
//    lyricsDLL.clear();
}

DoubleLinkedList<string> &Song::getLyricsDll() {
    return lyricsDLL;
}

