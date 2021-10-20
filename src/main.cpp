//for Sleep() function
//also for additional GUI later on
//Need to add this in a platform header
//////////////////////////
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>     //also need to implement usleep()    //ask Sir
#endif
//////////////////////////

#include <iostream>
#include <iomanip>
#include <list>

#include "Branch.h"
#include "University.h"
#include "Student.h"

using namespace std;

int choice; //stores the choice 
char enter;     //character for input of ENTER

//global UniversityList 
//we can also make the UniversityList class of static members
UniversityList obj_UnList;


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

int main()
{
    //login()

    mainScreen();

    return 0;
}


/*
______DISPLAY GUI________
*/

//to clear the console screen
//cls -- windows
//clear -- linux
inline void clrscr()
{
    system("CLS || CLEAR");
}

void displayHeader()
{
    cout << "\n\n";
    cout << setw(120) << setfill('-') << "-";
    cout << "\n\n";
    cout << setw(75) << setfill(' ') << "Welcome to the University-Student Database";
    cout << "\n\n";
    cout << setw(120) << setfill('-') << "-";
    cout << endl;
}

//maybe we can have login/signup window for admins 
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
            Sleep(700);
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
            cout << "\n\nTODO. NOT IMPLEMENTED.";
            Sleep(700);
            mainScreen();

            //branchScreen();
        }break;

        case 0:
        {
            //add a logout use
            //right now 0 exits the program
            return;

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Please Enter Again.";
            Sleep(700);
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
            return;

        }break;

        default:
        {
            //in case of a wrong input

            cout << "\t\t Wrong Input. Please Enter Again.";
            Sleep(700);
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
            cout << "\t\t The ID entered already exists.\n";
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

                    case 2:
                    {
                        clrscr();
                        universityScreen();
                    }break;

                    
                    default:
                    {
                        //in case of wrong input
                        cout << "\t\t Wrong Input. Please Enter Again.";
                        Sleep(500);

                    }break;
                }
            }
        }
    }

    obj_UnList.Ulist.push_back(un_temp);

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

    obj_UnList.displayList();

    cout << setw(79) << setfill('-') << "-";
    cout << "\n\n";

    cout << "\t Total Universites in the Database: " << obj_UnList.totalUniversities();
    
    cout << "\n\n\t Press Enter to return back.";
    cin.ignore();
    cin.get(enter);   

}

//TODO
void branchScreen()
{

}

//TODO
void studentScreen()
{

}