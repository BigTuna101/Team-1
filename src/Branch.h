//
//  Contains only functions and variables related to Branches
//

#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <list>
#include <cctype>
#include <iostream>

using namespace std;

class Branch
{
public:
    std::string name;
    std::string branch_ID;      //unique
    std::string university_ID;  //unique

    //do we need a constructor
    // Branch() {   }


    //takes the indiviual Branch's data
    void inputData()
    {
        cout << "\t\t Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t Enter Branch ID: ";
        getline(cin, branch_ID);
        cout << "\t\t Enter University ID: ";
        getline(cin, university_ID);
        
        capitalize(name);
        cout << endl;
    }

    void capitalize(string &str);

    //displays the individual Branch's data
    void displayData()
    {
        cout << "Name: " << name << "\n";
        cout << "University ID: " << university_ID << "\n";
        cout << "Branch ID: " << branch_ID;

        cout << endl;
    }
    
};

void Branch::capitalize(string &str)
{
    for (int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

////////////////////////////

class BranchList
{
public:
    std::list<Branch> Blist;
    
    void displayList();
    int totalBranches();
};

void BranchList::displayList()
{
    for (auto it = Blist.begin(); it != Blist.end(); ++it)
    {
        cout << "\n";
        it->displayData();
        cout << setw(79) << setfill('-') << "-";
        cout << "\n\n";
    }

}

int BranchList::totalBranches()
{
    return Blist.size();
}

#endif