#pragma once
#ifndef FRACTIE_H
#define FRACTIE_H
class Fractie {
private:
	int numarator;
	int numitor;
public:
	Fractie(int numarator = 0, int numitor = 1);
	Fractie(const Fractie&);
	Fractie& operator=(const Fractie&);
	~Fractie();
	void adunare(int,int);
	void scadere(int, int);
	void imultire(int, int);
	void impartire(int, int);
	static int cmmdc(int, int);
	void simplificare();
	Fractie reciproc();
	bool egal(const Fractie&);
	void print();
};
#endif FRACTIE_H