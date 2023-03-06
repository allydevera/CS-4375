/* ALLY DE VERA
*  AMD190012
*  February 04, 2023
*  CS 4375.004
*  Dr. Karen Mazidi
*  Portfolio 1 : C++ Data Exploration
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int main() {
	string fileName = "titanic_project.csv";
	vector<string>row;
	vector<string> passengerID;
	vector<int> pclass;
	vector<bool> survived;
	vector<char> sex;
	vector<int> age;
	//file read in 
	ifstream fileStream;
	fileStream.open(fileName, ios::in);


	if (fileStream.fail())
	{
		cout << "File " << fileName << " could not be opened.\nPress any key to continue";
		cin.ignore();
		cin.get();
		exit(EXIT_FAILURE);
	}

	int num = 0;
	while (fileStream.is_open())
	{
		string line = "";
		int count = 0;
		int col = 0;
		

		getline(fileStream, line);

		while (getline(fileStream, line, '\n'))
		{
			row.push_back(line);

		}
		fileStream.close();
	}
		
	for (int i = 0; i < row.size(); i++) {
		string str = row[i];
		int count = 0;

		do {
			int del = str.find(',');
			
			if (count == 0)
			{
				passengerID.push_back(str.substr(0, del));
			}
			

			if (count == 1)
			{		
				pclass.push_back(stoi(str.substr(0, del)));
			}

			
			if (count == 2)
			{
				if (str == "0") {
					survived.push_back(false);
				}
				else {
					survived.push_back(true);
				}
			}

			if (count == 3)
			{
				if (str == "0") {
					sex.push_back('M');
				}
				else {
					sex.push_back('F');
				}
			}

			if (count == 4)
			{
				age.push_back(stoi(str.substr(0, del)));
			}

							
	

			count++;
			str = str.substr(del + 1);
		} while (count < 5);

	}



}
