#pragma once

#include <iostream>
#include <fstream>
#include <string>

class DietPlan
{
public:

	// constructor
	DietPlan();

	// copy constructor
	DietPlan(const DietPlan& copy);

	// destructor
	~DietPlan();

	// setter
	void setGoal(const int& newGoal);
	void setName(const std::string& newName);
	void setDate(const std::string& newDate);

	//getter
	int getGoal() const;
	std::string getName() const;
	std::string getDate() const;

	// edit goal
	void editGoal();

private:
	int goal;
	std::string name;
	std::string date;
};

// Overloaded stream insertion operator for displaying a plan to the screen
std::ostream& operator<<(std::ostream& ostream, const DietPlan& plan);

// Overloaded stream insertion operator for writing a plan to a file
std::ofstream& operator<<(std::ofstream& ofstream, const DietPlan& plan);

// Overloaded stream extraction operator for reading a plan from a file
std::istream& operator>>(std::istream& ifstream, DietPlan& plan);