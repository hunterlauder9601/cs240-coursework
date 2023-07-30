#ifndef DLINKLIST_H
#define DLINKLIST_H
#include <iostream>
#include <fstream>
#include "BadWords.h"

template<typename T>
class DoubleLinkedList
{
    class Node
    {
    public:
        T data;
        Node* next;
        Node* prev;

        //constructors
        Node(): next(nullptr), prev(nullptr)
        {
        }
        Node(T d): data(d), next(nullptr), prev(nullptr)
        {
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:

    //overloaded << operator to print the list
    friend std::ostream& operator << (std::ostream& out , DoubleLinkedList<T>& obj)
    {
        Node* temp=obj.head;
        while (temp) {
            out << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return out;
    }

    friend std::ofstream& operator << (std::ofstream& out , DoubleLinkedList<T>& obj)
    {
        Node* temp=obj.head;
        while (temp)
        {
            out << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return out;
    }

    //basic functions
    void append(T);
    void push_front(T);
    bool is_empty();
    void reverse();
    void clear();
    void remove(T);
    void save();
    int getSize();
    void showSongs(bool);
    void showLyrics(bool);
    void showSomeLyrics(int, int, bool);
    void cleanLyrics();
    T skip(T, int);
    T findSong(std::string);
    T getHead();
    T findExplicitSong();
    T getDataAt(int);
};

template <typename T>
T DoubleLinkedList<T>::getDataAt(int icount){
    Node* tmp = head;
    int count = 0;
    while(tmp != nullptr) {
        if (count++ == icount) {
            return tmp->data;
        }
        tmp = tmp->next;
    }
}

template <typename T>
void DoubleLinkedList<T>::cleanLyrics() {
    int arrSize = sizeof(BAD_WORDS)/sizeof(BAD_WORDS[0]);
    Node* tmp = head;
    int count = 0;
    while(tmp != nullptr) {
        for(int i = 0; i<arrSize; i++) {
            if(tmp->data == BAD_WORDS[i]) {
                tmp->data = "BLEEP";
                count++;
            }
        }
        tmp = tmp->next;
    }
    std::cout << "<" << count << "> bad words have been censored!\n";
}

template <typename T>
T DoubleLinkedList<T>::findExplicitSong() {
    Node* tmp = head;
    while(tmp != nullptr) {
        if(tmp->data.getExplicit()) {
            return tmp->data;
        }
        tmp = tmp->next;
    }
    T p;
    return p;
}


template <typename T>
T DoubleLinkedList<T>::skip(T song, int num) {
    Node* tmp = head;
    int count = 0;
    while(tmp != nullptr) {
        if(tmp->data.returnTitle() == song.returnTitle()) {
            break;
        }
        tmp = tmp->next;
        count++;
    }
    if(count+num < getSize()) {
        for(int i = 0; i<num; i++) {
            tmp = tmp->next;
        }
    } else {
        tmp = tail;
        std::cout << "You tried to skip more than the remaining number of songs! Last song selected!\n";
    }
    return tmp->data;
}

template <typename T>
T DoubleLinkedList<T>::getHead() {
    return head->data;
}

template <typename T>
T DoubleLinkedList<T>::findSong(std::string titleName) {
    Node* tmp = head;
    bool found = false;
    while(tmp != nullptr) {
        if(tmp->data.returnTitle() == titleName) {
            found = true;
            return tmp->data;
        }
        tmp = tmp->next;
    }
    if(!found) {
        std::cout << "The song specified does not exist!\n";
        T p;
        return p;
    }
}

template <typename T>
void DoubleLinkedList<T>::showLyrics(bool censor) {
    Node* tmp = head;
        if(censor) {
            int arrSize = sizeof(BAD_WORDS)/sizeof(BAD_WORDS[0]);
            int count = 0;
            while(tmp != nullptr) {
                bool found = false;
                for(int i = 0; i<arrSize; i++) {
                    if(tmp->data == BAD_WORDS[i]) {
                        found = true;
                        count++;
                        break;
                    }
                }
                if (found) {
                    std::cout << "BLEEP ";
                } else {
                    std::cout << tmp->data << " ";
                }
                tmp = tmp->next;
            }
            std::cout << "<" << count << "> bad words have been censored!\n";
        } else {
            while(tmp != nullptr) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
    std::cout << "\n";
}

template <typename T>
void DoubleLinkedList<T>::showSomeLyrics(int limit, int init, bool censor) {
        Node* tmp = head;
        for(int i = 0; i<init; i++) {
            tmp = tmp->next;
        }
        if(censor) {
            int arrSize = sizeof(BAD_WORDS)/sizeof(BAD_WORDS[0]);
            int count = 0;
            while(init<limit) {
                bool found = false;
                for(int i = 0; i<arrSize; i++) {
                    if(tmp->data == BAD_WORDS[i]) {
                        found = true;
                        count++;
                        break;
                    }
                }
                if (found) {
                    std::cout << "BLEEP ";
                } else {
                    std::cout << tmp->data << " ";
                }
                tmp = tmp->next;
                init++;
            }
            std::cout << "\n<" << count << "> bad words have been censored!\n";
        } else {
            while(init<limit) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
                init++;
            }
        }
        std::cout << "\n";
}

template <typename T>
void DoubleLinkedList<T>::showSongs(bool censor) {
    Node* tmp = head;
    if(censor) {
        while(tmp != nullptr) {
            if(tmp->data.getExplicit()) {
                tmp = tmp->next;
            } else {
                std::cout << tmp->data.returnTitle() << std::endl;
                tmp = tmp->next;
            }
        }
    } else {
        while(tmp != nullptr) {
            std::cout << tmp->data.returnTitle() << std::endl;
            tmp = tmp->next;
        }
    }
}

template <typename T>
int DoubleLinkedList<T>::getSize() {
    int size = 0;
    Node* current = head;
    while (current)
    {
        current = current -> next;
        ++size;
    }

    return size;
}

template <typename T>
void DoubleLinkedList<T>::save() {
//    if (head) {
//        std::ofstream outfile(filename);
//        if (outfile.is_open()) {
//            Node* cur = head;
//            char delim = ' ';
//            for (; cur != nullptr; cur = cur->next) {
//                if ((cur->next != nullptr) && (cur->next->name == "\n")) {
//                    outfile << cur->name;
//                } else if (cur->name == "\n") {
//                    outfile << cur->name;
//                } else {
//                    outfile << cur->name << delim;
//                }
//            }
//        }
//        outfile.close();
//    }
}

template <typename T>
void DoubleLinkedList<T>:: append(T dat)
{
    Node* current = new Node(dat);
    if (head == nullptr)
    {
        head = current;
    }
    else
    {
        tail -> next = current;
        current -> prev = tail;
    }
    tail = current;
}

//adds an item to front of list
template <typename T>
void DoubleLinkedList<T>:: push_front(T dat)
{
    Node* current = new Node(dat);
    if (head == nullptr)
    {
        head = current;
        tail = current;
    }
    else
    {
        head -> prev = current;
        current -> next = head;
        head = current;
    }
}

//checks if the list is empty
template <typename T>
bool DoubleLinkedList<T>:: is_empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
        return false;
}

//reverses the list
template <typename T>
void DoubleLinkedList<T>:: reverse()
{
    Node* current = tail;
    Node* future_next = nullptr;
    while (current)
    {
        future_next = current -> prev;
        if (current == tail)
        {
            head = tail;
            current -> prev = nullptr;
            current -> next = future_next;
        }
        else
        {
            current -> next = future_next;
            current -> prev = tail;
        }
        tail = current;
        current = future_next;
    }
}

//removes a given data node
template <typename T>
void DoubleLinkedList<T>::remove(T dat)
{
    Node* current = head;
    Node* previous = head;
    while (current)
    {
        if (current -> data == dat)
        {
            if(head == tail)
            {
                head = nullptr;
                tail = nullptr;
                delete current;
                std::cout << "Removed: " << dat << std::endl;
                return ;
            }
            else if (current == head)
            {
                head = current->next;
                head -> prev = nullptr;
                delete current;
                std::cout << "Removed: " << dat << std::endl;
                return ;
            }
            else if (current == tail)
            {
                previous -> next = nullptr;
                tail = previous;
                delete current;
                std::cout << "Removed: " << dat <<std::endl;
                return ;
            }
            else
            {
                (previous -> next) = (current -> next);
                (current -> next) -> prev = previous;
                delete current;
                std::cout << "Removed: " << dat <<std::endl;
                return ;
            }
        }
        previous = current;
        current = current -> next;
    }
    std::cerr << "Element not in list" << std::endl;
    return;
}

//deallocates all dynamically allocated memory
template <typename T>
void DoubleLinkedList<T>::clear()
{
    Node* current = head;
    Node* temp = head;
    while (current)
    {
        current = current -> next;
        delete temp;
        temp = current;
    }
    delete temp;
    head = nullptr;
    tail = nullptr;
}


#endif //DLINKLIST_DLINKLIST_H
