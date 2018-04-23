/**
* Basic_Text.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/23/18
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
    Basic_Text() : Basic_Text("Not Initialized") { }

    Basic_Text(std::string t) : text(t) { }

    // FIXME:
    virtual friend std::ostream &operator<<(std::ostream &out, Basic_Text &b) 
    {
        return out << text;
    }

    virtual ~Basic_Text() {}
private:
    std::string text;
};

#endif