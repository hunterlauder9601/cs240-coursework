
#ifndef LAB2_LIBRARY_H
#define LAB2_LIBRARY_H
#include "DoubleLinkedList.h"
#include "SongDeTokenizer.h"
#include "WordTokenizer.h"
#include "SongTokenizer.h"
#include "Song.h"

#include <unistd.h>
using namespace std;

class Library {
public:
    //friend ostream & operator<<(ostream &out,Library const &library);
    std::vector<std::string> getSongFilenames(std::string inputdir_name);
    void load(WordTokenizer& wt, DoubleLinkedList<string>* lyrics_store);
    Library(string inputdir_name, string outputdir_name);
    void save(string outputdir_name);
    void add(string, string);
    void showSongs(bool);
    void showSong(string, bool);
    void remove(string);
    void selectSong(string);
    void skipSongs(int);
    void clean();
    Song findSong(string);
    virtual ~Library();
    Song getSelectedSong() const;

private:
    Song selectedSong;
    DoubleLinkedList<Song>* songs_dll;
//    DLL_song songs_dll;
    std::vector<std::string> song_files;
};


#endif //LAB2_LIBRARY_H
