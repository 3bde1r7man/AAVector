#include "AAVector.h"
#include "AAVector.cpp"


int main() {
	AAVector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	v.push_back(3);

	v.resize(4);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
