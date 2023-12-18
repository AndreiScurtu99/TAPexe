#pragma once
#ifndef STIVASTATICA_H
#define STIVASTATICA_H
#include <exception>
using namespace std;
class stivaAbstracta {
public:
	virtual void push(int) = 0;
	virtual int pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void print() = 0;
	virtual int peek() = 0;
	virtual int* getData() = 0;
	virtual int getTop()=0;
	class StackOverflow : public exception {
	public:
		const char* what() const noexcept override {
			return "Queue Overflow Exception: The queue is full!";
		}
	};
	class StackUnderflow : public exception {
	public:
		const char* what() const noexcept override {
			return "Queue Underflow Exception: The queue is empty!";
		}
	};
};
class StivaStatica : public stivaAbstracta {
private:
	int* vector;
	int top;
	int max_size;
public:
	StivaStatica(int max_size = 100);
	StivaStatica(const StivaStatica&);
	~StivaStatica();
	virtual void push(int);
	virtual int pop();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual void print();
	virtual int peek();
	virtual int* getData();
	virtual int getTop();
	virtual StivaStatica& operator=(const StivaStatica&);
#endif
};
