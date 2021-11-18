#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{

}

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	this->mUnits = newUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	this->mUnits = newUnits;
}

int TransactionNode::getUnits() const
{
	return this->mUnits;
}

void TransactionNode::printData()
{
	cout << "  " << this->mData << " : " << this->mUnits << endl;
}

