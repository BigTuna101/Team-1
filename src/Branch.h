//
//  Contains only functions and variables related to Branches
//

#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <list>
#include <iostream>
#include <cctype>


using namespace std;

class Branch
{
public:
    std::string name;
    std::string branch_ID;      //unique
    std::string university_ID;  //unique

    // Branch() {   }


    //takes the indiviual Branch's data
    void inputData()
    {
        cout << "\t\t Enter Name: ";
        cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "\t\t Enter Branch ID: ";
        getline(cin, branch_ID);
        cout << "\t\t Enter University ID: ";
        getline(cin, university_ID);
        
        capitalize(name);
        cout << endl;
    }

    void capitalize(std::string &str);

    //displays the individual Branch's data
    void displayData()
    {
        cout << "|--- Branch Name: " << name << "\n";
        cout << "|--- Branch ID: " << branch_ID;

        cout << endl;
    }
    
};

//TODO: add functions to modify data

void Branch::capitalize(std::string &str)
{
    for (unsigned int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

//////////////////////////////

class BranchList
{
public:
    std::list<Branch> Blist;
    
    void displayList();
    //int totalBranches();  //TODO: find total branch per Univerisity
};

void BranchList::displayList()
{
    string UnID;
    for (auto it = Blist.begin(); it != Blist.end(); ++it)
    {
        cout << "\n";
        
        if (UnID != it->university_ID)
        { 
            if (UnID != "")   
            {
                cout << setw(79) << setfill('-') << "-";
                cout << "\n\n";
            }

            UnID = it->university_ID;
            cout << " " << UnID << " ";
            cout << "\n|\n";

        }
        it->displayData();
        
        //TODO: display the total branch per university
        //TODO: instead of displaying only the University ID we can display the University Name (ID) and then branch names 

    }

}


///////////////////////////////



#endif