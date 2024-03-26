#ifndef READER_CLASS_CPP
#define READER_CLASS_CPP

#include <iostream>
#include <algorithm>

#include "Reader_class.h"

void Reader::operator()()
{
    while (true)
    {
        std::string input;
        std::cout << "Enter a string of numbers (max. 64 characters) \nor enter 'exit' if you want to close the program: ";
        std::getline(std::cin, input);

        if (std::cin.eof() || input == "exit")
        {
            std::cout << "Program closed." << std::endl;
            exit(0);
        }

        if (!Reader::isValid(input))
        {
            std::cerr << "Input error! Try again." << std::endl;
            continue;
        }

        std::sort(input.begin(), input.end(), std::greater<char>());

        std::string handledString;
        for (char a : input)
        {
            if ((a - '0') % 2 == 0)
                handledString += "КВ";
            else
                handledString += a;
        }
    }
}

bool Reader::isValid(const std::string& str) const
{
    return str.size() <= 64 && str.find_first_not_of("0123456789") == std::string::npos;
}

#endif

