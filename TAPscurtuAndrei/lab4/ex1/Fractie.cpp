#include <iostream>
#include "fractie.h"
using namespace std;

Fractie::Fractie(int numarator, int numitor)
{
	if (numitor == 0)
		throw NumitorZeroException();
	this->numarator = numarator;
	this->numitor = numitor;
}
Fractie::Fractie(const Fractie& other)
{
	this->numarator = other.numarator;
	this->numitor = other.numitor;
}
Fractie& Fractie::operator=(const Fractie& other)
{
	this->numarator = other.numarator;
	this->numitor = other.numitor;
	return *this;
}
Fractie::~Fractie()
{

}
int Fractie::cmmdc(int nr1, int nr2)
{
	while (nr1 != nr2)
	{
		if (nr1 > nr2)
			nr1 = nr1 - nr2;
		else
			nr2 = nr2 - nr1;
	}
	return nr1;
}
void Fractie::simplificare()
{
	int tmp = cmmdc(this->numarator, this->numitor);
	this->numarator /= tmp;
	this->numitor /= tmp;
}
Fractie Fractie::reciproc()
{
	if (this->numarator = 0)
	{
		throw NumitorZeroException();
	}
	else
	{
		Fractie f(this->numitor, this->numarator);
		return f;
	}

}
Fractie operator+(const Fractie& f1, const Fractie& f2)
{
	if (f1.numitor == f2.numitor)
		return Fractie(f1.numarator + f2.numarator, f1.numitor);
	Fractie rez(f1.numarator * f2.numitor + f1.numitor * f2.numarator, f1.numitor * f2.numitor);
	rez.simplificare();
	return rez;
}
Fractie operator-(const Fractie& f1, const Fractie& f2)
{
	if (f1.numitor == f2.numitor)
		return Fractie(f1.numarator - f2.numarator, f1.numitor);
	Fractie rez(f1.numarator * f2.numitor - f1.numitor * f2.numarator, f1.numitor * f2.numitor);
	rez.simplificare();
	return rez;
}
Fractie operator*(const Fractie& f1, const Fractie& f2)
{
	return Fractie(f1.numarator * f2.numarator, f1.numitor * f2.numitor);
}
Fractie operator/(const Fractie& f1, const Fractie& f2)
{
	if (f2.numarator == 0)
		throw NumitorZeroException();
	Fractie rez(f1.numarator * f2.numitor, f1.numitor * f2.numarator);
	rez.simplificare();
	return rez;
}
Fractie Fractie::operator-() const
{
	return Fractie(this->numarator * -1, this->numitor);
}
Fractie& Fractie::operator+=(const Fractie& other) 
{
	if (this->numitor == other.numitor)
	{
		this->numarator += other.numarator;
		this->simplificare();
		return *this;
	}
	int tmp = this->numitor;
	this->numitor *= other.numitor;
	this->numarator = this->numarator * other.numitor + tmp * other.numarator;
	this->simplificare();
	return *this;
}
Fractie& Fractie::operator-=(const Fractie& other) 
{
	if (this->numitor == other.numitor)
	{
		this->numarator -= other.numarator;
		this->simplificare();
		return *this;
	}
	int tmp = this->numitor;
	this->numitor *= other.numitor;
	this->numarator = this->numarator * other.numitor - tmp * other.numarator;
	this->simplificare();
	return *this;
}
Fractie& Fractie::operator*=(const Fractie& other) 
{
	this->numarator *= other.numarator;
	this->numitor *= other.numitor;
	this->simplificare();
	return *this;
}
Fractie& Fractie::operator/=(const Fractie& other) 
{
	Fractie tmp = other;
	this->numarator = tmp.reciproc().numarator;
	this->numitor = tmp.reciproc().numitor;
	this->simplificare();
	return *this;
}
bool Fractie::operator<(const Fractie& other) const
{
	if (this->numitor == other.numitor)
		return(this->numarator < other.numarator);
	return(this->numarator * other.numitor < this->numitor * other.numarator);
}
bool Fractie::operator<=(const Fractie& other) const
{
	if (this->numitor == other.numitor)
		return(this->numarator <= other.numarator);
	return(this->numarator * other.numitor <= this->numitor * other.numarator);
}
bool Fractie::operator>(const Fractie& other) const
{
	if (this->numitor == other.numitor)
		return(this->numarator > other.numarator);
	return(this->numarator * other.numitor > this->numitor * other.numarator);
}
bool Fractie::operator>=(const Fractie& other) const
{
	if (this->numitor == other.numitor)
		return(this->numarator >= other.numarator);
	return(this->numarator * other.numitor >= this->numitor * other.numarator);
}
bool Fractie::operator==(const Fractie& other) const
{
	int cmmdc1 = cmmdc(this->numarator, this->numitor);
	int cmmdc2 = cmmdc(other.numarator, other.numitor);
	return((this->numarator / cmmdc1) == (other.numarator / cmmdc2)
		&& (this->numitor / cmmdc1) == (other.numitor / cmmdc2));
}
bool Fractie::operator!=(const Fractie& other) const
{
	int cmmdc1 = cmmdc(this->numarator, this->numitor);
	int cmmdc2 = cmmdc(other.numarator, other.numitor);
	return((this->numarator / cmmdc1) != (other.numarator / cmmdc2)
		&& (this->numitor / cmmdc1) != (other.numitor / cmmdc2));
}
Fractie& Fractie::operator++()
{
	this->numarator = this->numarator + this->numitor;
	return *this;
}
Fractie& Fractie::operator++(int a)
{
	Fractie f(*this);
	++*this;
	return f;
}
Fractie& Fractie::operator--()
{
	this->numarator = this->numarator - this->numitor;
	return *this;
}
Fractie& Fractie::operator--(int a)
{
	Fractie f(*this);
	--*this;
	return f;
}
ostream& operator<<(ostream& os, const Fractie& f)
{
	os << f.numarator << endl << "---" << endl << f.numitor<<endl;
	return os;
}
istream& operator>>(istream& is, Fractie& f)
{
	is >> f.numarator >> f.numitor;
	return is;
}

