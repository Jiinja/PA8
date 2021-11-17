#include "BST.h"

BST::~BST()
{
	destroyTree(this->mpRoot);
}

BST::BST()
{
	this->mpRoot = nullptr;
}

void BST::setRoot(Node* newRoot)
{
	this->mpRoot = newRoot;
}

Node* BST::getRoot()
{
	return this->mpRoot;
}

void BST::insert(string newData, int newUnits)
{
	TransactionNode* newNode = new TransactionNode(newData, newUnits);
	insert((TransactionNode*)this->mpRoot, newNode);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

TransactionNode& BST::findSmallest()
{
	TransactionNode* traverse = (TransactionNode*)this->mpRoot;
	while (traverse->getLeftPtr() != nullptr)
	{
		traverse = (TransactionNode*)traverse->getLeftPtr();
	}
	return *traverse;
}

TransactionNode& BST::findLargest()
{
	TransactionNode* traverse = (TransactionNode*)this->mpRoot;
	while (traverse->getRightPtr() != nullptr)
	{
		traverse = (TransactionNode*)traverse->getRightPtr();
	}
	return *traverse;
}

void BST::destroyTree(Node* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}

void BST::insert(TransactionNode* pTree, TransactionNode* newNode)
{
	if (this->mpRoot == nullptr)
	{
		this->mpRoot = newNode;
	}
	else
	{
		if (newNode->getUnits() > pTree->getUnits())
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(newNode);
			}
			else
			{
				insert(pTree, newNode);
			}
		}
		else if (newNode->getUnits() < pTree->getUnits())
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(newNode);
			}
			else
			{
				insert(pTree, newNode);
			}
		}
		else
		{
			cout << "ERROR: DUPLICATE ENTERED INTO THE BST" << endl;
		}
	}
}

void BST::inOrderTraversal(Node* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeftPtr());
		pTree->printData();
		inOrderTraversal(pTree->getRightPtr());
	}
}

