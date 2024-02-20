#include "ExercisePlan.h"

std::ostream& operator<<(std::ostream& ostream, const ExercisePlan& plan)
{
    ostream << "Name: " << plan.getName() << std::endl;
    ostream << "Date: " << plan.getDate() << std::endl;
    ostream << "Goal: " << plan.getGoal() << std::endl;
    return ostream;
}

std::ofstream& operator<<(std::ofstream& ofstream, const ExercisePlan& plan)
{
    ofstream << plan.getName() << std::endl;
    ofstream << plan.getDate() << std::endl;
    ofstream << plan.getGoal() << std::endl;
    ofstream << std::endl;
    return ofstream;
}

std::istream& operator>>(std::istream& ifstream, ExercisePlan& plan)
{
    std::string name, date;
    std::string line;
    int goal;
    // read the goal, name, and date from the input file stream
    std::getline(ifstream, name);
    ifstream >> goal;
    std::getline(ifstream, date);
    std::getline(ifstream, line);
    plan.setName(name);
    plan.setDate(date);
    plan.setGoal(goal);
    // return a reference to the input file stream to allow chaining of input operations
    return ifstream;
}

ExercisePlan::ExercisePlan()
{
    goal = 0;
    name = "";
    date = "";
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
    goal = copy.goal;
    name = copy.name;
    date = copy.date;
}

ExercisePlan::~ExercisePlan()
{
}

void ExercisePlan::setGoal(const int& newGoal)
{
    goal = newGoal;
}

void ExercisePlan::setName(const std::string& newName)
{
    name = newName;
}

void ExercisePlan::setDate(const std::string& newDate)
{
    date = newDate;
}

int ExercisePlan::getGoal() const
{
    return goal;
}

std::string ExercisePlan::getName() const
{
    return name;
}

std::string ExercisePlan::getDate() const
{
    return date;
}

void ExercisePlan::editGoal()
{
    int newGoal;

    std::cout << "Enter new goal value: ";
    std::cin >> newGoal;

    setGoal(newGoal);
}
