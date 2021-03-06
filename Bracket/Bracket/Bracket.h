/**
* Bracket.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/25/18
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
#include "Assist_Math.h"

using namespace std;

// Keeps track of what type of bracket this is:
enum class Type_of_Entry
{
    Basic_Text,
    Song
};

enum class Winner
{
    Top,
    Bottom,
    Undecided
};

class Bracket
{
public:
    Bracket() : Bracket("ERROR", Type_of_Entry::Basic_Text) {}

    Bracket(string f, Type_of_Entry e) : filename(f), entry_type(e) {}

    // Main Function, handles all abilities of bracket class:
    void run_bracket()
    {
        // NOTE: need to check if a round has even elements to know if bye needed:
    }

    void print()
    {
        print_header();
    }

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

        char quotation;
        fin >> quotation;
        if (quotation != '\"')
        {
            cerr << "Title is not formatted properly, should be formatted: \"Title\" [NEW LINE]\n";
            exit(EXIT_FAILURE);
        }

        // Grabs the title of the bracket
        getline(fin, title, '\"');
        string empty_end_of_line;
        getline(fin, empty_end_of_line);

        if (entry_type == Type_of_Entry::Basic_Text)
        {
            read_file_Basic_Text(fin);
        }
        else if (entry_type == Type_of_Entry::Song)
        {
            read_file_Song(fin);
        }

        // Set the total size of the bracket and elements left in it.
        total_size = Entries.size();
        elements_left = total_size;

        // Finds the number of rounds:
        int size_rounded = static_cast<int>(total_size);
        if (!is_power_of_two(size_rounded))
        {
            size_rounded = closest_power_of_two(size_rounded);
        }

        total_rounds = log2(size_rounded);
        rounds_left = total_rounds;

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
    // Tracks what type of entry each entry is
    vector <string> entry_tracker;
    string filename;
    string title;
    Type_of_Entry entry_type;
    size_t total_size;
    size_t elements_left;
    int total_rounds;
    int rounds_left;

    void read_file_Basic_Text(ifstream &fin)
    {
        string line_text;
        int num_elements = 0;

        while (getline(fin, line_text))
        {
            Bracket_Place b;

            // Determines whether its a top half of bracket or bottom
            if (num_elements % 2 == 0)
            {
                b = Bracket_Place::Top;
            }
            else
            {
                b = Bracket_Place::Bottom;
            }

            if (line_text == "BYE")
            {
                Entries.push_back(new Bye(b));
                entry_tracker.push_back("BYE");
            }
            else
            {
                Entries.push_back(new Basic_Text(line_text, b));
                entry_tracker.push_back("Basic_Text");
            }

            num_elements++;
        }

        // If odd need to end final bye week:
        if (!is_even(num_elements))
        {
            Entries.push_back(new Bye(Bracket_Place::Top));
            entry_tracker.push_back("BYE");
        }
    }

    // TODO: make/fix
    void read_file_Song(ifstream &fin)
    {

    }

    void print_header()
    {
        cout << "::: " << title << " Bracket :::\n";
        cout << "Elements left in bracket: " << elements_left
            << " | Rounds left: " << rounds_left << " out of " << total_rounds << '\n';
    }

    /** index_top, index_bottom represent the index of the two bracket entries
    * being printed. If w == winner, a winner has not yet been selected, otherwise
    * the winner is the end of the bracket denoted by w
    */
    void print_bracket_section(const int index_top, 
        const int index_bottom, Bracket_Place w)
    {
        if (entry_tracker[index_top] == "BYE")
        {
            w = Bracket_Place::Bottom;
        }
        else if (entry_tracker[index_bottom] == "BYE")
        {
            w = Bracket_Place::Top;
        }

        // TODO: continue work on this
        cout << *(Entries[index_top]);
        cout << *(Entries[index_bottom]);
    }
};

#endif