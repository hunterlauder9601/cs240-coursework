#include "Library.h"


Library::Library(string inputdir_name, string outputdir_name) {
    song_files = getSongFilenames(inputdir_name);
    songs_dll = new DoubleLinkedList<Song>();
    // song_lyrics is a vector of doubly linkedlists.
    // The doubly linkedlist at location 0 in song_lyrics vector should hold lyrics present in the file at location 0 in song_files vector.
    //song_lyrics;

    // Iterate through the song_files vector.
    // In each loop,
    // 	instantiate a new doubly linkedlist on the heap.
    // 	instantiate a WordTokenizer object on the stack.
    // 	load the contents of the file into the doubly linkedlist by calling load(...).
    // 	add to the end the doubly linkedlist into the song_lyrics vector.
    std::vector<std::string>::iterator song_files_iter = song_files.begin();

    for(song_files_iter; song_files_iter != song_files.end(); song_files_iter++) {
        SongTokenizer s(inputdir_name, *song_files_iter);
        Song* song = s.loadSong();
        song_files_iter++;
        WordTokenizer w(inputdir_name, *song_files_iter);
        DoubleLinkedList<string>* lyricsDLL = new DoubleLinkedList<string>();
        load(w, lyricsDLL);
        song->setLyricsDll(*lyricsDLL);
        songs_dll->append(*song);
//        song->displayInfo();
    }
    selectedSong = songs_dll->getHead();
    cout << "Song <" << selectedSong.returnTitle() << "> is automatically selected!\n";

}
Song Library::findSong(string song) {
    return songs_dll->findSong(song);
}

Song Library::getSelectedSong() const {
    return selectedSong;
}
void Library::selectSong(string songTitle) {
    selectedSong = songs_dll->findSong(songTitle);
    if(selectedSong.returnTitle() == songTitle) {
        cout << "Song <" << selectedSong.returnTitle() << "> is now selected!\n";
    } else {
        selectedSong = songs_dll->getHead();
    }
}

void Library::save(string outputdir_name) {
    SongDeTokenizer s(outputdir_name);
    for (int i = 0 ; i < songs_dll->getSize(); i++) {
        Song song = songs_dll->getDataAt(i);
        s.writeSong(&song);
    }
}

void Library::skipSongs(int num) {
    Song tmp = songs_dll->skip(selectedSong, num);
    selectedSong = tmp;
    cout << "<" << num << "> songs skipped; <" << selectedSong.returnTitle() << "> is now selected!\n";
}

void Library::clean() {
    Song tmp = songs_dll->findExplicitSong();
    while(!tmp.returnTitle().empty()) {
        cout << "Explicit Song <"<< tmp.returnTitle() << "> removed!\n";
        songs_dll->remove(tmp);
        tmp = songs_dll->findExplicitSong();
    }
}
//void Library::setSongsDll(const DLL_song &songsDll) {
//    songs_dll = songsDll;
//}

//const DLL_song &Library::getSongsDll() const {
//    return songs_dll;
//}

Library::~Library() {
    // destroy the doubly linkedlists.
    // DO NOT CHANGE THIS. ASSUME THIS WORKS.
//    for (std::vector<std::string>::iterator iter = song_files.begin(); iter != song_files.end(); iter++) {
//        delete *iter;
for(int i = 0; i < songs_dll->getSize(); i++) {
    songs_dll->getDataAt(i).getLyricsDll().clear();
}
    songs_dll->clear();
}

// getSongFilenames takes a directory name and returns the names of all .txt files in that directory.
// DO NOT CHANGE THIS. ASSUME THIS WORKS.
std::vector<std::string> Library::getSongFilenames(std::string inputdir_name) {
    if (inputdir_name == "") return std::vector<std::string>();
    // cite - https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
    DIR* dir;
    struct dirent* dir_entry;
    std::vector<std::string> filenames;
    if ((dir = opendir(inputdir_name.c_str())) != nullptr) {
        while ((dir_entry = readdir(dir)) != nullptr) {
            // only adding txt files.
            if (std::string(dir_entry->d_name).find(".txt") != std::string::npos) {
                filenames.push_back(dir_entry->d_name);
            }
        }
        closedir(dir);
    }
    return filenames;
}

void Library::load(WordTokenizer& wt, DoubleLinkedList<string>* lyrics_store) {
    // TODO AS PART OF LAB EXERCISE MAR 25.
    // 1. call nextLine() on the WordTokenizer object to retrieve a vector containing words in a single line.
    // 2. iterate through the vector and add the words into the given doubly linkedlist.
    // Repeat this process until there are no more words returned by nextLine().
    // Note: do not use goto statements. Convert this logic into a while/for loop.

    auto input = wt.nextLine();
    while (input.size() != 0){
        for (int i = 0; i < input.size(); i++){
            lyrics_store->append(input[i]);
        }
        input = wt.nextLine();
    }
}

//ostream & operator<<(ostream &out,Library const &library1) {
//    for(int i = 0; i < library1.num; i++) {
//        out << "Song: " << i+1 << endl;
//       library1.songs[i].displayInfo();
//    }
//    return out;
//}


void Library::remove(string title) {
    //Song* song = new Song();
    //song->setTitle(title);
    songs_dll->remove(songs_dll->findSong(title));
}

void Library::add(string ifileName, string dir) {
    const string suffix = ".song-info.txt";
    char buff[FILENAME_MAX]; //create string buffer to hold path
//    getcwd( buff, FILENAME_MAX );
//    string current_working_dir(buff);
    SongTokenizer s(dir, ifileName+suffix);
    Song* song = s.loadSong();
    songs_dll->append(*song);
 //   songs_dll.getTailData().displayInfo();
}

void Library::showSong(string songTitle, bool censor) {
    Song tmp = songs_dll->findSong(songTitle);
    if(censor) {
        if(tmp.getExplicit()) {
            cout << "The song that you requested is explicit and therefore cannot be displayed while censor is active!\n";
        } else {
            tmp.displayInfo();
        }
    } else {
        tmp.displayInfo();
    }
}

void Library::showSongs(bool censor) {
    cout << "Songs: " << endl;
    songs_dll->showSongs(censor);
}