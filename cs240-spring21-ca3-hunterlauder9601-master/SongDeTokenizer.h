
#ifndef CA3LAB_SONGDETOKENIZER_H
#define CA3LAB_SONGDETOKENIZER_H
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "Song.h"

class SongDeTokenizer {
public:
    SongDeTokenizer(std::string idir_name) {
        dir_name = idir_name;
    }

    void writeSong(Song* song) {
        string songfilename = song->returnTitle()+".song-info.txt";
        ofstream ofile = std::ofstream(filePath(dir_name, songfilename).c_str());
        ofile << song->returnTitle() << endl;
        ofile << song->getName() << endl;
        ofile << song->getDuration() << endl;
        ofile << (song->getExplicit()?"y":"n") << endl;
        ofile << song->getTimeAdded() << endl;
        ofile << song->getDateAdded() << endl;
        ofile.close();
//        if (ofile) delete ofile;
//        ofile = nullptr;
        if (!song->getLyricsDll().is_empty())  {
            string lyricsfilename = song->returnTitle()+".song-lyrics.txt";
            ofile = std::ofstream(filePath(dir_name, lyricsfilename).c_str());
            ofile << song->getLyricsDll() << endl;
            ofile.close();
        }

    }


    ~SongDeTokenizer() {
    }

private:


    std::string filePath(std::string dir, std::string filename) {
        // creating the filepath.
        std::stringstream ss;
        ss << dir << "/" << filename;
        return ss.str();
    }
    std::string dir_name;
};


#endif //CA3LAB_SONGTOKENIZER_H
