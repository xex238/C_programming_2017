#include <iostream>
#include <sstream>
#include "complex.h"
using namespace std;

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success" << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error" << str << " -> " << z << endl;
	}
	return istrm.good();
}


void Cd(const double q1, const double q2, const double q3)
{
	cout << "Test: Complex + double" << endl;
	Complex x(q1, q2);
	cout << "C + d = " << (x + q3) << endl;
	cout << "C - d = " << (x - q3) << endl;
	cout << "C * d = " << (x * q3) << endl;
	cout << "C / d = " << (x / q3) << endl;
	cout << endl;
}

void CC(const double q1, const double q2, const double q3, const double q4)
{
	cout << "Test: Complex + Complex" << endl;
	Complex x1(q1, q2);
	Complex x2(q3, q4);
	cout << "C + C = " << (x1 + x2) << endl;
	cout << "C - C = " << (x1 - x2) << endl;
	cout << "C * C = " << (x1 * x2) << endl;
	cout << "C / C = " << (x1 / x2) << endl;
	cout << endl;
}

void CCpl(const double q1, const double q2, const double q3, const double q4)
{
	cout << "Test: Complex++" << endl;
	Complex x1(q1, q2);
	Complex x2(q3, q4);
	cout << "C1+= " << (x1 += x2) << endl;
	cout << "C1-= " << (x1 -= x2) << endl;
	cout << "C1*= " << (x1 *= x2) << endl;
	cout << "C1/= " << (x1 /= x2) << endl;
	cout << endl;
}

void Cdpl(const double q1, const double q2, const double q3)
{
	cout << "Test: Complex + double" << endl;
	Complex x(q1, q2);
	cout << "C+= " << (x += q3) << endl;
	cout << "C-= " << (x -= q3) << endl;
	cout << "C*= " << (x *= q3) << endl;
	cout << "C/= " << (x /= q3) << endl;
	cout << endl;
}

void dCpl(const double q1, const double q2, const double q3)
{
	cout << "Test: double + Complex" << endl;
	Complex x(q2, q3);
	cout << "d+= " << (q1 + x) << endl;
	cout << "d-= " << (q1 - x) << endl;
	cout << "d*= " << (q1 * x) << endl;
	cout << "d/= " << (q1 / x) << endl;
	cout << endl;
}

int main()
{
	using namespace std;
	Cd(10, 20, 100);
	CC(10, 15, 20, 30);
	CCpl(10, 15, 20, 30);
	Cdpl(10, 20, 100);
	dCpl(15, 3, 5);
	
	Complex z1(10, 25);
	Complex z2(12, 25);

	cout << (z1 < z2) << endl;

	Complex z3(10, 26);


	//Complex z(5, 6);
	//cout << (z + 10);
	//cout << (10 + z);

	//Complex z;
	//z += Complex(8.0);
	//testParse("{8.9,9}");
	//testParse("{8.9, 9}");
	//testParse("{8.9, 9");
	//testParse("{9, 9}");
	//return 0;
}
