#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <vector>
#include "Node.h"

using namespace std;

class LinkedList
{
    private:
        Node* headPtr;
        int numItems;

    public:
        LinkedList();
        LinkedList(LinkedList*);
        int getLength();
        void addItem(string, string);
        vector<string> toVector();
};

#include "LinkedList.cpp"
#endif