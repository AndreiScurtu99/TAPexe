#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;
#include <iostream>

class Complex {
private:
	double re;
	double im;
public:
	Complex(int numarator = 0, int numitor = 1);
	Complex(const Complex&);
	Complex& operator=(const Complex&);
	~Complex();
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);
	bool operator<(const Complex&) const;
	bool operator<=(const Complex&) const;
	bool operator>(const Complex&) const;
	bool operator>=(const Complex&) const;
	bool operator!=(const Complex&) const;
	bool operator==(const Complex&) const;
	Complex operator-() const;
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	Complex& operator++();
	Complex& operator++(int a);
	Complex& operator--();
	Complex& operator--(int a);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	inline friend double modul(const Complex& z) { return z.re * z.re + z.im * z.im; }
	inline friend Complex reciproc(const Complex& z) { return Complex(z.re, -1 * z.im); }


};

#endif