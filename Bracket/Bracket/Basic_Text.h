/**
* Basic_Text.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/24/18
*
* This file holds the class Basic_Text, a subclass of Entry_Type meant to
* represent any basic form of text entered into the bracket, These 
*/

#ifndef BASIC_TEXT_H_
#define BASIC_TEXT_H_

#include "Entry_Type.h"
#include <string>

class Basic_Text : public Entry_Type
{
public:
    Basic_Text() : Basic_Text("Not Initialized", Bracket_Place::Top) { }

    Basic_Text(std::string t, Bracket_Place p) : text(t), place(p) { }

    virtual Bracket_Place get_bracket_place()
    {
        return place;
    }

    virtual void set_bracket_place(Bracket_Place p)
    {
        place = p;
    }

    virtual int print_size()
    {
        // plus 4 for the two white space and '<>' in the print
        return static_cast<int>(text.size()) + 4;
    }

    friend std::ostream &operator<<(std::ostream &out, const Basic_Text &b) 
    {
        out << " __";
        for (size_t i = 0; i < b.text.size(); ++i)
        {
            out << "_";
        }
        if (b.place == Bracket_Place::Bottom)
        {
            out << '/';
        }
        out << "\n< " << b.text << " >\n";
        out << " --";
        for (size_t i = 0; i < b.text.size(); ++i)
        {
            out << "-";
        }
        if (b.place == Bracket_Place::Top)
        {
            out << '\\';
        }

        return out;
    }

    virtual ~Basic_Text() {}
private:
    std::string text;
    // Keeps track of whether top or bottom half of bracket entry
    Bracket_Place place;
};

#endif