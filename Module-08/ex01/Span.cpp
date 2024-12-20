#include"Span.hpp"

class Span::IsFullException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "[ERROR] Span is full";
        }
};

class Span::NotEnoughNumbersException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "[ERROR] Not enough numbers in Span";
        }
};

Span::Span() : v(new std::vector<int>())
{
    (*this->v).reserve(0);
}


Span::Span(unsigned int n) : v(new std::vector<int>())
{
    (*this->v).reserve(n);
}

Span::Span(Span const &o)
{
    *this = o;
}

Span::~Span()
{ 
    delete v; 
}

Span &Span::operator=(Span const &o)
{
    this->v = o.v;
    return *this;
}

void Span::addNumber(int n)
{
    if (this->v->size() == this->v->capacity())
        throw IsFullException();
    this->v->push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->v->size() + std::distance(begin, end) > this->v->capacity())
        throw Span::IsFullException();

    std::vector<int>::iterator iter = this->v->begin();
    std::advance(iter, this->v->size());

    this->v->insert(iter, begin, end);
}

unsigned int Span::shortestSpan()
{
    if (this->v->size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> tmp = *this->v;
    int min = INT_MAX;
    for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end() - 1; iter++)
    {
        min = std::abs(*(iter + 1) - *iter) < min ? std::abs(*(iter + 1) - *iter) : min;
    }
    return (min == INT_MAX) ? 0 : min;
}

unsigned int Span::longestSpan()
{
    if (this->v->size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> tmp = *this->v;
    int max = INT_MIN;
    for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end() - 1; iter++)
        max = std::abs(*(iter + 1) - *iter) > max ? std::abs(*(iter + 1) - *iter) : max;
    return (max == INT_MIN) ? 0 : max;
}