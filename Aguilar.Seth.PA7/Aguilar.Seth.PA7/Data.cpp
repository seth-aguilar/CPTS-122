#include "Data.h"

Data::Data()
{
}

Data::Data(int id, std::string name, std::string email, int units, std::string program, std::string level, int absences, Stack absenceDates)
{
	this->id = id;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->level = level;
	this->absences = absences;
	this->absenceDates = absenceDates;
}

int Data::getID() const
{
	return id;
}

std::string Data::getName() const
{
	return name;
}

std::string Data::getEmail() const
{
	return email;
}

int Data::getUnits() const
{
	return units;
}

std::string Data::getProgram() const
{
	return program;
}

std::string Data::getLevel() const
{
	return level;
}

int Data::getAbsences() const
{
	return absences;
}

Stack Data::getAbsenceDates() const
{
	return absenceDates;
}

void Data::setID(const int newID)
{
	id = newID;
}

void Data::setName(const std::string newName)
{
	name = newName;
}

void Data::setEmail(const std::string newEmail)
{
	email = newEmail;
}

void Data::setUnits(const int newUnits)
{
	units = newUnits;
}

void Data::setProgram(const std::string newProgram)
{
	program = newProgram;
}

void Data::setLevel(const std::string newLevel)
{
	level = newLevel;
}

void Data::setAbsences(const int newAbsences)
{
	absences = newAbsences;
}

void Data::setAbsenceDates(const Stack newAbsenceDates)
{
	absenceDates = newAbsenceDates;
}
