//
//  Contains only functions and variables related to Universities
//

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <list>
#include <iostream>
#include <cctype>

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
        cin.ignore(1000, '\n');
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

    void capitalize(std::string &str);

    //takes the indiviual University's data
    void displayData()
    {
        cout << "\tName: " << name << "\n";
        cout << "\tLocation: " << location << "\n";
        cout << "\tYear of Start: " << year_of_start << "\n";
        cout << "\tUniversity ID: " << university_ID;

        cout << endl;
    }
    
};

void University::capitalize(std::string &str)
{
    for (unsigned int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

/////////////////////////////

class UniversityList
{
public:
    list<University> Ulist;

    //Display the entire University list
    void displayList();
    int totalUniversities();
    void updateUniversity();

};

void UniversityList::updateUniversity()
{

}

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