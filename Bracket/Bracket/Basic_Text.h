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

    virtual ~Basic_Text() {}
private:
    std::string text;
    // Keeps track of whether top or bottom half of bracket entry
    Bracket_Place place;

    virtual std::ostream& print(std::ostream &out)
    {
        out << " __";
        for (size_t i = 0; i < text.size(); ++i)
        {
            out << "_";
        }
        if (place == Bracket_Place::Bottom)
        {
            out << '/';
        }
        out << "\n< " << text << " >\n";
        out << " --";
        for (size_t i = 0; i < text.size(); ++i)
        {
            out << "-";
        }
        if (place == Bracket_Place::Top)
        {
            out << '\\';
        }
        out << '\n';
        return out;
    }
};

#endif