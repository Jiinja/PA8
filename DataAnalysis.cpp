#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{

}

DataAnalysis::~DataAnalysis()
{
	this->mCsvStream.close();
}

void DataAnalysis::runAnalysis()
{
	openFile();
	loop();
	writeTrends();
}

bool DataAnalysis::openFile()
{
	this->mCsvStream.open("data.csv");
	return(this->mCsvStream.is_open());
}

void DataAnalysis::readline(string& units, string& type, string& transaction)
{
	getline(this->mCsvStream, units, ',');
	getline(this->mCsvStream, type, ',');
	getline(this->mCsvStream, transaction);
}

void DataAnalysis::insertToTree(string units, string type, string transaction)
{
	if (transaction == "Purchased")
	{
		this->mTreePurchased.insert(type, stoi(units));
	}
	else if (transaction == "Sold")
	{
		this->mTreeSold.insert(type, stoi(units));
	}
}

void DataAnalysis::loop()
{
	string units;
	string type;
	string transaction;
	while (!this->mCsvStream.eof())
	{
		readline(units, type, transaction);
		insertToTree(units, type, transaction);
		cout << "[PURCHASED LIST]" << endl;
		this->mTreePurchased.inOrderTraversal();
		cout << "[SOLD LIST]" << endl;
		this->mTreeSold.inOrderTraversal();
		cout << endl;
	}
}

void DataAnalysis::writeTrends()
{
	cout << endl <<"[TRENDS]" << endl;
	cout << "Purchased: Smallest/Largest" << endl;
	this->mTreePurchased.findSmallest().printData();
	this->mTreePurchased.findLargest().printData();
	cout << "Sold: Smallest/Largest" << endl;
	this->mTreeSold.findSmallest().printData();
	this->mTreeSold.findLargest().printData();


}

