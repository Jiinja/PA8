#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{

}

TransactionNode::TransactionNode(string newData, int newUnits)
{
	this->mData = newData;
	this->mUnits = newUnits;
	this->mpRight = nullptr;
	this->mpLeft = nullptr;
}

void TransactionNode::setUnits(int newUnits)
{
	this->mUnits = newUnits;
}

int TransactionNode::getUnits()
{
	return this->mUnits;
}

void TransactionNode::printData()
{
	cout << this->mData << " : " << this->mUnits << endl;
}

