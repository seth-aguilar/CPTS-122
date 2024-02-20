#include "Node.h"

Node::Node(std::string Data)
{
	mData = Data;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

void Node::setData(std::string newData)
{
	mData = newData;
}

void Node::setLeft(Node* newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node* newRight)
{
	mpRight = newRight;
}

std::string Node::getData()
{
	return mData;
}

Node*& Node::getLeft()
{
	return mpLeft;
}

Node*& Node::getRight()
{
	return mpRight;
}

void Node::printData()
{
	std::cout << mData << std::endl;
}
