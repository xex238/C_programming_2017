#ifndef Programka
#define Programka

#include <iosfwd>
#include <string>
#include <ostream>
#include <sstream>
using namespace std;

template <typename T>
struct Vector
{
private:
	T x{ 0.0 };
	T y{ 0.0 };
	T z{ 0.0 };
public:
	Vector() = default;
	~Vector() = default;
	Vector(T x, T y, T z) : x(x), y(y), z(z)
	{

	}
	Vector& operator-=(const Vector<T>& q1);
	Vector& operator+=(const Vector<T>& q1);
	Vector& operator*=(const Vector<T>& q1);
	Vector& operator/=(const Vector<T>& q1);
	Vector& operator*=(const double q1);
	Vector& operator/=(const double q2);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

};

template <typename T>
inline std::ostream& operator<<(std::ostream& ostrm, Vector<T> q)
{
	return q.writeTo(ostrm);
}

template <typename T>
inline std::istream& operator>> (std::istream& istrm, Vector<T> q)
{
	return q.readFrom(istrm);
}


template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& q1)
{
	x -= q1.x;
	y -= q1.y;
	z -= q1.z;
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& q1)
{
	x += q1.x;
	y += q1.y;
	z += q1.z;
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator*=(const Vector<T>& q1)
{
	x *= q1.x;
	y *= q1.y;
	z *= q1.z;
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(const Vector<T>& q1)
{
	x /= q1.x;
	y /= q1.y;
	z /= q1.z;
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator*=(const double q1)
{
	x *= q1;
	y *= q1;
	z *= q1;
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator/=(const double q2)
{
	x /= q2;
	y /= q2;
	z /= q2;
	return *this;
}


template <typename T>
Vector<T> operator+(const Vector<T>& q1, const Vector<T>& q2)
{
	Vector<T> w(q1);
	w += q2;
	return w;
}

template <typename T>
Vector<T> operator-(const Vector<T>& q1, const Vector<T>& q2)
{
	Vector<T> w(q1);
	w -= q2;
	return w;
}

template <typename T>
Vector<T> operator*(const Vector<T>& q1, const Vector<T>& q2)
{
	Vector<T> w(q1);
	w *= q2;
	return w;
}

template <typename T>
Vector<T> operator/(const Vector<T>& q1, const Vector<T>& q2)
{
	Vector<T> w(q1);
	w /= q2;
	return w;
}

template <typename T>
Vector<T> operator*(const Vector<T>& q1, const double q2)
{
	Vector<T> w(q1);
	w *= q2;
	return w;
}

template <typename T>
Vector<T> operator/(const Vector<T>& q1, const double q2)
{
	Vector<T> w(q1);
	w /= q2;
	return w;
}

template <typename T>
std::ostream& Vector<T>::writeTo(std::ostream& ostrm) const
{
	ostrm << x << ", " << y << ", " << z << ";";
	return ostrm;
}

template <typename T>
std::istream& Vector<T>::readFrom(std::istream & istrm)
{
	return istrm;
}
#endif // 
