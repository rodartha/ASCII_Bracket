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

class Entry_Type
{
public:
    virtual friend std::ostream& operator<<(std::ostream &out, const Entry_Type &e) { }
    
    virtual ~Entry_Type() {}
};

#endif