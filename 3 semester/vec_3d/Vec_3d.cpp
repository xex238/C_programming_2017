using namespace std;
#include <iostream>
#include <sstream>
#include "Vec_3d.h"


void Test_Parse1 (const Vector& q1, const Vector& q2)
{
	cout << "Vector q1 = {" << q1.x << ", " << q1.y << ", " << q1.z << "}" << endl;
	cout << "Vector q2 = {" << q2.x << ", " << q2.y << ", " << q2.z << "}" << endl;
	cout << "Test_Parse1 is start... " << endl;
	cout << "V1 + V2 = " << (q1 + q2) << endl;
	cout << "V1 - V2 = " << (q1 - q2) << endl;
	cout << "V1 * V2 = " << (q1 * q2) << endl;
	cout << "V1 / V2 = " << (q1 / q2) << endl;
	cout << "Test_Parse1 is end. " << endl;
}

void Test_Parse2(const Vector& q1, const double q2)
{
	cout << "Vector q1 = {" << q1.x << ", " << q1.y << ", " << q1.z << "}" << endl;
	cout << "Number q2 = " << q2 << endl;
	cout << "Test_Parse2 is start... " << endl;
	cout << "V1 * q2 = " << (q1 * q2) << endl;
	cout << "V1 / q2 = " << (q1 / q2) << endl;
	cout << "Test_Parse2 is end. " << endl;
}

int main()
{
	Vector q1(1, 2, 3);
	Vector q2(10, 20, 30);
	Test_Parse1(q1, q2);
	Test_Parse2(q1, 10);
}
