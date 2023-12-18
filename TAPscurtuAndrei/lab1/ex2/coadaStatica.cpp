#include "coadaStatica.h"
#include <iostream>
using namespace std;

coadaStatica::coadaStatica(int max) {
	this->max_size = max;
	this->size = 0;
	this->vector = new int[max];
}
coadaStatica::coadaStatica(const coadaStatica& c)
{
	this->max_size = c.max_size;
	this->size = c.size;
	this->vector = new int[max_size];
	for (int i = 0; i < size; i++)
		this->vector[i] = c.vector[i];
}
coadaStatica::~coadaStatica()
{
	this->max_size = 0;
	this->size = 0;
	delete[] this->vector;
}
coadaStatica& coadaStatica::operator=(const coadaStatica& c)
{
	this->max_size = c.max_size;
	this->size = c.size;
	this->vector = new int[max_size];
	for (int i = 0; i < size; i++)
		this->vector[i] = c.vector[i];
	return *this;
}
void coadaStatica::enQueue(int info)
{
	if (isFull())
		throw QueueOverflow();
	vector[size] = info;
	size++;
}
int coadaStatica::deQueue()
{
	if (isEmpty())
		throw QueueUnderflow();
	int aux = vector[0];
	for (unsigned int i = 0; i < size - 1; i++)
		vector[i] = vector[i + 1];
	size--;
	return aux;
}
bool coadaStatica::isEmpty()
{
	return(size == 0);
}
bool coadaStatica::isFull()
{
	return(size >= max_size - 1);
}
void coadaStatica::print()
{
	if(isEmpty())
		throw QueueUnderflow();
	for (unsigned int i = 0; i < size; i++)
		cout << vector[i] << " ";
	cout << endl;
}