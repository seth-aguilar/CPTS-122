#include "DataAnalysis.h"

DataAnalysis::~DataAnalysis()
{
	mCsvStream.close();
}

void DataAnalysis::runAnalysis()
{
	openFile();
	readAll();
	displayTrends();
}

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv", std::ios::in);
}

void DataAnalysis::readLine(const std::string& line, int& units, std::string& type, std::string& transaction)
{
	std::istringstream lineStream(line);
	std::string token;

	std::getline(lineStream, token, ',');
	units = std::stoi(token);

	std::getline(lineStream, token, ',');
	type = token;

	std::getline(lineStream, token, ',');
	transaction = token;
}

void DataAnalysis::readAll()
{
	std::string line;
	std::getline(mCsvStream, line);

	while (std::getline(mCsvStream, line))
	{
		int units;
		std::string data, transaction;
		readLine(line, units, data, transaction);
		insertData(units, data, transaction);
	}

	std::cout << "Purchased" << std::endl;
	mTreePurchased.inOrderTraversal();
	std::cout << "Sold" << std::endl;
	mTreeSold.inOrderTraversal();
}

void DataAnalysis::insertData(int units, const std::string& data, const std::string& transaction)
{
	if (transaction == "Sold") 
	{
		mTreeSold.insert(data, units);
	}
	else if (transaction == "Purchased") 
	{
		mTreePurchased.insert(data, units);
	}
}

void DataAnalysis::displayTrends()
{
	std::cout << "Least Purchased:" << std::endl;
	std::cout << mTreePurchased.findSmallest().getData() << ", " << mTreePurchased.findSmallest().getUnits() << std::endl;
	std::cout << "Least Sold:" << std::endl;
	std::cout << mTreeSold.findSmallest().getData() << ", " << mTreeSold.findSmallest().getUnits() << std::endl;
	std::cout << "Most Purchased:" << std::endl;
	std::cout << mTreePurchased.findLargest().getData() << ", " << mTreePurchased.findLargest().getUnits() << std::endl;
	std::cout << "Most Sold:" << std::endl;
	std::cout << mTreeSold.findLargest().getData() << ", " << mTreeSold.findLargest().getUnits() << std::endl;
}
