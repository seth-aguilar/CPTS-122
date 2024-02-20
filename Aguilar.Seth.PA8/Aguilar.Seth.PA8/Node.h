#pragma once
#include <iostream>

class Node
{
public:
	Node(std::string Data);
	virtual ~Node();

	void setData(std::string newData);
	void setLeft(Node* newLeft);
	void setRight(Node* newRight);

	std::string getData();
	Node*& getLeft();
	Node*& getRight();

	void virtual printData();
protected:
	std::string mData;
	Node* mpLeft;
	Node* mpRight;
};
