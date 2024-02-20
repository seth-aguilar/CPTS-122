#include "BST.h"

BSTNode::BSTNode()
{
	English = '\0';
	Morse = '0';
}

BSTNode::BSTNode(char newEnglish, std::string newMorse)
{
	English = newEnglish;
	Morse = newMorse;
}

char BSTNode::getEnglish() const
{
	return English;
}

std::string BSTNode::getMorse() const
{
	return Morse;
}

BSTNode*& BSTNode::getpLeft()
{
	return pLeft;
}

BSTNode*& BSTNode::getpRight()
{
	return pRight;
}

void BSTNode::setEnglish(const char newEnglish)
{
	English = newEnglish;
}

void BSTNode::setMorse(const std::string newMorse)
{
	Morse = newMorse;
}

void BSTNode::setpLeft(BSTNode* newpLeft)
{
	pLeft = newpLeft;
}

void BSTNode::setpRight(BSTNode* newpRight)
{
	pRight = newpRight;
}

BST::BST()
{
	std::ifstream ifstream;
	ifstream.open("MorseTable.txt", std::ios::in);
	char English = '\0';
	std::string Morse;
	std::string line;
	BSTNode* newNode, * pCur = pRoot;

	while (std::getline(ifstream, line))
	{
		English = line[0]; // First element of each line is the char
		Morse = line.substr(2); // After the first two elements the rest is the morse code
		newNode = makeNode(Morse, English);
		insert(pCur, newNode, &pRoot);
	}

	ifstream.close();
}

BSTNode* BST::getRoot()
{
	return pRoot;
}

BSTNode* BST::makeNode(std::string newMorse, char newEnglish)
{
	BSTNode* newNode = new BSTNode(newEnglish, newMorse);

	return newNode;
}

void BST::insert(BSTNode*& pCur, BSTNode* pNew, BSTNode** ppRoot)
{
	if (*ppRoot == nullptr)
	{
		*ppRoot = pNew;
		pCur = *ppRoot;
		return;
	}

	if (pCur == nullptr)
	{
		pCur = pNew;
		return;
	}

	if (pCur->getEnglish() < pNew->getEnglish())
	{
		insert(pCur->getpLeft(), pNew, ppRoot);
	}
	else if (pCur->getEnglish() > pNew->getEnglish())
	{
		insert(pCur->getpRight(), pNew, ppRoot);
	}
}

void BST::print(BSTNode* pCur)
{
	if (pCur != nullptr)
	{
		print(pCur->getpRight());
		std::cout << pCur->getEnglish() << ' ' << pCur->getMorse() << std::endl;
		print(pCur->getpLeft());
	}
}

std::string BST::search(char targetChar)
{
	BSTNode* pCur = pRoot;

	while (pCur->getEnglish() != targetChar)
	{
		if (pCur->getEnglish() < targetChar)
		{
			pCur = pCur->getpLeft();
		}
		if (pCur->getEnglish() > targetChar)
		{
			pCur = pCur->getpRight();
		}
	}
	std::string found = pCur->getMorse();

	return found;
}

void convert(BST bst)
{
	std::ifstream ifstream;
	ifstream.open("Convert.txt", std::ios::in);
	char c;
	std::string Morse;

	while (ifstream.get(c))
	{
		// Convert lowercase characters to uppercase
		if (c >= 'a' && c <= 'z')
		{
			c = toupper(c);
		}
		
		// Print newline characters if get comes across newline
		if (c == '\n')
		{
			std::cout << std::endl;
			continue;
		}

		// Print spaces
		if (c == ' ')
		{
			std::cout << c;
			continue;
		}

		Morse = bst.search(c);
		std::cout << Morse << ' ';
	}
	ifstream.close();
}
