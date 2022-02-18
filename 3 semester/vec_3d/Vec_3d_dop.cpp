#include "Vec_3d.h"
using namespace std;

Vector operator+(const Vector & q1, const Vector & q2)
{
	return Vector(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
}

Vector operator-(const Vector & q1, const Vector & q2)
{
	return Vector(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
}

Vector operator*(const Vector & q1, const Vector & q2)
{
	return Vector(q1.x*q2.x, q1.y*q2.y, q1.z*q2.z);
}

Vector operator/(const Vector & q1, const Vector & q2)
{
	return Vector(q1.x / q2.x, q1.y / q2.y, q1.z / q2.z);
}

Vector operator*(const Vector & q1, const double q2)
{
	return Vector(q1.x*q2, q1.y*q2, q1.z*q2);
}

Vector operator/(const Vector & q1, const double q2)
{
	return Vector(q1.x / q2, q1.y / q2, q1.z / q2);
}

std::ostream& Vector::writeTo(std::ostream& ostrm) const
{
	ostrm << x << ", " << y << ", " << z << ";";
	return ostrm;
}

std::istream & Vector::readFrom(std::istream & istrm)
{
	return istrm;
}
