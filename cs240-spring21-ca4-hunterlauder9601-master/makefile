# Use the first FLAGS definition for debugging, the 2nd for optimizing your code
FLAGS = -Wall -Wextra -g
#FLAGS = -Wall -Wextra -O3

CA = 4
LASTNAME = Lewis
BU_USERID = mlewis
GITHUB_USERID = mlewis608
EXECUTABLE = CA4
OBJ_DIR = obj
BIN_DIR = bin
OBJS = $(OBJ_DIR)/useTicker.o \
       $(OBJ_DIR)/useMap.o \
       $(OBJ_DIR)/nlogn.o \
       $(OBJ_DIR)/CA4.o

all: CA4 useTicker useMap

tar: clean
	cd .. && tar -cvzf CA$(CA)_$(LASTNAME)_$(BU_USERID).tar.gz cs240-spring21-ca$(CA)-$(GITHUB_USERID) && cd -

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	$(BIN_DIR)/$(EXECUTABLE)

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing

CA4: $(OBJ_DIR)/CA4.o
	g++ $(FLAGS) $(OBJ_DIR)/CA4.o -o $(BIN_DIR)/$(EXECUTABLE)

$(OBJ_DIR)/CA4.o: CA4.cpp Sorter.cpp Sorter.h
	g++ $(FLAGS) -c CA4.cpp -o $(OBJ_DIR)/CA4.o

useTicker: $(OBJ_DIR)/useTicker.o $(OBJ_DIR)/nlogn.o
	g++ $(FLAGS) $(OBJ_DIR)/useTicker.o $(OBJ_DIR)/nlogn.o -o $(BIN_DIR)/useTicker

$(OBJ_DIR)/useTicker.o: useTicker.cpp Ticker.h
	g++ $(FLAGS) -c useTicker.cpp -o $(OBJ_DIR)/useTicker.o

$(OBJ_DIR)/nlogn.o: nlogn.cpp
	g++ $(FLAGS) -c nlogn.cpp -o $(OBJ_DIR)/nlogn.o

useMap: $(OBJ_DIR)/useMap.o $(OBJ_DIR)/useMap.o
	g++ $(FLAGS) $(OBJ_DIR)/useMap.o -o $(BIN_DIR)/useMap

$(OBJ_DIR)/useMap.o: useMap.cpp
	g++ $(FLAGS) -c useMap.cpp -o $(OBJ_DIR)/useMap.o

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXECUTABLE) $(BIN_DIR)/useTicker $(BIN_DIR)/useMap
