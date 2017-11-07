#include "Array.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4 };

	Array q1(10);
	for (int i = 0; i < q1.Size(); i++)
	{
		cout << q1[i] << " ";
	}
	cout << endl;
	q1.write_to();
	q1.insert(60, 5);
	q1.write_to();
	//q1.insert_massiv(a, 2);
	//q1.write_to();
	
}
