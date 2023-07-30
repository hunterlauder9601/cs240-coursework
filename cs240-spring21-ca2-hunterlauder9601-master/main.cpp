#include <iostream>
#include <string>
#include <iterator>
#include <sstream>

#include "Library.h"
#include "Playlist.h"
#include "Parser.h"

int main() {
    Library lib;
    string commandIn = "";
    Playlist selectedPlaylist;
    bool selectLibrary = true;
    int playlists_capacity = 1;
    int playlists_num = 0;
    Playlist *playlists = new Playlist[playlists_capacity];

    cout << "Hello, please build your mini music library with commands <add>, <show>, and <quit>." << endl;
    cout << "Enter add, show, select, remove, or quit:" << endl;
    getline(cin, commandIn);
    while (commandIn != "quit") {
        Parser parse(commandIn);
        if (parse.getOperation() == "select") {
            if (parse.getArg1() == "playlist") { // cmd: select playlist <playlist_name>
                bool found = false;
                for (int i = 0; i < playlists_num; i++) {
                    if (parse.getArg2() == playlists[i].returnName()) {
                        selectedPlaylist = playlists[i];
                        cout << "Playlist <" << playlists[i].returnName() << "> selected!" << endl;
                        found = true;
                        selectLibrary = false;
                        break;
                    }
                }
                if (!found) {
                    cout << "Error! Playlist title not found!" << endl;
                }
            } else if (parse.getArg1() == "library") {
                selectLibrary = true;
                cout << "Library selected!" << endl;
            } else {
                selectLibrary = false;
            }
        } else if (parse.getOperation() == "add") {
            if (parse.getArg1() == "song") {
                if (parse.getArg2().empty()) {
                    lib.add(); // cmd: add song
                } else {
                    if (selectLibrary) {
                        cout << "Error! No playlist selected (library selected)." << endl;
                    }
                    bool found = false;
                    for (int i = 0; i < lib.returnrSize(); i++) { // cmd: add song <title>
                        if (parse.getArg2() == lib.returnDyArr()[i].returnTitle()) {
                            selectedPlaylist.add(lib.returnDyArr()[i]);
                            for(int k = 0; k < playlists_num; k++) {
                                if(selectedPlaylist.returnName()==playlists[k].returnName()) {
                                    playlists[k] = selectedPlaylist;
                                }
                            }
                            found = true;
                            cout << "<" << lib.returnDyArr()[i].returnTitle() << "> added to <"
                                 << selectedPlaylist.returnName() << ">" << endl;
                        }
                    }
                    if(!found) {
                        cout << "Incorrect title entered! " << endl;
                    }
                }
            }
            if (parse.getArg1() == "playlist") { //cmd: add playlist <name>
                if (parse.getArg2().empty()) { // checks to see if <name> is empty
                    cout << "Missing playlist name! Enter here: " << endl;
                    getline(cin, commandIn);
                    Playlist list(lib, commandIn);
                    selectedPlaylist = list; // auto-selects this playlist since it was just created
                    selectLibrary = false;
                    playlists[playlists_num] = list;
                    playlists_num++;
                    cout << "Playlist <" << commandIn << "> successfully created!" << endl;
                } else {
                    Playlist list(lib, parse.getArg2());
                    cout << "Playlist <" << parse.getArg2() << "> successfully created!" << endl;
                    selectedPlaylist = list; // auto-selects this playlist since it was just created
                    selectLibrary = false;
                    playlists[playlists_num] = list;
                    playlists_num++;
                }
                if (playlists_num == playlists_capacity) {
                    playlists_capacity *= 2;
                    Playlist *temp = new Playlist[playlists_capacity];
                    copy(playlists, playlists + playlists_num, temp);
                    delete[] playlists;
                    playlists = temp;
                }
            }
        } else if (parse.getOperation() == "remove") {
            if (parse.getArg1() == "song") { // cmd: remove song <song_title> from current sel playlist/lib
                if (selectLibrary) { // library selected
                    lib.remove(parse.getArg2());
                } else { // playlist selected
                    selectedPlaylist.remove(parse.getArg2());
                    for(int k = 0; k < playlists_num; k++) {
                        if (selectedPlaylist.returnName() == playlists[k].returnName()) {
                            playlists[k] = selectedPlaylist;
                        }
                    }
                }
            } else if (parse.getArg1() == "playlist") {
                if (parse.getArg2().empty()) {
                    if (selectLibrary) {
                        cout << "Error! Library selected and no playlist specified!" << endl;
                    } else { // removes selected playlist
                        bool found = false;
                        for (int i = 0; i < playlists_num; i++) {
                            if (selectedPlaylist.returnName() == playlists[i].returnName()) { //needs to get position
                                found= true;
                                continue;
                            }
                            if (found && i-1>=0) {
                                playlists[i-1] = playlists[i];
                            }
                        }
                        if (found) {
                            cout << "Playlist " << parse.getArg2() << " was removed!" << endl;
                            playlists_num--;
                        }
                    }
                } else { // if playlist name is actually given
                    bool found = false;
                    for (int i = 0; i < playlists_num; i++) {
                        if (parse.getArg2() == playlists[i].returnName()) { //needs to get position
                            found= true;
                            continue;
                        }
                        if (found && i-1>=0) {
                            playlists[i-1] = playlists[i];
                        }
                    }
                    if (found) {
                        cout << "Playlist " << parse.getArg2() << " was removed!" << endl;
                        playlists_num--;
                    } else {
                        cout << "Playlist " << parse.getArg2() << " not found" << endl;
                    }
                }
            } else {
                cout << "unknown arg1 to remove: " << parse.getArg1() << endl;
            }
        } else if (parse.getOperation() == "show") {
            if (parse.getArg1() == "playlist") {
                if(parse.getArg2().empty()) {
                    if(selectLibrary){
                        cout << "No playlist selected (library selected)!" << endl;
                    } else {
                        selectedPlaylist.show();
                    }
                } else {
                    for (int i = 0; i < playlists_num; i++) {
                        if (parse.getArg2() == playlists[i].returnName()) {
                            playlists[i].show();
                        }
                    }
                }
            } else if (parse.getArg1() == "songs") {
                // NOTE: I am using my own << operator
                cout << lib;
            } else if (parse.getArg1() == "song") {
                if(selectLibrary) {
                    for(int i = 0; i < lib.returnrSize(); i++) {
                        // NOTE: I am using my own == operator
                        if(parse.getArg2()==lib.returnDyArr()[i]) {
                            lib.returnDyArr()[i].displayInfo();
                        }
                    }
                } else {
                    for(int i = 0; i < selectedPlaylist.returnPlaylistSize(); i++) {
                        // NOTE: I am using my own == operator
                        if(parse.getArg2()==selectedPlaylist.returnPlaylistSongsArr()[i]) {
                            selectedPlaylist.returnPlaylistSongsArr()[i].displayInfo();
                        }
                    }
                }
            } else if (parse.getArg1() == "playlists") {
                for(int i = 0; i < playlists_num; i++) {
                    playlists[i].returnTimeCreated();
                }
            }
            else {
                cout << "unknown arg1 to show: " << parse.getArg1() << endl;
            }
        }
        else if(parse.getOperation()=="clone") { // cmd: clone <playlist_name>
            if(selectLibrary) {
                cout << "Error! Playlist not selected!" << endl;
            } else {
                if(parse.getArg1().empty()) {
                    cout << "Error! Missing playlist name!" << endl;
                } else {
                    Playlist clone = Playlist(selectedPlaylist, parse.getArg1());
                    playlists[playlists_num] = clone;
                    playlists_num++;
                    if (playlists_num == playlists_capacity) {
                        playlists_capacity *= 2;
                        Playlist *temp = new Playlist[playlists_capacity];
                        copy(playlists, playlists + playlists_num, temp);
                        delete[] playlists;
                        playlists = temp;
                    }
                    cout << "Playlist <" << parse.getArg1() << "> was created!" << endl;
                }
            }
        }
        else if(parse.getOperation()=="import") {
            stringstream sstream(commandIn);
            for(auto inputPlaylists = istream_iterator<string>(sstream); inputPlaylists != istream_iterator<string>(); inputPlaylists++) {
                if(*inputPlaylists == "import") {
                    continue;
                }
                Playlist* p = nullptr;
                for(int i = 0; i < playlists_num; i++) {
                    if(*inputPlaylists == playlists[i].returnName()) {
                        p = &playlists[i];
                    }
                }
                if(!selectLibrary) {
                    // NOTE: I am using my own + operator
                    selectedPlaylist = selectedPlaylist + *(p);
                    for(int k = 0; k < playlists_num; k++) {
                        if (selectedPlaylist.returnName() == playlists[k].returnName()) {
                            playlists[k] = selectedPlaylist;
                        }
                    }
                    cout << "Playlist(s) songs imported into <" << selectedPlaylist.returnName() << ">!" << endl;
                } else {
                    for(int k = 0; k < p->returnPlaylistSize(); k++) {
                        bool found = false;
                        for(int i = 0; i < lib.returnrSize(); i++) {
                            if (lib.returnDyArr()[i].returnTitle() == p->returnPlaylistSongsArr()[k].returnTitle()) {
                                break;
                            }
                        }
                        if (!found) {
                            lib.addSpecific(p->returnPlaylistSongsArr()[k]);
                        }
                    }
                    cout << "Playlist(s) songs imported into library!" << endl;
                }
            }
        }
        else {
            cout << "unknown operation: " << parse.getOperation() << endl;
        }
        cout << "Enter add, show, select, remove, or quit:" << endl;
        getline(cin >> ws, commandIn);
    }
    delete [] playlists;
    return 0;
}