/**
* Bracket.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/24/18
*
* This file holds the Bracket class which contains the bracket itself and
* handles the main processes of the program.
*/

#ifndef BRACKET_H_
#define BRACKET_H_

#include<fstream>
#include <vector>

#include "Bye.h"
#include "Basic_Text.h"

using namespace std;

// Keeps track of what type of bracket this is:
enum class Type_of_Entry
{
    Basic_Text,
    Song
};

class Bracket
{
public:
    Bracket() : Bracket("ERROR", Type_of_Entry::Basic_Text) {}

    Bracket(string f, Type_of_Entry e) : filename(f), entry_type(e) {}

    // Main Function, handles all abilities of bracket class:
    void run_bracket()
    {
        read_file();
    }

    ~Bracket() 
    {
        for (size_t i = 0; i < Entries.size(); ++i)
        {
            delete Entries[i];
            Entries[i] = nullptr;
        }
    }
private:
    vector <Entry_Type*> Entries;
    string filename;
    Type_of_Entry entry_type;

    // Reads the file into Entries:
    void read_file()
    {
        string file_ending = filename.substr(filename.size() - 4);

        if (file_ending != ".txt")
        {
            cerr << "Error: The file input was not a .txt file\n";
            exit(EXIT_FAILURE);
        }

        ifstream fin;
        fin.open(filename);

        if (!fin.is_open())
        {
            cerr << "Error opening file " << filename << "\n";
            exit(EXIT_FAILURE);
        }

        if (entry_type == Type_of_Entry::Basic_Text)
        {
            read_file_Basic_Text(fin);
        }
        else if (entry_type == Type_of_Entry::Song)
        {
            read_file_Song(fin);
        }
    }

    void read_file_Basic_Text(ifstream &fin)
    {

    }


    // TODO: make/fix
    void read_file_Song(ifstream &fin)
    {

    }
};

#endif