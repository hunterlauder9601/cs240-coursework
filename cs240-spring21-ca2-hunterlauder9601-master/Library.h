
#ifndef LAB2_LIBRARY_H
#define LAB2_LIBRARY_H
#include "Song.h"

class Library {
public:
    friend ostream & operator<<(ostream &out,Library const &library);
    Library();
    void add();
    void addSpecific(Song song);
    void show();
    void remove(string);
    Song* returnDyArr() const;
    int returnrSize() const;
    virtual ~Library();

private:
    int num;
    int capacity;
    Song* songs;
};


#endif //LAB2_LIBRARY_H
