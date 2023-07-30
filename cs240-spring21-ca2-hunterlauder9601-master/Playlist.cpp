
#include "Playlist.h"

Playlist::~Playlist() {
    //delete [] playlist;
}

Playlist::Playlist(const Library& other, string name) {
    capacity = 1;
    playlist_num = 0;
    playlist= new Song[capacity];
    lib = other.returnDyArr();
    libSize = other.returnrSize();
    playlistName = name;
    completedTime = Timestamp();
}

Playlist::Playlist(const Playlist& ogPlaylist, string name) {
    this->playlistName = name;
    this->capacity = ogPlaylist.capacity;
    this->playlist_num = ogPlaylist.playlist_num;
    this->completedTime = ogPlaylist.completedTime;
    this->lib = ogPlaylist.lib;
    this->libSize = ogPlaylist.libSize;
    Song* temp = new Song[ogPlaylist.capacity];
    for (int i = 0; i < ogPlaylist.playlist_num; i++) {
        temp[i] = ogPlaylist.playlist[i];
    }
    this->playlist = temp;
}
Playlist operator + (Playlist const &selectedPlaylist, Playlist const &chosenPlaylist) {
    Playlist temp(selectedPlaylist, selectedPlaylist.playlistName);
    for(int k = 0; k < chosenPlaylist.playlist_num; k++) {
        bool found = false;
        for(int i = 0; i < selectedPlaylist.playlist_num; i++) {
            if (selectedPlaylist.playlist[i].returnTitle() == chosenPlaylist.playlist[k].returnTitle()) {
                break;
            }
        }
        if (!found) {
            temp.add(chosenPlaylist.playlist[k]);
        }
    }
    return temp;
}

void Playlist::returnTimeCreated() {
    cout << "Playlist <" << playlistName << "> created at: " << completedTime.toString() << endl;
}

int Playlist::returnPlaylistSize() {
    return playlist_num;
}

Song* Playlist::returnPlaylistSongsArr() {
    return playlist;
};

string Playlist::returnName() {
    return playlistName;
}

void Playlist::show() {
    cout << "Playlist songs: " << endl;
    for(int i = 0; i < playlist_num; i++) {
        cout << playlist[i].returnTitle() << endl;
    }
}

void Playlist::remove(string songtitle) {
    bool found = false;
    for (int i = 0; i < playlist_num; i++) {
        if (songtitle == playlist[i].returnTitle()) { //needs to get position
            found= true;
            continue;
        }
        if (found && i-1>=0) {
            playlist[i-1] = playlist[i];
        }
    }
    if (found) {
        cout << "Song <" << songtitle << "> was removed from <" << playlistName << ">!" << endl;
        playlist_num--;
    } else {
        cout << "Song title not found in selected playlist!" << endl;
    }
}

void Playlist::add(Song song) {
        playlist[playlist_num] = song;
        playlist_num++;
        if(playlist_num == capacity) {
            capacity*=2;
            Song* temp = new Song[capacity];
            std::copy(playlist, playlist + playlist_num, temp);
            delete [] playlist;
            playlist = temp;
        }
}

Playlist::Playlist() {

}

