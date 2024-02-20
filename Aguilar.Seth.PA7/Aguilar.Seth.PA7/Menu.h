#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>

#include "Data.h"
#include "List.h"
#include "Node.h"
#include "Stack.h"

class Menu 
{
public:
    void displayMenu();
    void importCourseList(List<Node<Data>>* masterList);
    void loadMasterList(List<Node<Data>>* masterList);
    void storeMasterList(List<Node<Data>>* masterList);
    void markAbsences(List<Node<Data>>* masterList);
    void editAbsences(List<Node<Data>>* masterList); // Bonus - Not implemented
    void generateReport(List<Node<Data>>* masterList);
};