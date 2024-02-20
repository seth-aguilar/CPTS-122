#include "DietPlan.h"

std::ostream& operator<<(std::ostream& ostream, const DietPlan& plan)
{
    ostream << "Name: " << plan.getName() << std::endl;
    ostream << "Date: " << plan.getDate() << std::endl;
    ostream << "Goal: " << plan.getGoal() << std::endl;
    return ostream;
}

std::ofstream& operator<<(std::ofstream& ofstream, const DietPlan& plan)
{
    ofstream << plan.getName() << std::endl;
    ofstream << plan.getDate() << std::endl;
    ofstream << plan.getGoal() << std::endl;
    ofstream << std::endl;
    return ofstream;
}

std::istream& operator>>(std::istream& ifstream, DietPlan& plan)
{    
    std::string name, date;
    std::string line;
    int goal;
    // read the goal, name, and date from the input file stream
    ifstream >> name;
    ifstream >> goal;
    ifstream >> date;
    std::getline(ifstream, line);
    plan.setName(name);
    plan.setDate(date);
    plan.setGoal(goal);
    // return a reference to the input file stream to allow chaining of input operations
    return ifstream;
}

DietPlan::DietPlan()
{
    goal = 0;
    name = "";
    date = "";
}

DietPlan::DietPlan(const DietPlan& copy)
{
    goal = copy.goal;
    name = copy.name;
    date = copy.date;
}

DietPlan::~DietPlan()
{
}

void DietPlan::setGoal(const int& newGoal)
{
    goal = newGoal;
}

void DietPlan::setName(const std::string& newName)
{
    name = newName;
}

void DietPlan::setDate(const std::string& newDate)
{
    date = newDate;
}

int DietPlan::getGoal() const
{
    return goal;
}

std::string DietPlan::getName() const
{
    return name;
}

std::string DietPlan::getDate() const
{
    return date;
}

void DietPlan::editGoal()
{
    int newGoal;

    std::cout << "Enter new goal value: ";
    std::cin >> newGoal;

    setGoal(newGoal);
}
