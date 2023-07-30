#include "DLL.h"
#include <iostream>
#include <fstream>
#include <vector>

DLL::DLLNode::DLLNode(std::string word) : prev(nullptr), next(nullptr), value(word) {}

DLL::DLL() : head(nullptr), tail(nullptr), size(0) {}

void DLL::append(std::string word) {
	if (!head) {
		head = new DLLNode(word);
		tail = head;
	} else {
		DLLNode* new_node = new DLLNode(word);
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
	++size;
}

void DLL::save(std::string filename) {
	if (head) {
		std::ofstream outfile(filename);
		if (outfile.is_open()) {
			DLLNode* cur = head;
			char delim = ' ';
			for (; cur != nullptr; cur = cur->next) {
				if ((cur->next != nullptr) && (cur->next->value == "\n")) {
					outfile << cur->value;
				} else if (cur->value == "\n") {
					outfile << cur->value;
				} else {
					outfile << cur->value << delim;
				}
			}
		}
		outfile.close();
	}
}

DLL::DLLNode::~DLLNode() {
	prev = nullptr;
	if (next) delete next;
	next = nullptr;
}

DLL::~DLL() {
	if (head) {
		delete head;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}
