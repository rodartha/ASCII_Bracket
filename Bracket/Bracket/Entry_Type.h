/**
* Entry_Type.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/23/18
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
    Top
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

    virtual friend std::ostream& operator<<(std::ostream &out, const Entry_Type &e) { }
    
    virtual ~Entry_Type() {}

private:
    Bracket_Place place;
};

#endif