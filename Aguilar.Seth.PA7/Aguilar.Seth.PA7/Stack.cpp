#include "Stack.h"

Stack::Stack()
{
}

void Stack::push(const std::string& date)
{
    dates.push_back(date);
}

std::string Stack::pop()
{
    if (isEmpty()) 
    {
        std::cout << "Stack is empty." << std::endl;
        return nullptr;
    }
    std::string date = dates.back();
    dates.pop_back();
    return date;
}

std::string Stack::peek()
{
    if (isEmpty()) 
    {
        std::cout << "Stack is empty." << std::endl;
        return nullptr;
    }
    return dates.back();
}

bool Stack::isEmpty()
{
    return dates.empty();
}