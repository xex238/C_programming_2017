#ifndef Programka
#define Programka
#include <iostream>
#include <sstream>
using namespace std;
struct Kvaternion
{
	int q[2][2]{ 0, 0, 0, 0 };
	Kvaternion(int a11, int a12, int a21, int a22)
	{
		q[0][0] = a11;
		q[0][1] = a12;
		q[1][0] = a21;
		q[1][1] = a22;
	}
	Kvaternion() = default;
	~Kvaternion() = default;

	int opredelitel()
	{
		return (this->q[0][0] * this->q[1][1] - this->q[1][0] * this->q[0][1]);
	}

	ostream& writeTo(ostream& ostr) const;
	istream& readFrom(istream& isrm);
};

inline ostream& operator<< (ostream& ostr, const Kvaternion& q1)
{
	return q1.writeTo(ostr);
}

inline istream& operator >> (istream& isrm, Kvaternion& q1)
{
	return q1.readFrom(isrm);
}

Kvaternion operator+ (const Kvaternion& q1, const Kvaternion& q2);
Kvaternion operator- (const Kvaternion& q1, const Kvaternion& q2);
Kvaternion operator* (const Kvaternion& q1, const Kvaternion& q2);
Kvaternion operator/ (const Kvaternion& q1, const Kvaternion& q2);

Kvaternion operator* (const Kvaternion& q1, const int q2);
Kvaternion operator/ (const Kvaternion& q1, const int q2);

Kvaternion operator* (const int q1, const Kvaternion& q2);
Kvaternion operator/ (const int q1, const Kvaternion& q2);

#endif // !Programke
