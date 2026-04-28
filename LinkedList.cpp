#include "LinkedList.h"
#include "Node.h"
#include <vector>

using namespace std;

LinkedList::LinkedList() : headPtr(nullptr), numItems(0)
{

}

LinkedList::LinkedList(LinkedList* list)
{
    // Set number of items and headPtr fields
    numItems = list->numItems;

    if(list->headPtr != nullptr)
    {
        // Point origList to the original linked list's first node
        Node* origList = list->headPtr;

        // Create a node used to the copy original linked list
        Node* newList = new Node();

        // Copy the data attributes of the first node
        newList->setCategory(origList->getCategory());
        newList->setLine(origList->getLine());

        // Point heatptr to newList pointer
        headPtr = newList;

        // Get the node after the first node in the original linked list
        origList = origList->getNext();
        
        while(origList != nullptr)
        {
            // Copy the fields of the current node into a new node
            Node* current = new Node();
            current->setCategory(origList->getCategory());
            current->setLine(origList->getLine());
            newList->setNext(current);

            // Add the new node to the new list and set it to the next
            newList = current;

            // Get the next node
            origList = origList->getNext();

            // Set current to nullptr
            current = nullptr;
        }

        // Set origList to nullptr
        origList = nullptr;
    }
    else
    {
        headPtr = nullptr;
    }
}