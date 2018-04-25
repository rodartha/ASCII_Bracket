/**
* Entry_Type.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/24/18
*
* This file holds the abstract class entry type from which all specific
* Entry type classes are derived
*/

#ifndef ENTRY_TYPE_H_
#define ENTRY_TYPE_H_

#include <iostream>

enum class Bracket_Place 
{
    Bottom,
    Top,
    Winner
};

class Entry_Type
{
public:
    Entry_Type(Bracket_Place p) : place(p) {}

    Entry_Type() : Entry_Type(Bracket_Place::Top) {}

    virtual Bracket_Place get_bracket_place()
    {
        return place;
    }

    virtual void set_bracket_place(Bracket_Place p)
    {
        place = p;
    }

    /**
    * Returns size in characters of printed output when operator<< used
    * to allow the Bracket class to print properly
    */
    virtual int print_size()
    {
        return 0;
    }

    virtual std::ostream& print(std::ostream &out) { return out; }

    friend std::ostream& operator<<(std::ostream &out, Entry_Type &e) { return e.print(out); }
    
    virtual ~Entry_Type() {}

private:
    // Keeps track of whether top or bottom half of bracket entry
    Bracket_Place place;
};

#endif