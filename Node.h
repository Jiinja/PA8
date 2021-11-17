#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


class Node
{
protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
public:
	virtual ~Node() = 0;
	Node(string newData = "");
	void setData(string newData);
	void setRightPtr(Node* newNode);
	void setLeftPtr(Node* newNode);
	string getData();
	Node* getRightPtr();
	Node* getLeftPtr();
	virtual void printData() = 0;
};

