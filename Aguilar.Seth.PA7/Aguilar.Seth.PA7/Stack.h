#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Stack 
{
public:
    Stack();

    void push(const std::string& date);

    std::string pop();

    std::string peek();

    bool isEmpty();
private:
    std::vector<std::string> dates;
};