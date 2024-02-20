#include "BST.h"


BST::~BST()
{
    destroyTree(mpRoot);
}

void BST::setRoot(Node* newRoot)
{
    mpRoot = newRoot;
}

Node* BST::getRoot()
{
	return mpRoot;
}

void BST::insert(std::string data, int units)
{
    insert(mpRoot, data, units);
}

void BST::inOrderTraversal()
{
    inOrderTraversal(mpRoot);
}

TransactionNode& BST::findSmallest()
{
    return findSmallest(mpRoot);
}

TransactionNode& BST::findLargest()
{
    return findLargest(mpRoot);
}

void BST::destroyTree(Node* root)
{
    if (root == nullptr) 
    {
        return;
    }

    destroyTree(root->getLeft());

    destroyTree(root->getRight());

    delete root;
}

void BST::insert(Node*& newNode, std::string data, int units)
{
    if (newNode == nullptr)
    {
        newNode = new TransactionNode(data, units);
    }
    else if (units < dynamic_cast<TransactionNode*>(newNode)->getUnits())
    {
        insert(newNode->getLeft(), data, units);
    }
    else 
    {
        insert(newNode->getRight(), data, units);
    }
}

void BST::inOrderTraversal(Node* pCur)
{
    if (pCur == nullptr)
    {
        return;
    }

    inOrderTraversal(pCur->getLeft());
    pCur->printData();
    inOrderTraversal(pCur->getRight());
}

TransactionNode& BST::findSmallest(Node* pCur)
{
    if (pCur->getLeft() == nullptr)
    {
        return *dynamic_cast<TransactionNode*>(pCur);
    }
    else
    {
        return findSmallest(pCur->getLeft());
    }
}

TransactionNode& BST::findLargest(Node* pCur)
{
    if (pCur->getRight() == nullptr)
    {
        return *dynamic_cast<TransactionNode*>(pCur);
    }
    else
    {
        return findLargest(pCur->getRight());
    }

}
