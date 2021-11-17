#include "Node.h"

Node::Node(string newData = "")
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

void Node::setData(string newData)
{
	this->mData = newData;
}

void Node::setRightPtr(Node* newNode)
{
	this->mpRight = newNode;
}

void Node::setLeftPtr(Node* newNode)
{
	this->mpLeft = newNode;
}

string Node::getData()
{
	return this->mData;
}

Node* Node::getRightPtr()
{
	return this->mpRight;
}

Node* Node::getLeftPtr()
{
	return this->mpLeft;
}

