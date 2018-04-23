/**
* Errors_and_help.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/23/18
*
* This file holds functions that handle error commands as well as the functions that handle
* the help and info messages from the command line.
*/

#ifndef ERRORS_AND_HELP_H_
#define ERRORS_AND_HELP_H_

#include <iostream>
#include <string>


using namespace std;

// CONSTANT VALUES
// UPDATE:

// FIXME
const string VALID_TYPES[2] = {"Basic Text", "Song"};
const int NUM_TYPES = 2;

void help()
{
    cout << "This program takes in a file, creates a bracket from the file and\n";
    cout << "allows a user to then vote on items in the bracket until there is a\n";
    cout << "winner. The command line arguments taken by this program are listed below:\n\n";
    cout << "1) -h/--help\n";
    cout << "2) -i/--info\n";
    cout << "3) -t/--type <type_of_obj>\n";
    cout << "4) -f/--file <file_of_bracket>\n";
    cout << "To learn about any command specifically please enter a number corresponding\n";
    cout << "with its number on the list. If you are done and wish to restart the program\n";
    cout << "please enter [d]\n";

    int user_input;
    cin >> user_input;

    while (user_input != 'd' && user_input != 'm')
    {
        if (user_input == 1 || user_input == 2 || user_input == 3 || user_input == 4)
        {
            user_input = command_help(user_input);
        }
        else
        {
            cout << "The only valid options are: 1, 2, 3, 4, or 'd'\n Please try again: ";
            cin >> user_input;
        }
    }

    if (user_input == 'd')
    {
        cout << "Program exiting\n";
        exit(0);
    }
    else if (user_input == 'm')
    {
        help();
    }
}

char command_help(int help_choice)
{
    switch (help_choice)
    {
    case 1:
        cout << "-h/--help \n";
        cout << "This is an OPTIONAL command that allows the user to access the help\n";
        cout << "menu should they need help understanding other argument options\n";
        break;
    case 2:
        cout << "-i/--info \n";
        cout << "This is an OPTIONAL command that allows the user to access the info\n";
        cout << "menu that provides information about the program\n";
        break;
    case 3:
        cout << "-t/--type \n";
        cout << "This is a REQUIRED command that should be followed by a type that defines\n";
        cout << "what type of objects the bracket will consist of. The current valid types are:\n";
        for (int i = 0; i < NUM_TYPES; ++i)
        {
            cout << i << ") " << VALID_TYPES[i] << "\n";
        }
        break;
    case 4:
        cout << "-f/--file \n";
        cout << "This is a REQUIRED command that should be followed by the name of a text file\n";
        cout << "that holds the elements that will be placed into the bracket. The file must be entered\n";
        cout << "as follows: [file_name.txt] (minus the brackets). Within the file itself, the format\n";
        // FIXME: add format explanation + defintion:
        cout << "should be: \n";
        break;
    default:
        cout << "You broke my program, nice! :) \n";
        break;
    }

    char user_input;
    cout << "You may now either enter 'd' to exit the program or 'm' to return\n"
        << "to the main menu: ";
    cin >> user_input;

    while (user_input != 'd' && user_input != 'm')
    {
        "Error, your answer was neither 'd' nor 'm', please try again: ";
        cin >> user_input;
    }

    return user_input;
}

void info()
{
    // FIXME: add info about the program

    exit(0);
}

void incorrect_args()
{
    cerr << "Error: usage: [OPTIONAL]-h/--help [OPTIONAL]-i/--info [REQUIRED]-t/--type"
        << " <type_of_obj_in_bracket> [REQUIRED]-f/--file <name_of_file.txt> \n";

    exit(1);
}

#endif