#include "LinkedList.h"
#include "Node.h"
#include <vector>
#include <cctype>

using namespace std;

LinkedList::LinkedList() : headPtr(nullptr), numItems(0)
{

}

LinkedList::LinkedList(LinkedList* list)
{
    if(list->headPtr != nullptr)
    {
        // Set number of items and headPtr fields
        numItems = list->numItems;

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

int LinkedList::getLength()
{
    return numItems;
}

string LinkedList::convertToUpper(string str) 
{
    for (char &c : str) 
    {
        c = std::toupper(c);
    }
    return str;
}

int LinkedList::findIndexToAdd(string catToAdd, string lineToAdd)
{
    Node* current = headPtr;    // To point to the current node
    int index = 0;              // To know the position in the linked chain
    bool foundPos = false;      // To stop while loop

    // Find the correct category position
    while(current != nullptr && !foundPos)
    {
        // Get current category and convert it to all caps
        string currentCat = current->getCategory();
        currentCat = convertToUpper(currentCat);

        // Check if the current position is right. If it is not,
        // advance current
        if(convertToUpper(catToAdd) <= currentCat)
            foundPos = true;
        else 
        {
            current = current->getNext();
            index++;
        }
        
    }

    // Reset foundPos for the next while loop
    foundPos = false;

    // Define currentCat to make sure the program
    // stays within the same category
    string currentCat;
    if(current != nullptr)
    {
        currentCat = current->getCategory();
        currentCat = convertToUpper(currentCat); 
    }
    
    // Find the correct line position       
    while(current != nullptr 
        && currentCat == convertToUpper(catToAdd)
        && !foundPos)
    {
        // Get current line and convert it to all caps
        string currentLine = current->getLine();
        currentLine = convertToUpper(currentLine);

        // Check if the current position is right. If it is not,
        // advance current
        if(convertToUpper(lineToAdd) >= currentLine)
            foundPos = true;
        else 
        {
            // Get the next ptr
            current = current->getNext();

            // In case the current ends up being a nullptr
            if(current != nullptr)
            {
                currentCat = current->getCategory();
                currentCat = convertToUpper(currentCat);
            }
            
            index++;
        }
    }
    

    return index;
}

void LinkedList::addItem(string category, string line)
{
    bool success = false;    // To know if adding the item was successfull

    // For a case when the list is empty
    if(numItems == 0)
    {
        headPtr = new Node();
        headPtr->setCategory(category);
        headPtr->setLine(line);
        numItems++;
    }
    // For a case if the list has items
    else
    {
        Node* nodeBef;
        // Get the right index for adding the new node
        int index = findIndexToAdd(category, line);

        // Create a new node and set the values
        Node* newNode = new Node();
        newNode->setCategory(category);
        newNode->setLine(line);

        // When the new node is added in the beginning
        if(index == 0)
        {
            // Add the new node
            newNode->setNext(headPtr);
            headPtr = newNode;
            numItems++;
        }
        else
        {
            // Find the node that is supposed to be before 
            // the new node
            for(int i = 0; i <= index - 1; i++)
            {
                if(i == 0)
                    nodeBef = headPtr;
                else
                    nodeBef = nodeBef->getNext();
            }

            // Add the new node
            newNode->setNext(nodeBef->getNext());
            nodeBef->setNext(newNode);
            numItems++;
        }
        
    }

}

vector<string> LinkedList::toVector()
{
    Node* current = headPtr;;   // To access the current node
    vector<string> items;       // To store categories and lines in
                                // the linked list

    while(current != nullptr)
    {
        // Add current category and line into list
        items.push_back(current->getCategory());
        items.push_back(current->getLine());
        current = current->getNext();
        
    }

    return items;
}