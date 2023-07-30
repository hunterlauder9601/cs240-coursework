#include <string>
#include <iostream>
// argc tells you how many command-line arguments exist. argc >= 1 (it factors in the command used to run the program).
// 	ex: "./partA arg1 arg2" has 3 command-line arguments which are ./partA, arg1, and arg2.
//
// argv is an array of C style strings (char* and not 'string'). argv[0] gives you the command used to run the program, argv[1] gives
// 	you the first command-line argument, argv[2] gives you the second command-line argument and so on.
int main(int argc, char* argv[]) {
	std::string input_dir_name;
	std::string working_dir_name;
	// print the number of command-line arguments.
    std::cout << argc << std::endl;
	// make sure that at least one command-line argument has been provided.
	// if not, then print an error message indicating the same and exit.
	// if the working directory name is not provided or is empty, then
	// 	print that it is empty.
	// 	set the working directory to be the input directory.
	// 	print a corresponding message indicating what you did in the previous step and exit.
	// else, if both the command-line arguments (input directory name and working directory name) have been provided, then
	// 	set input_dir_name and working_dir_name to the ones provided.
    if (argc < 2) {
        std::cout << "No command-line argument!" << std::endl;
    }
    else if (argv[2] == "") {
        std::cout << "No working directory name is provided!" << std::endl;
        working_dir_name == input_dir_name;
        std::cout << "Working directory set to input directory!" << std::endl;
        return 0;
    }
    else {
        input_dir_name = argv[1];
        working_dir_name = argv[2];
    }

	// IF HERE, THEN input_dir_name and working_dir_name != "".

	std::cout << "input directory name = " << input_dir_name << std::endl;
	std::cout << "working directory name = " << working_dir_name << std::endl;
	return 0;
}
