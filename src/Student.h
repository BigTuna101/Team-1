//
//  Contains only functions and variables related to Students
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include <cctype>
#include <iostream>

using namespace std;

class Student
{
public:
    std::string roll_no;      //unique
    std::string name;
    std::string branch_ID;    //unique
    float CGPA;

    //Student()   { }

    //takes the indiviual student's data
    void inputData()
    {
        cout << "\t\t Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t Enter Roll No: ";
        getline(cin, roll_no);
        cout << "\t\t Enter Branch ID: ";
        getline(cin, branch_ID);
        cout << "\t\t Enter CGPA: ";
        cin >> CGPA;
        
        capitalize(name);

        cout << endl;
    }

    void capitalize(string &str);

    //displays the individual student's data
    void displayData()
    {
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << roll_no << "\n";
        cout << "Branch ID: " << branch_ID << "\n";
        cout << "CGPA: " << CGPA;

        cout << endl;
    }
    
};

void Student::capitalize(string &str)
{
    for (int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

//add functions to update name and cgpa

////////////////////////////

class StudentList
{
public:
    std::list<Student> Slist;

    void displayList();
    int totalStudents();
};

void StudentList::displayList()
{
    for (auto it = Slist.begin(); it != Slist.end(); ++it)
    {
        cout << "\n";
        it->displayData();
        cout << setw(79) << setfill('-') << "-";
        cout << "\n\n";
    }

}

int StudentList::totalStudents()
{
    return Slist.size();
}


#endif