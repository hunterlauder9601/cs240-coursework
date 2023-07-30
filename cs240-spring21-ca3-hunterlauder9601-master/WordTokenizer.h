
#ifndef CA3LAB_WORDTOKENIZER_H
#define CA3LAB_WORDTOKENIZER_H
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <sstream>
#include <fstream>

// WordTokenizer tokenizes words in a file and exposes a function that can be used to retrieve the words in the file as vector.
// DO NOT CHANGE THIS. ASSUME THIS WORKS.
class WordTokenizer {
public:
    WordTokenizer(std::string inputdir_name, std::string filename) {
        infile = new std::ifstream(filePath(inputdir_name, filename).c_str());
    }

    // nextLine() returns a vector of words that form the next line in the file.
    // If the line in the file is 'just beat it', then nextLine() returns a vector ['just', 'beat', 'it', '\n'].
    // if the vector is empty, it means that EOF has been reached.
    std::vector<std::string> nextLine() {
        std::string line;
        std::vector<std::string> words;
        if (std::getline(*infile, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                words.push_back(word);
            }
            words.push_back("\n"); // adding the newline character as another word.
        } else {
            // we have read in all lines from file.
            infile->close();
        }
        return words;
    }

    ~WordTokenizer() {
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


#endif //CA3LAB_WORDTOKENIZER_H
