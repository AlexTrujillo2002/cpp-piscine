#include "easyFind.hpp"

#include <vector>
#include <list>


int main()
{
    std::vector<int>    v;
    std::list<int>      l;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    try
    {
        std::cout << easyFind(v, 3) << std::endl;
        std::cout << easyFind(l, 2) << std::endl;
        std::cout << easyFind(v, 4) << std::endl;
        std::cout << easyFind(v, 5) << std::endl;
        std::cout << easyFind(l, 5) << std::endl;
    }
    catch (const NotFoundOcurrenceException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}