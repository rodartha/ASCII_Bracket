/**
* Driver.cpp
*
* ASCII Bracket Program
* Colin Page
* cwpage@umich.edu
*
* Version: 0.0
* Last Edited: 4/23/18
*
* This File holds the driver for the bracket function:
*/

#include <string>

#include "Errors_and_help.h"
#include "Bracket.h"

// Handles finding getopt.h on linux and windows
#if defined(__GNUC__)
#include <getopt.h>
#elif defined(_MSC_VER)
#include "getopt.h"
#else
#error Unsupported compiler
#endif

using namespace std;

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);

    static struct option longopts[] = {
        { "help", no_argument, nullptr, 'h' },
        { "info", no_argument, nullptr, 'i' },
        { "type", required_argument, nullptr, 't' },
        { "file", required_argument, nullptr, 'f' },
        { nullptr, 0, nullptr, 0 }
    };

    int index = 0;
    int c;

    bool type_seen = false;
    string type;

    bool file_seen = false;
    string file;

    while ((c = getopt_long(argc, argv, "hit:f:", longopts, &index)) != -1)
    {
        switch (c)
        {
        case 'h':
            help();
            break;
        case 'i':
            info();
            break;
        case 't':
            if (!type_seen)
            {
                type_seen = true;
                type = optarg;
            }
            else
            {
                incorrect_args();
            }
            break;
        case 'f':
            if (!file_seen)
            {
                file_seen = true;
                file = optarg;
            }
            else
            {
                incorrect_args();
            }
            break;
        default:
            incorrect_args();
            break;
        }

    }

    if (!type_seen || !file_seen)
    {
        incorrect_args();
    }

    Type_of_Entry t;

    // Update as new types come out:
    if (type == "Basic_Text")
    {
        t = Type_of_Entry::Basic_Text;
    }
    else if (type == "Song")
    {
        t = Type_of_Entry::Song;
    }

    Bracket b(file, t);
    b.read_file();

    return 0;
}