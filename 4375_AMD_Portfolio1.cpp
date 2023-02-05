/* ALLY DE VERA
*  AMD190012
*  February 04, 2023
*  CS 4375.004
*  Dr. Karen Mazidi
*  Portfolio 1
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

float mean(vector<float> var)
{
	float total = 0;
	for (int i = 0; i < var.size(); i++) 
	{
		total = total + var[i];
	}

	return total/var.size();
}

float median(vector<float> var)
{
	sort(var.begin(), var.end());


	int mid = var.size() / 2;

	if (var.size() % 2 == 1) {
		return var[mid];
	}

	if (var.size() % 2 == 0) {
		 return (var[mid] + var[mid + 1])/2 ;
	}

}

float mode(vector<float> var)
{
	sort(var.begin(), var.end());

	int greatestCount = 0;
	int currentCount = 1;
	int mostIndex = 0;

	for (int i = 1; i < var.size(); i++)
	{
	
		if (var[i - 1] == var[i]) 
		{
			currentCount++;
			if (i == var.size() - 1) {
				if (currentCount > greatestCount) {
					greatestCount = currentCount;
					mostIndex = i - 1;
				}
			}
		}
		else {
			if (currentCount > greatestCount) {
				greatestCount = currentCount;
				mostIndex = i - 1;
			}
			
			currentCount = 1;
		}

	}

	return var[mostIndex];
}

float range(vector<float> var)
{
	float max = 0;
	for (int i = 0; i < var.size(); i++)
	{
		if (max < var[i])
		{
			max = var[i];
		}
	}

	float min = max;
	for (int i = 0; i < var.size(); i++)
	{
		if (min > var[i])
		{
			min = var[i];
		}
	}

	return max - min;
}

float correlation(vector<float> r, vector<float> m)
{
	float meanR = mean(r);
	float totalR = 0;
	for (int i = 0; i < r.size(); i++)
	{
		totalR += pow((r[i] - meanR), 2);
	}
	float sigmaR = sqrt(totalR / (r.size() - 1));


	float meanM = mean(m);
	float totalM = 0;
	for (int i = 0; i < m.size(); i++)
	{
		totalM += pow((m[i] - meanM), 2);
	}
	float sigmaM = sqrt(totalM / (m.size()-1));
	


	float totalCov = 0;
	float cov = 0;
	for (int i = 0; i < r.size(); i++) 
	{
		totalCov += (r[i] - meanR)*(m[i] - meanM);
	}
	 
	cov = totalCov / (r.size() - 1);

	float corrCo = cov/(sigmaR*sigmaM);

	

	return corrCo;
}


int main()
{
	vector<float> rm;
	vector<float> medv;
	string fileName = "Boston.csv";

	ifstream fileStream;
	fileStream.open(fileName, ios::in);


	if (fileStream.fail()) {
		cout << "File " << fileName << " could not be opened.\nPress any key to continue";
		cin.ignore();
		cin.get();
		exit(EXIT_FAILURE);
	}
	
	int num = 0; 
	while(fileStream.is_open())
	{
		string line = "";
		string delimeter = ",";
		int count = 0;

		while (getline(fileStream, line))
		{
			if (count != 0) 
			{
				int pos = line.find(delimeter);

				string r = line.substr(0, pos);
				float rFloat = stof(r);
				rm.push_back(rFloat);


				string m = line.substr(pos + 1, line.length() - 1);
				float mFloat = stof(m);
				medv.push_back(mFloat);
				
	
			}
			count = 1;
		}

		fileStream.close();
		
	}

	

	cout << "Mean RM   : " << mean(rm) << endl;
	cout << "Mean MEDV : " << mean(medv) << endl;
	cout << endl;

	cout << "Median RM   : " << median(rm) << endl;
	cout << "Median MEDV : " << median(medv) << endl;
	cout << endl;

	cout << "Mode RM   : " << mode(rm) << endl;
	cout << "Mode MEDV : " << mode(medv) << endl;
	cout << endl;

	cout << "Range RM   : " << range(rm) << endl;
	cout << "Range MEDV : " << range(medv) << endl;
	cout << endl;

	cout << "Correlation Coefficent of rm and medv : " << correlation(rm, medv) << endl;

	return 0;
}
