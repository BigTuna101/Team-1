#include <iostream>
#include <iomanip>
#include <list>

#include "Branch.h"
#include "University.h"
#include "Student.h"

using namespace std;

int choice;     //stores the choice 
char enter;     //character for input of ENTER

//global UniversityList, BranchList
UniversityList obj_UnList;
BranchList obj_BrList;

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


int main()
{
    //login()

    mainScreen();

    return 0;
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

//TODO: maybe later we can have login/signup screen for admins / students
// void login() {   }

void mainScreen()
{
    clrscr();
    displayHeader();

    cout << "\n\n";
    cout << "\t\t 1. STUDENT\n";
    cout << "\t\t 2. UNIVERSITY\n"; 
    cout << "\t\t 3. BRANCH\n";
    cout << "\t\t 0. EXIT\n";

    //cout << "\t\t 0. LOGOUT\n";
    
    cout << "\n\n";
    cout << "\t\t Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "\n\nTODO. NOT IMPLEMENTED.";
            cout << "Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  
            mainScreen();

            //studentScreen();

        }break;

        case 2:
        {
            universityScreen();
            mainScreen();

        }break;

        case 3:
        {
            branchScreen();
            mainScreen();

        }break;

        case 0:
        {
            //add a logout use
            //right now 0 exits the program

            exit(0);

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Press Enter to return back.";
            cin.ignore(1000, '\n');
            cin.get(enter);  
            mainScreen();
            
        }break;
    }
    
}


void universityScreen()
{
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
            universityScreen();

        }break;

        case 2:
        {
            viewAllUniversity();
            universityScreen();   

        }break;

        case 0:
        {
            mainScreen();

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
            universityScreen();

        }break;
    }
}

//Adds a University to the List of University
void addUniversity()
{
    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY PORTAL";
    cout << "\n\t\t -----------------";

    cout << "\n\t\t Enter the University Details:";
    cout << "\n\n";

    University un_temp;
    un_temp.inputData();

    //check uniqueness of the ID
    for (auto it = obj_UnList.Ulist.begin(); it != obj_UnList.Ulist.end(); ++it)
    {
        if(it->university_ID == un_temp.university_ID)
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
                        clrscr();
                        addUniversity();
                    }break;

                    case 0:
                    {
                        clrscr();
                        universityScreen();
                    }break;

                    
                    default:
                    {
                        //in case of wrong input
                        cout << "\t\t Wrong Input. Please Enter Again.";

                    }break;
                }
            }
        }
    }

    obj_UnList.Ulist.push_back(un_temp);

    cout << "\n\t\t University Successfully added to the Database.\n";
    cout <<"\t\t Press Enter to return back.";
    cin.ignore(1000, '\n');
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

    obj_UnList.displayList();

    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";

    cout << "\t Total Universites in the Database: " << obj_UnList.totalUniversities();
    
    cout << "\n\n\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);   

}


void branchScreen()
{
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
            branchScreen();

        }break;

        case 2:
        {
            viewAllBranch();
            branchScreen();   

        }break;

        case 0:
        {
            mainScreen();

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
            branchScreen();

        }break;
    }  
}

//Adds a Branch for a University
void addBranch()
{
    clrscr();
    displayHeader();

    cout << "\t\t UNIVERSITY-BRANCH PORTAL";
    cout << "\n\t\t ------------------------";

    cout << "\n\t\t Enter the Branch details:";
    cout << "\n\n";

    Branch br_temp;
    br_temp.inputData();
    
    bool flag = false;  //we need this flag to check if university exists or not

    //first we check if the University ID exists or not.
    //if not then flag = false
    for (auto it = obj_UnList.Ulist.begin(); it != obj_UnList.Ulist.end(); ++it)
    {
        if(it->university_ID == br_temp.university_ID)
        {
            flag = true;
            break;
        }
    }

    if(flag == false)
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
                    clrscr();
                    addBranch();
                }break;

                case 0:
                {
                    clrscr();
                    branchScreen();
                }break;

                
                default:
                {
                    //in case of wrong input
                    cout << "\t\t Wrong Input. Please Enter Again.  ";

                }break;
            }
        }
    }


    //check uniqueness of the ID
    for (auto it = obj_BrList.Blist.begin(); it != obj_BrList.Blist.end(); ++it)
    {
        if(it->branch_ID == br_temp.branch_ID)
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
                        clrscr();
                        addBranch();
                    }break;

                    case 0:
                    {
                        clrscr();
                        branchScreen();
                    }break;

                    
                    default:
                    {
                        //in case of wrong input
                        cout << "\t\t Wrong Input. Please Enter Again.";

                    }break;
                }
            }
        }
    }


    //we push the branch in a ordered manner such that all branches of a particular University grouped sequentially

    //this checks if the branch of a University ID exists
    //then it inserts it in front of the current iterator 
    auto it = obj_BrList.Blist.begin();
    while(it != obj_BrList.Blist.end())
    {
        if (it->university_ID == br_temp.university_ID)
        {
            obj_BrList.Blist.insert(it, br_temp);
            break;
        }
        ++it;
    }

    //else simply appends the branch to the end of the list
    if(it == obj_BrList.Blist.end())
        obj_BrList.Blist.push_back(br_temp);



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

    obj_BrList.displayList();

    cout << "\n";
    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";
    
    cout << "\t Press Enter to return back.";
    cin.ignore(1000, '\n');
    cin.get(enter);   

}


//TODO
void studentScreen()
{

}