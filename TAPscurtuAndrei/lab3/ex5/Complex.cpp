#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex& Complex::operator=(const Complex& other)
{
	this->re = other.re;
	this->im = other.im;
	return *this;
}
double modul(const Complex& z)
{
	return sqrt(z.re * z.re + z.im * z.im);
}
Complex conjugat(const Complex& z)
{
	return Complex(z.re, -1*z.im);
}