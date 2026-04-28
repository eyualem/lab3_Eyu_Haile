#ifndef _NODE 
#define _NODE

#include <string>

using namespace std;

class Node 
{
    private:
        string category;   // the category of the line 
        string line;       // line from a file
        Node* next;        // pointer to next node

    public:
        Node();
        void setCategory(string);    // To set category
        void setLine(string);        // To set line
        void setNext(Node*);         // To set next node
        string getCategory();        // To get category
        string getLine();            // To get line
        Node* getNext();             // To get next node
};

#include "Node.cpp"
#endif