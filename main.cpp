#include <iostream>
#include <fstream>
#include <vector>
#include "LinkedList.h"

int main()
{
    string fileName;        // To store the name of the file
    string category;        // To store a category in a file
    string line;            // To store a line in a file
    vector<string> items;   // To store the lines a file

    // Create a LinkedList object
    LinkedList* list = new LinkedList();
    
    // Ask the user for the file name
    cout << "What is the name of the file whose contents you want displayed? " << endl;
    cin >> fileName;
    cout << endl;

    // Open the file
    ifstream file(fileName);

    // Read the contents of the file and store them in the LinkedList
    while(getline(file, category))
    {
        getline(file, line);
        list->addItem(category, line);
    }

    // Get the contents in the LinkedList
    items = list->toVector();

    // Display the items in the LinkedList
    cout << "Here are the contents of the file: " << endl;
    for(int i = 0; i < items.size(); i++)
    {
        cout << items[i] << endl;
    }


    return 0;
}