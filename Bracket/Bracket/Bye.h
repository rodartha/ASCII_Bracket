/**
* Bye.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/24/18
*
* This file holds the class Bye, a subclass of Entry_Type meant to
* represent an empty spot in the bracket in which a "competitor" has a
* bye week
*/

#ifndef BYE_H_
#define BYE_H_

#include "Entry_Type.h"

class Bye : public Entry_Type
{
public:
    Bye() : Bye(Bracket_Place::Top) { }

    Bye(Bracket_Place p) : place(p) { }

    virtual Bracket_Place get_bracket_place()
    {
        return place;
    }

    virtual void set_bracket_place(Bracket_Place p)
    {
        place = p;
    }

    friend std::ostream &operator<<(std::ostream &out, const Bye &b)
    {
        out << " _____";
        if (b.place == Bracket_Place::Bottom)
        {
            out << '/';
        }
        out << "\n< Bye >\n -----";
        if (b.place == Bracket_Place::Top)
        {
            out << '\\';
        }
        return out;
    }

    virtual ~Bye() {}
private:
    // Keeps track of whether top or bottom half of bracket entry
    Bracket_Place place;
};

#endif