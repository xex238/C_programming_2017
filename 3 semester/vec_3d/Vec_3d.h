#ifndef Programka
#define Programka
using namespace std;
#include <ostream>
#include <sstream>

struct Vector
{
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };
	Vector() = default;
	~Vector() = default;
	Vector(double x, double y, double z) : x(x), y(y), z(z)
	{

	}

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

};

inline std::ostream& operator<<(std::ostream& ostrm, const Vector& q)
{
	return q.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vector& q)
{
	return q.readFrom(istrm);
}

Vector operator+ (const Vector& q1, const Vector& q2);
Vector operator- (const Vector& q1, const Vector& q2);
Vector operator* (const Vector& q1, const Vector& q2);
Vector operator/ (const Vector& q1, const Vector& q2);

Vector operator* (const Vector& q1, const double q2);
Vector operator/ (const Vector& q1, const double q2);

#endif // 
