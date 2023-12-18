#include "StivaStatica.h"
#include <iostream>
using namespace std;

StivaStatica::StivaStatica(int max) {
	this->max_size = max;
	this->top = 0;
	this->vector = new int[max];
}
StivaStatica::StivaStatica(const StivaStatica& c)
{
	this->max_size = c.max_size;
	this->top = c.top;
	this->vector = new int[max_size];
	for (int i = 0; i < top; i++)
		this->vector[i] = c.vector[i];
}
StivaStatica::~StivaStatica()
{
	this->max_size = 0;
	this->top = 0;
	delete[] this->vector;
}
StivaStatica& StivaStatica::operator=(const StivaStatica& c)
{
	this->max_size = c.max_size;
	this->top = c.top;
	this->vector = new int[max_size];
	for (int i = 0; i < top; i++)
		this->vector[i] = c.vector[i];
	return *this;
}
void StivaStatica::push(int info)
{
	if (isFull())
		throw StackOverflow();
	vector[top] = info;
	top++;
}
int StivaStatica::pop()
{
	if (isEmpty())
		throw StackUnderflow();
	top--;
	return vector[top];
}
bool StivaStatica::isEmpty()
{
	return(top == 0);
}
bool StivaStatica::isFull()
{
	return(top >= max_size - 1);
}
void StivaStatica::print()
{
	if (isEmpty())
		throw StackUnderflow();
	for (unsigned int i = 0; i < top; i++)
		cout << vector[i] <<endl;
	
}
int StivaStatica::peek()
{
	if (isEmpty())
		throw StackUnderflow();
	return vector[top-1];
}
int StivaStatica::getTop()
{
	return top;
}
int* StivaStatica::getData()
{
	return vector;
}