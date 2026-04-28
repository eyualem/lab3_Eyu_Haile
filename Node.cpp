#include "Node.h"
#include <string>

using namespace std;

/******************************************************
 * Node()
 * Initializes the fields of the node object
 * to their initial values.
 * 
 * Parameters:
 *   None
 * 
 * Returns: nothing
 ******************************************************/
Node::Node() : next(nullptr), line(""), category("")
{

}

/******************************************************
 * setCategory(string cat)
 * Sets the category field of the node object to the 
 * given string.
 * 
 * Parameters:
 *   string cat: the category to set
 * 
 * Returns: nothing
 ******************************************************/
void Node::setCategory(string cat)
{
    category = cat;
}

/******************************************************
 * setLine(string l)
 * Sets the line field of the node object to the 
 * given string.
 * 
 * Parameters:
 *   string l: the line to set
 * 
 * Returns: nothing
 ******************************************************/
void Node::setLine(string l)
{
    line = l;
}

/******************************************************
 * setNext(Node* nxt)
 * Sets the next node in the linked list.
 * 
 * Parameters:
 *   Node* nxt: the next node to set
 * 
 * Returns: nothing
 ******************************************************/
void Node::setNext(Node* nxt)
{
    next = nxt;
}

/******************************************************
 * getCategory()
 * Gets the category field of the node object.
 * 
 * Parameters:
 *   none
 * 
 * Returns: the category
 ******************************************************/
string Node::getCategory()
{
    return category;
}

/******************************************************
 * getLine()
 * Gets the line field of the node object.
 * 
 * Parameters:
 *   none
 * 
 * Returns: the line
 ******************************************************/
string Node::getLine()
{
    return line;
}

/******************************************************
 * getNext()
 * Gets the next node in the linked list.
 * 
 * Parameters:
 *   none
 * 
 * Returns: the next node
 ******************************************************/
Node* Node::getNext()
{
    return next;
}
