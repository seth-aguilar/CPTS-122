#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{

}

FitnessAppWrapper::~FitnessAppWrapper()
{
}

void FitnessAppWrapper::runApp(void)
{
	int choice = 0;
	std::ifstream ifstream; // construct an input file stream
	std::ofstream ofstream; // contruct an output file stream

	FitnessAppWrapper fitnessPlan;

	while (choice != 9)
	{
		do
		{
			system("cls");
			displayMenu();
			std::cin >> choice;
		} while (choice < 1 || choice > 9);

		switch (choice)
		{
		case 1:
			system("cls");

			ifstream.open("dietPlans.txt", std::ios::in); // input stream - read - 
			if (!ifstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.loadWeeklyPlan(ifstream, fitnessPlan.dietWeeklyPlan);

			ifstream.close();

			break;
		case 2:
			system("cls");

			ifstream.open("exercisePlans.txt", std::ios::in); // input stream - read - 
			if (!ifstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.loadWeeklyPlan(ifstream, fitnessPlan.exerciseWeeklyPlan);

			ifstream.close();

			break;
		case 3:
			system("cls");

			ofstream.open("dietPlans.txt", std::ios::out); // input stream - read - 
			if (!ofstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.storeWeeklyPlan(ofstream, fitnessPlan.dietWeeklyPlan);

			ofstream.close();

			break;
		case 4:
			system("cls");

			ofstream.open("exercisePlans.txt", std::ios::out); // input stream - read - 
			if (!ofstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.storeWeeklyPlan(ofstream, fitnessPlan.exerciseWeeklyPlan);

			ofstream.close();

			break;
		case 5:
			system("cls");

			fitnessPlan.displayWeeklyPlan(fitnessPlan.dietWeeklyPlan);

			system("pause");

			break;
		case 6:
			system("cls");

			fitnessPlan.displayWeeklyPlan(fitnessPlan.exerciseWeeklyPlan);

			system("pause");

			break;
		case 7:
			system("cls");

			fitnessPlan.dietWeeklyPlan->editGoal();

			break;
		case 8:
			system("cls");

			fitnessPlan.exerciseWeeklyPlan->editGoal();

			break;
		case 9:
			system("cls");

			std::cout << "Exiting" << std::endl;

			ofstream.open("dietPlans.txt", std::ios::out); // input stream - read - 
			if (!ofstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.storeWeeklyPlan(ofstream, fitnessPlan.dietWeeklyPlan);

			ofstream.close();

			ofstream.open("exercisePlans.txt", std::ios::out); // input stream - read - 
			if (!ofstream)
			{
				std::cout << "Error opening file" << std::endl;
				break;
			}

			fitnessPlan.storeWeeklyPlan(ofstream, fitnessPlan.exerciseWeeklyPlan);

			ofstream.close();

			break;
		}
	}
}

void FitnessAppWrapper::loadDailyPlan(std::istream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(std::istream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(std::istream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(std::istream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(const DietPlan plan)
{
	std::cout << plan;
}

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan plan)
{
	std::cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(const DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(const ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, const DietPlan plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, const ExercisePlan plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, const DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, const ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayMenu(void)
{
	std::cout << "1. Load weekly diet plan from file." << std::endl;
	std::cout << "2. Load weekly exercise plan from file." << std::endl;
	std::cout << "3. Store weekly diet plan to file." << std::endl;
	std::cout << "4. Store weekly exercise plan to file." << std::endl;
	std::cout << "5. Display weekly diet plan to screen." << std::endl;
	std::cout << "6. Display weekly exercise plan to screen." << std::endl;
	std::cout << "7. Edit daily diet plan." << std::endl;
	std::cout << "8. Edit daily exercise plan." << std::endl;
	std::cout << "9. Exit." << std::endl;
}
