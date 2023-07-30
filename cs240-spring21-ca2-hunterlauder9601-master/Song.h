#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    friend bool operator==(Song const &song1, Song const &song2);
    friend bool operator==(string const &name, Song const &song2);
   void getArtist();
    void getTitle();
    void getDuration();
    void getDateAdded();
    void getTimeAdded();
    void getExplicit();
    void displayInfo();
    string returnTitle();
private:
    string name;
    string title;
    string duration;
    string dateAdded;
    string timeAdded;
    bool isExplicit;
};

