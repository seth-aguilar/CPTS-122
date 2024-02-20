#pragma once

#include <iostream>
#include <fstream>
#include <string>

class ExercisePlan
{
public:

	// constructor
	ExercisePlan();

	// copy constructor
	ExercisePlan(const ExercisePlan& copy);

	// destructor
	~ExercisePlan();

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
std::ostream& operator<<(std::ostream& os, const ExercisePlan& plan);

// Overloaded stream insertion operator for writing a plan to a file
std::ofstream& operator<<(std::ofstream& ofs, const ExercisePlan& plan);

// Overloaded stream extraction operator for reading a plan from a file
std::istream& operator>>(std::istream& ifstream, ExercisePlan& plan);