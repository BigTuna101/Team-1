//
//  Contains only functions and variables related to Students
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include <iostream>
#include <cctype>

using namespace std;

class Student
{
public:
    string roll_no;      //unique
    string name;
    string branch_ID;    //unique
    float CGPA;

    //Student()   { }

    //takes the indiviual student's data
    void inputData()
    {
        cout << "\t\t Enter Name: ";
        cin.ignore(1000, '\n');
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

    void capitalize(std::string &str);
  
    //displays the individual student's data
    void displayData()
    {
        cout << "\tName: " << name << "\n";
        cout << "\tRoll No: " << roll_no << "\n";
        cout << "\tBranch ID: " << branch_ID << "\n";
        cout << "\tCGPA: " << CGPA;

        cout << endl;
    }
    
};

void Student::capitalize(std::string &str)
{
    for (unsigned int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

//////////////////////////////////////

class StudentList
{
public:
    std::list<Student> Slist;

    void displayList();
    int totalStudents();
    void updateStudent();
};

void StudentList::updateStudent()
{

}
void StudentList::displayList()
{
    string BrID;
    for (auto it = Slist.begin(); it != Slist.end(); ++it)
    {
        cout << "\n";
        
        if (BrID != it->branch_ID)
        { 
            if (BrID != "")   
            {
                cout << setw(79) << setfill('-') << "-";
                cout << "\n\n";
            }

            BrID = it->branch_ID;
            cout << " " << BrID << "\n";
            cout << setw(20) << setfill('*') << "*";
            cout << "\n";

        }
        it->displayData();
        
        //TODO: instead of displaying only the branch ID we can display the University Name (ID) and then branch names then 
        //the Student

    }
}

int StudentList::totalStudents()
{
    return Slist.size();
}


#endif