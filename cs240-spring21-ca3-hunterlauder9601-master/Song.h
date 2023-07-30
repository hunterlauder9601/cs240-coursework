#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

using namespace std;

class Song {
public:
    Song();
    void cleanSong();
    void play(bool);
    bool playN(int, int, bool);
    int getLyricsSize();
    void displayInfo();
    friend bool operator == (Song const &, Song const &);
    friend std::ostream& operator << (std::ostream& out , Song& obj);
    Song(const Song &p1) {
        name = p1.name;
        title = p1.title;
        duration = p1.duration;
        dateAdded = p1.dateAdded;
        timeAdded = p1.timeAdded;
        isExplicit = p1.isExplicit;
        lyricsDLL = p1.lyricsDLL;
    }
    void displayForFileWrite();

    string returnTitle();
    string getName();
    string getTimeAdded();
    string getDateAdded();
    string getDuration();
    bool getExplicit();

    void setName(const string &name);

    void setTitle(const string &title);

    void setDuration(const string &duration);

    void setDateAdded(const string &dateAdded);

    void setTimeAdded(const string &timeAdded);

    void setIsExplicit(bool isExplicit);

    ~Song();

    void setLyricsDll(const DoubleLinkedList<string> &lyricsDll);

    DoubleLinkedList<string> &getLyricsDll();

private:
    string name;
    string title;
    string duration;
    string dateAdded;
    string timeAdded;
    bool isExplicit;
    DoubleLinkedList<string> lyricsDLL;
};

#endif //SONG_H