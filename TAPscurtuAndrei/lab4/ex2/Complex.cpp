#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex(int re, int im) :re(re), im(im){}
Complex::Complex(const Complex& other) :re(other.re), im(other.im){}
Complex::~Complex(){}
Complex& Complex::operator=(const Complex& other)
{
	this->re = other.re;
	this->im = other.im;
	return *this;
}
Complex& Complex::operator+=(const Complex& other)
{
	this->re += other.re;
	this->im += other.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& other)
{
	this->re -= other.re;
	this->im -= other.im;
	return *this;
}
Complex& Complex::operator*=(const Complex& other)
{
	double rezultatReal = this->re * other.re - this->im * other.im;
	double rezultatImaginar = this->re * other.im + this->im * other.re;
	this->re = rezultatReal;
	this->im = rezultatImaginar;
	return *this;
}
Complex& Complex::operator/=(const Complex& other)
{
	double numitor = other.re * other.re + other.im * other.im;
	double rezultatReal = (this->re * other.re + this->im * other.im) / numitor;
	double rezultatImaginar = (this->im * other.re - this->re * other.im) / numitor;
	this->re = rezultatReal;
	this->im = rezultatImaginar;
	return* this;
}
