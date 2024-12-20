#ifndef EASY_FIND_TPP
# define EASY_FIND_TPP

template <typename T>
int easyFind(T &container, int value)
{
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw NotFoundOcurrenceException();
    return *iter;
}

template <typename T>
int easyfind(T const &container, int value)
{
    typename T::iterator  iter;

    iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw NotFoundOcurrenceException();
    return (*iter);
}

#endif