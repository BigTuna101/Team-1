//
//  Contains only functions and variables related to Universities
//

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <list>
#include <iostream>

#include "Utility.h"

using namespace std;

class University
{
public:
    string university_ID;
    string name; 
    string location;
    string year_of_start;    

    // University() {   }   //TDOD: add a meaningfull constructor

    //takes the indiviual University's data
    void inputData()
    { 
        cout << "\t\t Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t Enter Location: ";
        getline(cin, location);
        cout << "\t\t Enter Year of Start: ";
        getline(cin, year_of_start);
        cout << "\t\t Enter University ID: ";
        getline(cin, university_ID);
        
        capitalize(name);

        cout << endl;
    }

    //takes the indiviual University's data
    void displayData()
    {
        cout << "Name: " << name << "\n";
        cout << "Location: " << location << "\n";
        cout << "Year of Start: " << year_of_start << "\n";
        cout << "University ID: " << university_ID;

        cout << endl;
    }
    
};

//TODO: add functions to modify data

/////////////////////////////

class UniversityList
{
public:
    list<University> Ulist;

    //Display the entire University list
    void displayList();
    int totalUniversities();

};


void UniversityList::displayList()
{
    for (auto it = Ulist.begin(); it != Ulist.end(); ++it)
    {
        cout << "\n";
        it->displayData();
        cout << setw(79) << setfill('-') << "-";
        cout << "\n\n";
    }

}

int UniversityList::totalUniversities()
{
    return Ulist.size();
}



#endif