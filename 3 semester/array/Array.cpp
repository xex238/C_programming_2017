#include "Array.h"
#include <iostream>
using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4 };

	Array q1(10);
	cout << "Ten of zeros" << endl;
	for (int i = 0; i < q1.Size(); i++)
	{
		cout << q1[i] << " ";
	}
	cout << endl;
	q1.add();
	cout << "Ten + 1 of zeros" << endl;
	q1.write_to();
	q1.insert(60, 9);
	cout << "After insert of number" << endl;
	q1.write_to();
	cout << "After insert massiv" << endl;
	q1.insert_massiv(a, 2);
	q1.write_to();
	
}
