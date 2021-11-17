#pragma once
#include "BST.h"
class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis();
private:
	bool openFile();
	void readline(string& units, string& type, string& transaction);
	void insertToTree(string units, string type, string transaction);
	void loop();
	void writeTrends();

	//Data members
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
};

