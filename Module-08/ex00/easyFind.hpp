#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundOcurrenceException : std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "*ERROR* Not found occurence";
        }
};

#include "easyFind.tpp"

#endif