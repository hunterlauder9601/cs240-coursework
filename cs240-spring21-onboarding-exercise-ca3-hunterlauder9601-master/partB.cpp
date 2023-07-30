#include "DLL.h"
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <sstream>
#include <fstream>

// getSongFilenames takes a directory name and returns the names of all .txt files in that directory.
// DO NOT CHANGE THIS. ASSUME THIS WORKS.
std::vector<std::string> getSongFilenames(std::string inputdir_name) {
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


// load the words from the tokenizer into the given doubly linkedlist.
void load(WordTokenizer& wt, DLL* lyrics_store) {
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

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "error: invalid number of commandline arguments" << std::endl;
		exit(1);
	}

	std::string inputdir_name = argv[1];
	std::string outputdir_name = argv[2];
	// song_files vector stores the names of the files in the input directory.
	std::vector<std::string> song_files = getSongFilenames(inputdir_name);
	// song_lyrics is a vector of doubly linkedlists.
	// The doubly linkedlist at location 0 in song_lyrics vector should hold lyrics present in the file at location 0 in song_files vector.
	std::vector<DLL*> song_lyrics;

	// TODO AS PART OF LAB EXERCISE MAR 25.
	// Iterate through the song_files vector.
	// In each loop,
	// 	instantiate a new doubly linkedlist on the heap.
	// 	instantiate a WordTokenizer object on the stack.
	// 	load the contents of the file into the doubly linkedlist by calling load(...).
	// 	add to the end the doubly linkedlist into the song_lyrics vector.


	// Simulataneously iterate through both song_lyrics and song_files vectors.
	// For each loop.
	// 	generate the output file path by concatenating outputdir_name, '/' and value of song_files iterator.
	// 	save the song lyrics (calling save() on the value of song_lyrics iterator) to the output file.
	// DO NOT CHANGE THIS. ASSUME THIS WORKS.
	std::vector<std::string>::iterator song_files_iter = song_files.begin();
	std::vector<DLL*>::iterator lyrics_iter;
	for (lyrics_iter = song_lyrics.begin(); lyrics_iter != song_lyrics.end(); lyrics_iter++) {
		// generating output file path (<outputdir>/<filename>).
		std::string song_filename = *song_files_iter;
		std::stringstream ss;
		ss << outputdir_name << "/" << song_filename;
		std::string output_filepath = ss.str();

		// save the song lyrics into the output file.
		(*lyrics_iter)->save(output_filepath);
		song_files_iter++;
	}

	// destroy the doubly linkedlists.
	// DO NOT CHANGE THIS. ASSUME THIS WORKS.
	for (std::vector<DLL*>::iterator iter = song_lyrics.begin(); iter != song_lyrics.end(); iter++) {
		delete *iter;
	}
}
