/*********************************************************************/

/* Eyu Haile

/* Lab 3 Solution                           

/* This program receives a file name from the user, then, after

/* reading its contents, displays them by category. The categories

/* are displayed in ascending order, while the lines are stored in

/* descending order. It uses a linked list to store the contents of 

/* the file.

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

    if(!file)
    {
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
    }
    else
    {
        cout << "Error: File could not be opened." << endl;
    }

    // Get rid of list object
    delete list;
    list = nullptr;

    return 0;
}