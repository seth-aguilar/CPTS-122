#pragma once
#include <iostream>
#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(std::string data, int units) : Node(data), mUnits(units) {};
	~TransactionNode();

	int getUnits();
	void setUnits(int newUnits);

	void printData() override;
private:
	int mUnits;
};