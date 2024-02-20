#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"


class Data
{
public:
	Data();

	Data(int id,
	std::string name,
	std::string email,
	int units,
	std::string program,
	std::string level,
	int absences,
	Stack absenceDates);

	int getID() const;
	std::string getName() const;
	std::string getEmail() const;
	int getUnits() const;
	std::string getProgram() const;
	std::string getLevel() const;
	int getAbsences() const;
	Stack getAbsenceDates() const;

	void setID(const int newID);
	void setName(const	std::string newName);
	void setEmail(const std::string newEmail);
	void setUnits(const int newUnits);
	void setProgram(const std::string newProgram);
	void setLevel(const std::string newLevel);
	void setAbsences(const int newAbsences);
	void setAbsenceDates(const Stack newAbsenceDates);

private:
	int id;
	std::string name;
	std::string email;
	int units;
	std::string program;
	std::string level;
	int absences;
	Stack absenceDates;
};