/*********************************************************************/

/* Your name

/* Lab 1 Solution                           

/* This program does this and that

/* (give details that would help a programmer understand

/* what the program does before looking at the code)               

/*********************************************************************/ 

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
    cout << "(Make sure to include the file extension)" << endl;
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
    string currentCat;
    for(int i = 0; i < items.size(); i+=2)
    {
        if(currentCat != items[i])
        {
            currentCat = items[i];
            cout << currentCat << endl;
            cout << "   " << items[i + 1] << endl;
        }
        else 
        {
            cout << "   " << items[i + 1] << endl;
        }
    }


    return 0;
}