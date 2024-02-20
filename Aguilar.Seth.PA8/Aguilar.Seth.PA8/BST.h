#pragma once
#include <iostream>
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST() : mpRoot(nullptr) {};
	~BST();

	void setRoot(Node* newRoot);
	Node* getRoot();

	void insert(std::string data, int units); //Hides pointer info
	void inOrderTraversal(); //Hides pointer info

	TransactionNode& findSmallest(); //Hides pointer info
	TransactionNode& findLargest(); //Hides pointer info

private:
	void destroyTree(Node* root);
	void insert(Node*& newNode, std::string data, int units);
	void inOrderTraversal(Node* pCur);
	TransactionNode& findSmallest(Node* pCur);
	TransactionNode& findLargest(Node* pCur);

	Node* mpRoot;
};