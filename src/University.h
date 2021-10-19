//
//  Contains only functions and variables related to Universities
//

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <list>
#include <cctype>
#include <iostream>

using namespace std;

class University
{
public:
    string university_ID;
    string name; 
    string location;
    string year_of_start;    

    //do we need a constructor
    // University() {   }

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

    void capitalize(string &str);

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

void University::capitalize(string &str)
{
    for (int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

//add functions to update name and location and year_of_start

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