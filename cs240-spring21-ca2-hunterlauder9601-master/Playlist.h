
#ifndef LAB2_PLAYLIST_H
#define LAB2_PLAYLIST_H

#include "Library.h"
#include "Timestamp.h"

class Playlist {
public:
    Playlist();
    Playlist(const Library&, string);
    Playlist(const Playlist&, string);
    void add(Song);
    void remove(string);
    string returnName();
    void show();
    int returnPlaylistSize();
    Song* returnPlaylistSongsArr();
    void returnTimeCreated();
    friend Playlist operator + (Playlist const &, Playlist const &);
    virtual ~Playlist();

private:
    string playlistName;
    int capacity;
    Song* playlist;
    Song* lib;
    int playlist_num;
    int libSize;
    Timestamp completedTime;
};


#endif //LAB2_PLAYLIST_H
