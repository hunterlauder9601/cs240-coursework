#ifndef DLL_H
#define DLL_H
#include <string>

class DLLNode;

class DLL {
	public:
		class DLLNode {
			public:
				// DLL class can now access private members of DLLNode.
				friend class DLL;
				DLLNode(std::string);
				~DLLNode();
			private:
				DLLNode* prev;
				DLLNode* next;
				// Note that you might have to change the type for CA3.
				std::string value;
		};

		DLL();
		// add the given word at the tail end of the doubly linkedlist.
		void append(std::string);
		// persist the words into the provided file.
		void save(std::string);
		~DLL();
	private:
		DLLNode* head;
		DLLNode* tail;
		int size;
};

#endif
