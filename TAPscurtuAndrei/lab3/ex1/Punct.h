#pragma
#ifndef PUNCT_H
#define PUNCT_H


class Punct {
private:
    double x;
    double y;

    static int punctePeDreapta;
    static int semiplanPozitiv;
    static int semiplanNegativ;

public:
    Punct();
    Punct(double abs, double ord);
    Punct(const Punct& other);
    ~Punct();
    inline double getX() { return x; }
    inline double getY() { return y; }
    friend double distanta(const Punct& p1, const Punct& p2);

    inline static int getPunctePeDreapta() { return punctePeDreapta; }
    inline static int getSemiplanPozitiv() { return semiplanPozitiv; }
    inline static int getSemiplanNegativ() { return semiplanNegativ; }
};
class Dreapta {
private:
    double m;
    double n;

public:
    Dreapta();
    Dreapta(double, double);
    Dreapta(const Dreapta&);
    ~Dreapta();

    friend class Punct;

    inline double getPanta() { return m; }
    inline double getOrdonata() { return n; }
};

#endif 

