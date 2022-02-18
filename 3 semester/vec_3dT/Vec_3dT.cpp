using namespace std;
#include <iostream>
#include <sstream>
#include <iosfwd>
#include <string>
#include "Vec3dT.h"

template <typename T>
void Test_Parse1(const Vector<T>& q1, const Vector<T>& q2)
{
	cout << "q1 = " << q1 << endl;
	cout << "q2 = " << q2 << endl;
	cout << "Test_Parse1 is start... " << endl;
	cout << "q1 + q2 = " << (q1 + q2) << endl;
	cout << "q2 - q2 = " << (q1 - q2) << endl;
	cout << "q1 * q2 = " << (q1 * q2) << endl;
	cout << "q1 / q2 = " << (q1 / q2) << endl;
	cout << "Test_Parse1 is end. " << endl;
	cout << endl;
}

template <typename T>
void Test_Parse2(const Vector<T> q1, const double q2)
{
	cout << "q1 = " << q1 << endl;
	cout << "Number is " << q2 << endl;
	cout << "Test_Parse2 is start... " << endl;
	cout << "q1 * q2 = " << (q1 * q2) << endl;
	cout << "q1 / q2 = " << (q1 / q2) << endl;
	cout << "Test_Parse2 is end. " << endl;
}

int main()
{
	Vector<double> q1(1, 2, 3);
	Vector<double> q2(10, 20, 30);
	Test_Parse1(q1, q2);
	Test_Parse2(q1, 10);
}
