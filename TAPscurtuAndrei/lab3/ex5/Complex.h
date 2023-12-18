#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;
class Complex {
private:
	double re;
	double im;
public:
	Complex(double re, double im) : re(re), im(im) {}
	Complex(const Complex& other) : re(other.re), im(other.im){}
	~Complex(){}
	Complex& operator=(const Complex&);
	inline double getRe() { return re; }
	inline double getIm() { return im; }
	inline void adunare(const Complex& other)
	{
		this->re += other.re;
		this->im += other.im;
	}
	inline void scadere(const Complex& other)
	{
		this->re -= other.re;
		this->im -= other.im;
	}
	inline void imultire(const Complex& other)
	{
		double rezultatReal = this->re * other.re - this->im * other.im;
        double rezultatImaginar = this->re * other.im + this->im * other.re;
		this->re = rezultatReal;
		this->im = rezultatImaginar;
	}
	inline void impartire(const Complex& other)
	{
		double numitor = other.re * other.re + other.im * other.im;
		double rezultatReal = (this->re * other.re + this->im * other.im) / numitor;
		double rezultatImaginar = (this->im * other.re - this->re * other.im) / numitor;
		this->re = rezultatReal;
		this->im = rezultatImaginar;
	}
	friend double modul(const Complex&);
	friend Complex conjugat(const Complex&);

};
#endif 
