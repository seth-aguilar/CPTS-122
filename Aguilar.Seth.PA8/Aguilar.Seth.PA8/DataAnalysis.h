#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "TransactionNode.h"
#include "BST.h"

class DataAnalysis
{
public:
	~DataAnalysis();
	void runAnalysis();
private:
	void openFile();
	void readLine(const std::string& line, int& units, std::string& type, std::string& transaction);
	void readAll();
	void insertData(int units, const std::string& type, const std::string& transaction);
	void displayTrends();

	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;
};