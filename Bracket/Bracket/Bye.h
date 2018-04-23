/**
* Bye.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/23/18
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
    Bye() { }

    // FIXME:
    virtual friend std::ostream &operator<<(std::ostream &out, Bye &b)
    {
        return out << "Bye\n";
    }

    virtual ~Bye() {}
};

#endif