#include "Kvaternion.h"
#include <sstream>
#include <iostream>
using namespace std;

Kvaternion operator+(const Kvaternion & q1, const Kvaternion & q2)
{
	return Kvaternion(q1.q[0][0] + q2.q[0][0], q1.q[0][1] + q2.q[0][1], q1.q[1][0] + q2.q[1][0], q1.q[1][1] + q2.q[1][1]);
}

Kvaternion operator-(const Kvaternion & q1, const Kvaternion & q2)
{
	return Kvaternion(q1.q[0][0] - q2.q[0][0], q1.q[0][1] - q2.q[0][1], q1.q[1][0] - q2.q[1][0], q1.q[1][1] - q2.q[1][1]);
}

Kvaternion operator*(const Kvaternion & q1, const Kvaternion & q2)
{
	return Kvaternion(q1.q[0][0] * q2.q[0][0], q1.q[0][1] * q2.q[0][1], q1.q[1][0] * q2.q[1][0], q1.q[1][1] * q2.q[1][1]);
}

Kvaternion operator/(const Kvaternion & q1, const Kvaternion & q2)
{
	return Kvaternion(q1.q[0][0] / q2.q[0][0], q1.q[0][1] / q2.q[0][1], q1.q[1][0] / q2.q[1][0], q1.q[1][1] / q2.q[1][1]);
}



Kvaternion operator*(const Kvaternion & q1, const int q2)
{
	return Kvaternion(q1.q[0][0] * q2, q1.q[0][1] * q2, q1.q[1][0] * q2, q1.q[1][1] * q2);
}

Kvaternion operator/(const Kvaternion & q1, const int q2)
{
	return Kvaternion(q1.q[0][0] / q2, q1.q[0][1] / q2, q1.q[1][0] / q2, q1.q[1][1] / q2);
}



Kvaternion operator*(const int q1, const Kvaternion& q2)
{
	return Kvaternion(q2.q[0][0] * q1, q2.q[0][1] * q1, q2.q[1][0] * q1, q2.q[1][1] * q1);
}

Kvaternion operator/(const int q1, const Kvaternion& q2)
{
	return Kvaternion(q2.q[0][0] / q1, q2.q[0][1] / q1, q2.q[1][0] / q1, q2.q[1][1] / q1);
}

ostream & Kvaternion::writeTo(ostream & ostr) const
{
	ostr << q[0][0] << " " << q[0][1] << endl;
	ostr << q[1][0] << " " << q[1][1] << endl;
	return ostr;
}

istream & Kvaternion::readFrom(istream & isrm)
{
	return isrm;
}
