#include <iostream>
#include <sstream>
#include "Kvaternion.h"
using namespace std;

void TestParse1(const Kvaternion& q1, const Kvaternion& q2)
{
	cout << "Kvaternion 1" << endl << q1;
	cout << "Kvaternion 2" << endl << q2;
	cout << "Test_parse 1 is start.." << endl;
	cout << "q1 + q2 = " << endl << (q1 + q2);
	cout << "q1 - q2 = " << endl << (q1 - q2);
	cout << "q1 * q2 = " << endl << (q1 * q2);
	cout << "q1 / q2 = " << endl << (q1 / q2);
	cout << "Test_parse 1 is end" << endl;
};

void TestParse2(const Kvaternion& q1, const int q2)
{
	cout << "Kvaternion" << endl << q1;
	cout << "Number: " << q2 << endl;
	cout << "Test_parse 2 is start.." << endl;
	cout << "q1 * q2" << endl << (q1 * q2);
	cout << "q1 / q2" << endl << (q1 / q2);
	cout << "Test_parse 2 is end" << endl;
}

void TestParse3(const int q1, const Kvaternion& q2)
{
	cout << "Kvaternion" << endl << q2;
	cout << "Number: " << q1 << endl;
	cout << "Test_parse 3 is start.." << endl;
	cout << "q1 * q2" << endl << (q1 * q2);
	cout << "q1 / q2" << endl << (q1 / q2);
	cout << "Test_parse 3 is end" << endl;
}

int main()
{
	Kvaternion a(1, 2, 3, 4);
	Kvaternion b(10, 11, 12, 13);
	TestParse1(a, b);
	TestParse2(b, 10);
	TestParse3(10, b);
	a.opredelitel();
}
