#include <iostream>
#include <iomanip>
#include <list>

#include "Branch.h"
#include "University.h"
#include "Student.h"

using namespace std;

int choice;     //stores the choice 
char enter;     //character for input of ENTER

//global UniversityList, BranchList, StudentList
UniversityList objUniversity;
BranchList objBranch;
StudentList objStudent;

//GUI Functions
inline void clrscr();
void displayHeader();
void mainScreen();
void universityScreen();
void studentScreen();
void branchScreen();

//UNIVERSITY Functions
void addUniversity();
void viewAllUniversity();

//Branch Functions
void addBranch();
void viewAllBranch();

//Student Functions
void addStudent();
void viewAllStudent();

int main()
{

    mainScreen();

    return 0;
}

//to clear the console screen
inline void clrscr()
{
    system("CLS || CLEAR");
}

void displayHeader()
{
    cout << "\n\n";
    cout << setw(120) << setfill('-') << "-";
    cout << "\n\n";
    cout << setw(75) << setfill(' ') << "Welcome to the University Database";
    cout << "\n\n";
    cout << setw(120) << setfill('-') << "-";
    cout << endl;
}

void mainScreen()
{
reenter:

    clrscr();
    displayHeader();

    cout << "\n\n";
    cout << "\t\t 1. STUDENT\n";
    cout << "\t\t 2. UNIVERSITY\n"; 
    cout << "\t\t 3. BRANCH\n";
    cout << "\t\t 0. EXIT\n";
   
    cout << "\n\n";
    cout << "\t\t Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            studentScreen();

        }break;

        case 2:
        {
            universityScreen();

        }break;

        case 3:
        {
            branchScreen();

        }break;

        case 0:
        {
            return;

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  
            
        }break;
    }

    goto reenter;
}


void universityScreen()
{
reenter:

    clrscr();
    displayHeader();
    cout << "\n";

    cout << "\t\t UNIVERSITY PORTAL";
    cout << "\n\t\t -----------------";
    
    cout << "\n\n";
    cout << "\t\t 1. Add a University to the Database \n";
    cout << "\t\t 2. View All Current Universities in the Database \n"; 
    cout << "\n\t\t 0. Return to previous menu\n";
    cout << "\t\t-1. Exit!\n";

    cout << "\n\n";
    cout << "\t\t Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            addUniversity();

        }break;

        case 2:
        {
            viewAllUniversity();

        }break;

        case 0:
        {
            return;

        }break;

        case -1:
        {
            exit(0);

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  

        }break;
    }

    goto reenter;
}

//Adds a University to the List of University
void addUniversity()
{
reenter:

    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY PORTAL";
    cout << "\n\t\t -----------------";

    cout << "\n\t\t Enter the University Details:";
    cout << "\n\n";

    University Untemp;
    Untemp.inputData();

    bool flag = false;  //we need this flag to check if university already exists or not

    //check uniqueness of the ID
    for (auto it = objUniversity.Ulist.begin(); it != objUniversity.Ulist.end(); ++it)
    {
        if(it->university_ID == Untemp.university_ID)
        {
            flag = true;
            break;
        }
    }

    if(flag == true)
    {
        cout << "\t\t The University ID entered already exists.\n";
        cout << "\t\t Press 1 to Re-Enter the Correct Details.\n";
        cout << "\t\t Press 0 to Return back to Previous Menu.\n";

        while(1)
        {
            cout << "\n\t\t Enter Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    goto reenter;

                }break;

                case 0:
                {
                    return;

                }break;

                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.";

                }break;
            }
        }
    }

    objUniversity.Ulist.push_back(Untemp);

    cout << "\n\t\t University Successfully added to the Database.\n";
    cout <<"\t\t Press Enter to return back.";
    cin.get(enter);

}

