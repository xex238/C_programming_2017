#include <iostream>
#include "PQ.h"
#include <string>

int main()
{
	using namespace std;
	PQ<int> q1;
	PQ<int> q2;
	PQ<string> q3;
	q1.insert(2);
	q1.insert(2);
	q1.insert(8);
	q1.insert(10);
	q1.insert(100);

	q2 = q1;
	q2.insert(q1);
	while (!q2.isEpmty())
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;

	q3.insert("I'm first!");
	q3.insert("O, la la");
	q3.insert("xex238");
	q3.insert("Sorry, you're last");

	while (!q3.isEpmty())
	{
		cout << q3.top() << endl;
		q3.pop();
	}
	cout << endl;
}
