#include <iostream>
#include <sstream>
#include "Matrix.h"
using namespace std;

void Vivod(const Matrix& q)
{
	for (int i_Rows = 0; i_Rows < q.N_Rows(); i_Rows++)
	{
		for (int i_Columns = 0; i_Columns < q.N_Columns(); i_Columns++)
		{
			cout << q.matrix[i_Rows][i_Columns] << " ";
		}
		cout << endl;
	}
}

void Test_parse(const Matrix& q1, const Matrix& q2)
{
	cout << "Test_parse is start.. " << endl << endl;

	cout << "q1 = " << endl;
	Vivod(q1);
	cout << endl;

	cout << "q2 = " << endl;
	Vivod(q2);
	cout << endl;

	cout << "q1 + q2 = " << endl;
	Vivod(q1 + q2);
	cout << endl;

	cout << "q1 + q2 = " << endl;
	Vivod(q1 - q2);
	cout << endl;

	cout << "q1 * q2 = " << endl;
	Vivod(q1 * q2);
	cout << endl;

	cout << "Test_parse is end. " << endl;
}

int main()
{
	int **a = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = 5;
		}
	}

	int **b = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		b[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = 10;
		}
	}

	//int a1[3] = {1, 2, 3};

	Matrix q1(a, 3, 3);
	Matrix q2(b, 3, 3);
	Matrix q3(3, 3);

	Test_parse(q1, q2);

	//cout << "q3 =  " << endl;
	//q3 = q1 + q2;
	//Vivod(q3);
	//cout << endl;

	//q.Add(a1, 1);

	//cout << "q = " << endl;
	//cout << q << endl;

	//cout << q1 << endl;
	//cout << "q2 = " << endl;
	//cout << q2 << endl;
}
