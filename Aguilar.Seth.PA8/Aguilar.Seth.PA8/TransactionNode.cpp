#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{
}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	std::cout << mUnits << std::endl;
}
