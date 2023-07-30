
#ifndef CA3LAB_SONGTOKENIZER_H
#define CA3LAB_SONGTOKENIZER_H
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "Song.h"

// SongTokenizer tokenizes Song lines in a file and exposes a function that can be used to retrieve the Song.
class SongTokenizer {
public:
    SongTokenizer(
            std::string inputdir_name, std::string filename) {
        infile = new std::ifstream(filePath(inputdir_name, filename).c_str());
    }

    Song* loadSong() {
        std::string line;
        Song* song2 = new Song();
        if (std::getline(*infile, line)) {
            song2->setTitle(line);
        }
        if (std::getline(*infile, line)) {
            song2->setName(line);
        }
        if (std::getline(*infile, line)) {
            song2->setDuration(line);
        }
        if (std::getline(*infile, line)) {
            bool ex = false;
            if (line=="y") ex=true;
            song2->setIsExplicit(ex);
        }
        if (std::getline(*infile, line)) {
            song2->setTimeAdded(line);
        }
        if (std::getline(*infile, line)) {
            song2->setDateAdded(line);
        }
            // we have read in all lines from file.
            infile->close();
        return song2;
    }

    ~SongTokenizer() {
        if (infile) delete infile;
        infile = nullptr;
    }

private:


    std::string filePath(std::string dir, std::string filename) {
        // creating the filepath.
        std::stringstream ss;
        ss << dir << "/" << filename;
        return ss.str();
    }

    std::ifstream* infile;
};


#endif //CA3LAB_SONGTOKENIZER_H
