#pragma once
//#include "BSTNode.h"

#include <iostream>
#include <fstream>
#include <string>

class BSTNode
{
public:

	BSTNode();
	BSTNode(char newEnglish, std::string newMorse);

	char getEnglish() const;
	std::string getMorse() const;
	BSTNode*& getpLeft();
	BSTNode*& getpRight();

	void setEnglish(const char newEnglish);
	void setMorse(const std::string newMorse);
	void setpLeft(BSTNode* newpLeft);
	void setpRight(BSTNode* newpRight);

private:
	char English;
	std::string Morse;
	BSTNode* pLeft;
	BSTNode* pRight;
};


class BST
{
public:
	BST();
	BSTNode* getRoot();
	BSTNode* makeNode(std::string newMorse, char newEnglish);
	void insert(BSTNode*& pCur, BSTNode* pNew, BSTNode** ppRoot);
	void print(BSTNode* pCur);
	std::string search(char targetChar);
private:
	BSTNode* pRoot;
};

void convert(BST bst);