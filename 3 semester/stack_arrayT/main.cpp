#include "Array_stack_1.h"
#include <string>
using namespace std;

int main()
{
	cout << "Test_parse for int begin" << endl;

	Array_stack<int> q1;

	for (int i = 0; i < 10; i++)
	{
		q1.insert(i);
	}

	Array_stack<int> q2;
	q2 = q1;

	Array_stack<string> q3;
	Array_stack<string> q4;
	q3.insert("Happy new year!");
	q3.insert("Wow wow)");
	q3.insert("It's the best test!");
	q4 = q3;
	q4.insert("T.T");
	q4.insert("That's too bad");
	q4.insert("I'll fall my session");
	q4.insert("But, No happy new year");

	cout << "q1 = ";
	while (!q1.isEmpty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	for (int i = 95; i < 100; i++)
	{
		q2.insert(i);
	}

	cout << "q1 = ";
	while (!q1.isEmpty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	cout << "q2 = ";
	while (!q2.isEmpty())
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;
	cout << "Test_parse for int is end" << endl;


	cout << "Test_parse for string begin" << endl;
	cout << "q3 = " << endl;
	while (!q3.isEmpty())
	{
		cout << q3.top() << endl;
		q3.pop();
	}

	cout << "q4 = " << endl;
	while (!q4.isEmpty())
	{
		cout << q4.top() << endl;
		q4.pop();
	}
	cout << "Testing exeption" << endl;
	try
	{
		q4.pop();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << q4[-1];
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Test_parse for string is end" << endl;
}
