#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack q1;
	q1.push(228);
	for (int i = 0; i < 10; i++)
	{
		q1.push(i);
	}
	q1.push(2018);

	while (!q1.isEmpty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}
