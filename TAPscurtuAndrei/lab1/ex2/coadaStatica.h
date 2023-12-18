#pragma once
#ifndef COADASTATICA_H
#define COADASTATICA_H
#include <exception>
using namespace std;
class coadaAbstracta {
	public:
		virtual void enQueue(int) = 0;
		virtual int deQueue() = 0;
		virtual bool isEmpty() = 0;
		virtual bool isFull() = 0;
		virtual void print() = 0;
		class QueueOverflow : public exception {
		public:
			const char* what() const noexcept override {
				return "Queue Overflow Exception: The queue is full!";
			}
		};
		class QueueUnderflow : public exception {
		public:
			const char* what() const noexcept override {
				return "Queue Underflow Exception: The queue is empty!";
			}
		};
};
class coadaStatica : public coadaAbstracta {
private:
	int* vector;
	int size;
	int max_size;
public:
	coadaStatica(int max_size = 100);
	coadaStatica(const coadaStatica&);
	~coadaStatica();
	virtual void enQueue(int);
	virtual int deQueue();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual void print();
	virtual coadaStatica& operator=(const coadaStatica&);
#endif
};
