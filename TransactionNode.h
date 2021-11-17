#pragma once
#include "Node.h"
class TransactionNode : public Node
{
private:
	int mUnits;
public:
	~TransactionNode();
	TransactionNode(string newData, int newUnits);
	void setUnits(int newUnits);
	int getUnits();
	void printData();
};

