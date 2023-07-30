#include <iostream>
#include <string>
#include <iterator>
#include <sstream>

#include "Library.h"
#include "Parser.h"


int main(int argc, char* argv[]) {
    string commandIn = "";
    if (argc != 3) {
        std::cout << "error: invalid number of commandline arguments" << std::endl;
        exit(1);
    }
    bool censor = false;
    int cur = 0;
    int prev = 0;
    std::string inputdir_name = argv[1];
    std::string outputdir_name = argv[2];
    Library lib(inputdir_name, outputdir_name);

    cout << "Hello, please build your mini music library with commands <add>, <show>, and <quit>." << endl;
    cout << "Enter add, show, select, remove, or quit:" << endl;
    getline(cin, commandIn);
    while (commandIn != "quit") {
        Parser parse(commandIn);
        if (parse.getOperation() == "select") {
            if(parse.getArg1() == "song") {
                lib.selectSong(parse.getArg2());
                cur = 0;
                prev = 0; // resets play data
            }
        }
        else if (parse.getOperation() == "add") {
            if (parse.getArg1() == "fsong") {
                if (parse.getArg2().empty()) {
                    cout << "unknown arg2 to add: " << parse.getArg2() << endl;
                } else {
                    lib.add(parse.getArg2(), outputdir_name); // cmd: add fsong
                }
            }
        }
        else if (parse.getOperation() == "remove") {
            if (parse.getArg1() == "song") { // cmd: remove song <song_title> from lib
                    lib.remove(parse.getArg2());
            } else {
                cout << "unknown arg1 to remove: " << parse.getArg1() << endl;
            }
        }
        else if (parse.getOperation() == "show") {
            if (parse.getArg1() == "songs") {
                lib.showSongs(censor);
            } else if(parse.getArg1() == "song") {
                lib.showSong(parse.getArg2(), censor);
            }
            else {
                cout << "unknown arg1 to showSongs: " << parse.getArg1() << endl;
            }
        }
        else if (parse.getOperation() == "play") {
            if (parse.getArg1().empty()) {
                lib.getSelectedSong().play(censor);
            } else {
                stringstream ss(parse.getArg1());
                int x = 0;
                ss >> x;
                cur += x;
                bool houseKeeping = lib.getSelectedSong().playN(cur, prev, censor);
                prev += x;
                if(houseKeeping) {
                    cur = 0;
                    prev = 0;
                }
            }
        }
        else if (parse.getOperation() == "rewind") {
            if (parse.getArg1().empty()) {
                cur = 0;
                prev = 0; //resets the play data so next play starts from beginning
                cout << "Song rewinded to the beginning!\n";
            } else {
                stringstream ss(parse.getArg1());
                int x = 0;
                ss >> x;
                cur -= x;
                prev -= x;
                cout << "Song rewinded <" << parse.getArg1() << "> words!\n";
                if(prev <= 0 || cur <= 0) {
                    cur = 0;
                    prev = 0;
                    cout << "Song rewinded to the beginning because the beginning of the song was reached before going back <" << parse.getArg1() << "> words!\n";
                }
            }
        }
        else if (parse.getOperation() == "skip") {
            if (parse.getArg1().empty()) { //assumes skip=1 if nothing there
                lib.skipSongs(1);
                cur = 0;
                prev = 0; //resets the play data so next play starts from beginning
            } else {
                stringstream ss(parse.getArg1());
                int x = 0;
                ss >> x;
                lib.skipSongs(x);
                cur = 0;
                prev = 0; //resets the play data so next play starts from beginning
            }
        }
        else if (parse.getOperation() == "clean") {
            if (parse.getArg1().empty()) {
                lib.clean();
            }
            if (parse.getArg1() == "song") {
                lib.findSong(parse.getArg2()).cleanSong();
            }
        }
        else if (parse.getOperation() == "censor") {
            if (parse.getArg1() == "on") {
                censor = true;
                cout << "Censor toggled: on!\n";
            }
            else if(parse.getArg1() == "off") {
                censor = false;
                cout << "Censor toggled: off!\n";
            }
        }
        else {
            cout << "unknown operation: " << parse.getOperation() << endl;
        }
        cout << "Enter add, show, select, remove, or quit:" << endl;
        getline(cin >> ws, commandIn);
    }
    lib.save(outputdir_name);

    return 0;
}