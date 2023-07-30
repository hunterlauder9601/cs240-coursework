
#include <iostream>
#include <stdlib.h>
#ifndef CS240LAB1_HELLO_CLASS_H
#define CS240LAB1_HELLO_CLASS_H


using namespace std;


class Hello_Class {
public:
    Hello_Class(int);
    void print_hello();
private:
    string output_string;
};


#endif //CS240LAB1_HELLO_CLASS_H
