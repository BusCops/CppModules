#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
  public:
typedef typename std::stack<T, container>::container_type::iterator iterator;
typedef typename std::stack<T, container>::container_type::const_iterator const_iterator;

    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <typename T, typename container>
MutantStack<T, container>::MutantStack() : std::stack<T, container>()
{
}

template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack &other)
    : std::stack<T, container>(other)
{
}

template <typename T, typename container>
MutantStack<T, container>::~MutantStack()
{
}

template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin()
{
    return this->c.begin();
}

template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end()
{
    return this->c.end();
}

template <typename T, typename container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::begin() const
{
    return this->c.begin();
}

template <typename T, typename container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::end() const
{
    return this->c.end();
}

template <typename T, typename container>
MutantStack<T, container> &MutantStack<T, container>::operator=(const MutantStack &other)
{
    if (this != &other)
    {
        this->c = other.c;
    }
    return *this;
}

#endif