//View all the Universities in the List of Universities
void viewAllUniversity()
{

    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY PORTAL";
    cout << "\n\t\t -----------------";
    
    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    cout << "\t All Universities Currently in the Database: " << endl;
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    objUniversity.displayList();

    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";

    cout << "\t Total Universites in the Database: " << objUniversity.totalUniversities();
    
    cout << "\n\n\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);   

}

void branchScreen()
{
reenter:

    clrscr();
    displayHeader();
    cout << "\n";

    cout << "\t\t UNIVERSITY-BRANCH PORTAL";
    cout << "\n\t\t ------------------------";
    
    cout << "\n\n";
    cout << "\t\t 1. Add a Branch for a University in the Database \n";
    cout << "\t\t 2. View All Current Universities with their Branches in the Database \n"; 
    cout << "\n\t\t 0. Return to previous menu\n";
    cout << "\t\t-1. Exit!\n";

    cout << "\n\n";
    cout << "\t\t Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            addBranch();

        }break;

        case 2:
        {
            viewAllBranch(); 

        }break;

        case 0:
        {
            return;

        }break;

        case -1:
        {
            exit(0);

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  

        }break;
    }  

    goto reenter;
}

//Adds a Branch for a University
void addBranch()
{
reenter:

    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY-BRANCH PORTAL";
    cout << "\n\t\t ------------------------";

    cout << "\n\t\t Enter the Branch details:";
    cout << "\n\n";

    Branch Brtemp;
    Brtemp.inputData();
    
    bool Unflag = false;  //we need this flag to check if the university exists or not

    //first we check if the University ID exists or not.
    //if it exists then flag = true
    for (auto it = objUniversity.Ulist.begin(); it != objUniversity.Ulist.end(); ++it)
    {
        if(it->university_ID == Brtemp.university_ID)
        {
            Unflag = true;
            break;
        }
    }

    if(Unflag == false)
    {
        cout << "\t\t The University ID entered does not exist in the database.\n";
        cout << "\t\t Press 1 to Re-Enter the Correct Details.\n";
        cout << "\t\t Press 0 to Return back to Previous Menu.\n";

        while(1)
        {
            cout << "\n\t\t Enter Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    goto reenter;
                }break;

                case 0:
                {
                    return;
                }break;
                
                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.  ";

                }break;
            }
        }
    }

    bool Brflag = true;

    //check uniqueness of the branch ID
    for (auto it = objBranch.Blist.begin(); it != objBranch.Blist.end(); ++it)
    {
        if(it->branch_ID == Brtemp.branch_ID)
        {
            Brflag = false;
            break;
        }
    }

    if(Brflag == false)
    {
        cout << "\t\t The Branch ID is not unique. It already exists.\n";
        cout << "\t\t Press 1 to Re-Enter the Correct Details.\n";
        cout << "\t\t Press 0 to Return back to Previous Menu.\n";

        while(1)
        {
            cout << "\n\t\t Enter Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    goto reenter;
                }break;

                case 0:
                {
                    return;
                }break;
                
                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.  ";

                }break;
            }
        }
    }

    
    //we push the branch in a ordered manner such that all branches of a particular University grouped sequentially

    //this checks if the University has any previous entries for its branches
    //then it inserts it in front of the current iterator 
    auto it = objBranch.Blist.begin();
    while(it != objBranch.Blist.end())
    {
        if (it->university_ID == Brtemp.university_ID)
        {
            objBranch.Blist.insert(it, Brtemp);
            break;
        }
        ++it;
    }

    //else simply appends the branch to the end of the list
    if(it == objBranch.Blist.end())
        objBranch.Blist.push_back(Brtemp);

    cout << "\n\t\t Branch Successfully added to the University.\n";
    cout <<"\t\t Press Enter to return back.";
    cin.get(enter);
}

//View all the Universities with their Branches 
void viewAllBranch()
{
    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY-BRANCH PORTAL";
    cout << "\n\t\t -----------------------";
    
    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    cout << "\t All Universities with Branches Currently in the Database: " << endl;
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    objBranch.displayList();

    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";
    
    cout << "\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);   

}


