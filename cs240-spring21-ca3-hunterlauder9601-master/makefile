# Use the first FLAGS definition for debugging, the 2nd for optimizing your code
FLAGS = -Wall -Wextra -g

CA = 3
LASTNAME = Lauder
BU_USERID = hlauder1
GITHUB_USERID = hunterlauder9601
EXECUTABLE = main.exe
inputdir = mellow_songs
workdir = output

## ADD TARGETS TO SEPARATELY COMPILE YOUR CODE FOR CA3 AND CREATE AN EXECUTABLE.

replaceme:
	echo "Did you remember to set the variables in the makefile?!"

all: main

main: main.o Library.o Song.o
	g++ main.o Library.o Song.o -o main.exe

main.o:	main.cpp
	g++ -c main.cpp

Library.o: Library.cpp
	g++ -c Library.cpp

Song.o: Song.cpp
	g++ -c Song.cpp

tar: clean
	cd .. && tar -cvzf CA$(CA)_$(LASTNAME)_$(BU_USERID).tar.gz cs240-spring21-ca$(CA)-$(GITHUB_USERID) && cd -

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(inputdir) $(workdir)

memcheck: $(EXECUTABLE)
	valgrind ./$(EXECUTABLE) $(inputdir) $(workdir)

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(EXECUTABLE)
