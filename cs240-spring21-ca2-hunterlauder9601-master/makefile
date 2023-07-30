# Use the first FLAGS definition for debugging, the 2nd for optimizing your code
FLAGS = -Wall -Wextra -g

CA = 2
LASTNAME = Lauder
BU_USERID = hlauder1
GITHUB_USERID = HunterLauder9601
EXECUTABLE = main.exe

all: main

replaceme:
	echo "Did you remember to set the variables in the makefile?!"

tar: clean
	cd .. && tar -cvzf CA$(CA)_$(LASTNAME)_$(BU_USERID).tar.gz cs240-spring21-ca$(CA)-$(GITHUB_USERID) && cd -

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	./$(EXECUTABLE)

main: main.o Library.o Song.o Playlist.o Timestamp.o
	g++ main.o Library.o Song.o Playlist.o Timestamp.o -o main.exe

# Specify how the object files should be created from source files
main.o:	main.cpp
	g++ -c main.cpp

Library.o: Library.cpp
	g++ -c Library.cpp

Song.o: Song.cpp
	g++ -c Song.cpp

Playlist.o: Playlist.cpp
	g++ -c Playlist.cpp

Timestamp.o: Timestamp.cpp
	g++ -c Timestamp.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(EXECUTABLE)