void studentScreen()
{
reenter:

    clrscr();
    displayHeader();
    cout << "\n";

    cout << "\t\t UNIVERSITY-STUDENT PORTAL";
    cout << "\n\t\t -------------------------";
    
    cout << "\n\n";
    cout << "\t\t 1. Add a Student for a University Branch in the Database \n";
    cout << "\t\t 2. View All Current Students and their details in the Database \n"; 
    //cout << "\t\t 3. Seacrh for a Student in the Database \n";
    cout << "\n\t\t 0. Return to previous menu\n";
    cout << "\t\t-1. Exit!\n";

    cout << "\n\n";
    cout << "\t\t Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            addStudent();

        }break;

        case 2:
        {
            viewAllStudent(); 

        }break;
        
        case 3:
        {
            //TODO
            //searchStudent();

        }break;

        case 0:
        {
            return;

        }break;

        case -1:
        {
            exit(0);

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  

        }break;
    }  

    goto reenter;
}

//Adds a Student for a University Branch
void addStudent()
{
reenter:

    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY-STUDENT PORTAL";
    cout << "\n\t\t -------------------------";

    cout << "\n\t\t Enter the Student details:";
    cout << "\n\n";

    Student Sttemp;
    string StUniversityID;
    Sttemp.inputData();
    
    //flag that indicates whether
    //branch ID exists or not
    bool Brflag = false;    

    //first we check if the Branch ID exists or not.
    //if it exists then flag = true
    for (auto it = objBranch.Blist.begin(); it != objBranch.Blist.end(); ++it)
    {
        if(it->branch_ID == Sttemp.branch_ID)
        {
            Brflag = true;
            break;
        }

    }

    if(Brflag == false)
    {
        cout << "\t\t The Branch ID entered does not exist in the database.\n";
        cout << "\t\t Press 1 to Re-Enter the Correct Details.\n";
        cout << "\t\t Press 0 to Return back to Previous Menu.\n";

        while(1)
        {
            cout << "\n\t\t Enter Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    goto reenter;
                }break;

                case 0:
                {
                    return;
                }break;
                
                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.  ";

                }break;
            }
        }
    }

    //flag that indicates whether
    //Student roll no unique or not
    bool Stflag = true;    

    //to check whether Student roll no is unique or not
    for (auto it = objStudent.Slist.begin(); it != objStudent.Slist.end(); ++it)
    {
        if(it->roll_no == Sttemp.roll_no)
        {
            Stflag = false;
            break;
        }
    }

    if(Stflag == false)
    {
        cout << "\t\t Student Roll No not unique.\n";
        cout << "\t\t Press 1 to Re-Enter the Correct Details.\n";
        cout << "\t\t Press 0 to Return back to Previous Menu.\n";

        while(1)
        {
            cout << "\n\t\t Enter Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    goto reenter;
                }break;

                case 0:
                {
                    return;
                }break;
                
                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.  ";

                }break;
            }
        }
    }
    
    //we push the Students in a ordered manner such that all Students of a particular Branch grouped sequentially

    //this checks if the Branch has any previous entries for its Students
    //then it inserts it in front of the current iterator 
    auto it = objStudent.Slist.begin();
    while(it != objStudent.Slist.end())
    {
        if (it->branch_ID == Sttemp.branch_ID)
        {
            objStudent.Slist.insert(it, Sttemp);
            break;
        }
        ++it;
    }

    //else simply appends the branch to the end of the list
    if(it == objStudent.Slist.end())
        objStudent.Slist.push_back(Sttemp);

    cout << "\n\t\t Student successfully added in the database.\n";
    cout <<"\t\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);
}

//View all the Student details
void viewAllStudent()
{
    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY-STUDENT PORTAL";
    cout << "\n\t\t -----------------------";
    
    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    cout << "\t All Students Currently in the Database: " << endl;
    cout << setw(79) << setfill('-') << "-";
    cout << "\n";

    objStudent.displayList();

    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";
    
    cout << "\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);   

}

