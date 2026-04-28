#include "Node.h"
#include <string>

using namespace std;

Node::Node() : next(nullptr), line(""), category("")
{

}

void Node::setCategory(string cat)
{
    category = cat;
}

void Node::setLine(string l)
{
    line = l;
}

void Node::setNext(Node* nxt)
{
    next = nxt;
}

string Node::getCategory()
{
    return category;
}

string Node::getLine()
{
    return line;
}

Node* Node::getNext()
{
    return next;
}
