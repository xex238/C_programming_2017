#include "complex.h"
#include <iostream>
#include <sstream>

// Êîíñòðóêòîð äëÿ íå êîìïëåêñíîãî ÷èñëà
Complex::Complex(const double real) : Complex(real, 0.0) 
{

}

// Êîíñòðóêòîð äëÿ êîìïëåêñíîãî ÷èñëà
Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) 
{

}

// Complex++
Complex& Complex::operator+= (const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-= (const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*= (const Complex& rhs)
{
	re *= rhs.re;
	im *= rhs.im;
	return *this;
}

Complex& Complex::operator/= (const Complex& rhs)
{
	re /= rhs.re;
	im /= rhs.im;
	return *this;
}

// Complex + Complex
Complex operator+ (const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator- (const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator* (const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re * rhs.re, lhs.im * rhs.im);
}

Complex operator/ (const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re / rhs.re, lhs.im / rhs.im);
}

// Complex + double
Complex operator+ (const Complex& q1, const double q2)
{
	return Complex(q1.re + q2, q1.im);
}

Complex operator- (const Complex& q1, const double q2)
{
	return Complex(q1.re - q2, q1.im);
}

Complex operator* (const Complex& q1, const double q2)
{
	return Complex(q1.re * q2, q1.im);
}

Complex operator/ (const Complex& q1, const double q2)
{
	return Complex(q1.re / q2, q1.im);
}

//double + Complex
Complex operator+(const double q1, const Complex& q2)
{
	return Complex(q1 + q2.re, q2.im);
}

Complex operator-(const double q1, const Complex& q2)
{
	return Complex(q1 - q2.re, q2.im);
}

Complex operator*(const double q1, const Complex& q2)
{
	return Complex(q1 * q2.re, q2.im);
}

Complex operator/(const double q1, const Complex& q2)
{
	return Complex(q1 / q2.re, q2.im);
}

bool operator< (const Complex& q1, const Complex& q2)
{
	if (q1.re < q2.re)
		return true;
	else if ((q1.re == q2.re) && (q1.im<q2.im))
	{
		return true;
	}
	else return false;
}

bool operator> (const Complex& q1, const Complex& q2)
{
	return !operator<(q1, q2);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::rightBrace == rightBrace) && (Complex::separator == comma) && (Complex::leftBrace == leftBrace))
		{
			re = real;
			im = imaginary;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
