/*****************************************************************//**
 * \file   main.cpp
 * \brief  this program is for creating a vector
 * 
 * \author Ahmed Hanfy & Abdelrhman Mostafa
 * \date   December 2022
 *********************************************************************/
#include "AAVector.h"
#include "AAVector.cpp"

/**
 * this is main function .
 * 
 */
int main() {
	int a[6] = {1,2,3,4,5,6};
	AAVector<int> v (a,3);
	
	/*v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	v.push_back(3);*/
	v.insert(v.begin() + 2, 20);

	cout << v;

	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;*/
}
