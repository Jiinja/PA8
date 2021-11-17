#pragma once
#include "TransactionNode.h"
class BST
{
public:
	~BST();
	BST();
	void setRoot(Node* newRoot);
	Node* getRoot();
	void insert(string newData, int newUnits);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	Node* mpRoot;
	void destroyTree(Node* pTree);
	void insert(TransactionNode* pTree, TransactionNode* newNode);
	void inOrderTraversal(Node* pTree);

};

