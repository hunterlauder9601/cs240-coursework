
#include "Library.h"


Library::Library() {
    num = 0;
    capacity = 1;
    songs = new Song[capacity];
}

Library::~Library() {
    delete [] songs;
}

ostream & operator<<(ostream &out,Library const &library1) {
    for(int i = 0; i < library1.num; i++) {
        out << "Song: " << i+1 << endl;
       library1.songs[i].displayInfo();
    }
    return out;
}

Song * Library::returnDyArr() const {
    return songs;
}

int Library::returnrSize() const {
    return num;
}

void Library::addSpecific(Song song) {
    songs[num] = song;
    num++;
    if(num == capacity) {
        capacity*=2;
        Song* temp = new Song[capacity];
        std::copy(songs, songs + num, temp);
        delete [] songs;
        songs = temp;
    }
}

void Library::remove(string songtitle) {
    bool found = false;
    for (int i = 0; i < num; i++) {
        if (songtitle == songs[i].returnTitle()) { //needs to get position
            found= true;
            continue;
        }
        if (found && i-1>=0) {
            songs[i-1] = songs[i];
        }
    }
    if (found) {
        cout << "Playlist " << songtitle << " was removed!" << endl;
        num--;
    } else {
        cout << "Song title not found in library!" << endl;
    }
}

void Library::add() {
    cout << "Song: " << num+1 << endl;
    songs[num].getArtist();
    songs[num].getTitle();
    songs[num].getDuration();
    songs[num].getDateAdded();
    songs[num].getTimeAdded();
    songs[num++].getExplicit();

    if(num==capacity) {
        capacity *= 2;
        Song* temp = new Song[capacity];
        std::copy(songs, songs + num, temp);
        delete [] songs;
        songs = temp;
    }
}

void Library::show() {
    for(int i = 0; i < num; i++) {
        cout << "Song: " << i+1 << endl;
        songs[i].displayInfo();
    }
}