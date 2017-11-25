#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Stack<int> q1;
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

	Stack<string> q2;
	q2.push("It's easy"); 
	q2.push("Why did you create this??");
	q2.push("What is that?");

	while (!q2.isEmpty())
	{
		cout << q2.top() << endl;
		q2.pop();
	}
	cout << endl;
}
