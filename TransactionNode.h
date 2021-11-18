#pragma once
#include "Node.h"
class TransactionNode : public Node
{
private:
	int mUnits;
public:
	~TransactionNode();
	TransactionNode(string newData = "", int newUnits = 0);
	void setUnits(int newUnits);
	int getUnits() const;
	void printData();
};

