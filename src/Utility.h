#ifndef UTILITY_H
#define UTILITY_H

//////////////////////////////
//for additional GUI later on
// #ifdef _WIN32
//     #include <Windows.h>
// #else
//     #include <unistd.h>     
// #endif

//////////////////////////////

#include <string>
#include <cctype>
#include <cstdlib>


//capitalize the Name
void capitalize(std::string &str)
{
    for (int i = 0; i != str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

//to clear the console screen
//cls -- windows
//clear -- linux
inline void clrscr()
{
    system("CLS || CLEAR");
}


#endif