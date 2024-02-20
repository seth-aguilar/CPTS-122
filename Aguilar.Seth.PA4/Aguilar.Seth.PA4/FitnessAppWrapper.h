#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper
{
public:

	// constructor
	FitnessAppWrapper();

	// destructor
	~FitnessAppWrapper();

	// getters

	void runApp(void);
	void loadDailyPlan(std::istream& fileStream, DietPlan& plan);
	void loadDailyPlan(std::istream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(std::istream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(std::istream& fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan plan);
	void displayDailyPlan(const ExercisePlan plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void displayWeeklyPlan(const ExercisePlan weeklyPlan[]);
	void storeDailyPlan(std::ofstream& fileStream, const DietPlan plan);
	void storeDailyPlan(std::ofstream& fileStream, const ExercisePlan plan);
	void storeWeeklyPlan(std::ofstream& fileStream, const DietPlan weeklyPlan[]);
	void storeWeeklyPlan(std::ofstream& fileStream, const ExercisePlan weeklyPlan[]);
	void displayMenu(void);
private:
	DietPlan dietWeeklyPlan[7];
	ExercisePlan exerciseWeeklyPlan[7];
};