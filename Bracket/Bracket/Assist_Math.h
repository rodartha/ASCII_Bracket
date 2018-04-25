/**
* Assist_Math.h
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/25/18
*
* This file holds math functions that assist the program in running efficiently
*/

#ifndef ASSIST_MATH_H_
#define ASSIST_MATH_H_

#include <math.h>

// Returns true if x is a power of two
bool is_power_of_two(int x)
{
    if (ceil(log2(x)) == floor(log2(x)))
    {
        return true;
    }

    return false;
}

// If x is not a power of two, returns closest number that is
int closest_power_of_two(int x)
{
    int set_pos = ceil(log2(x));
    return pow(2, set_pos);
}

bool is_even(int x)
{
    if ((x % 2) == 0)
    {
        return true;
    }

    return false;
}

#endif