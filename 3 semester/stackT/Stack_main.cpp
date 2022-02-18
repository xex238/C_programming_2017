#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void Test_parse(Stack<T>& q1, const T q2[], const int q3)
{
	cout << "Test_parse is start..." << endl;
	if ((q3 < 0) || (q3 == 0))
	{
		throw invalid_argument("Введите верное значение переменной q3");
	}
	for (int i = 0; i < q3; i++)
	{
		q1.push(q2[i]);
	}
	while (!q1.isEmpty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl << "Test_parse is end." << endl;
}

int main()
{
	Stack<int> q1;
	const int x1[12] = { 228, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2018 };
	const int y1 = -1;
	try
	{
		Test_parse(q1, x1, y1);
	}
	catch (invalid_argument)
	{
		cout << "The method is suspended! Invalid value of the variable q3!" << endl;
	}

	Stack<string> q2;
	string x2[3] = { "It's so easy", "Why did you create this??", "What is that?" };
	const int y2 = 3;
	try
	{
		Test_parse(q2, x2, y2);
	}
	catch (invalid_argument)
	{
		cout << "The method is suspended! Invalid value of the variable q3!" << endl;
	}
}
