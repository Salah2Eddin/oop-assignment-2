#ifndef CLION_BIGREAL_H
#define CLION_BIGREAL_H
#include "BigDecimalIntClass.h"
#include <bits/stdc++.h>

class BigReal {
private:
    BigDecimalInt *pReal;
    BigDecimalInt *pFraction;
    int sign;
public:
    //void setNum(string);
    BigReal() = default;

    BigReal(double realNumber); // Default constructor
    BigReal(string realNumber);

    BigReal(BigDecimalInt bigInteger);

    BigReal(const BigReal &other); // Copy constructor
    BigReal(BigReal &&other); // Move constructor
    BigReal &operator=(BigReal &other); // Assignment operator
    BigReal &operator=(BigReal &&other); // Move assignment
    BigReal operator+(BigReal &other);

    BigReal operator-(BigReal &other);

    bool operator<(BigReal anotherReal);

    bool operator>(BigReal anotherReal);

    bool operator==(BigReal anotherReal);

    int size();

    int getSign();

    friend ostream &operator<<(ostream &out, BigReal &num);

    friend istream &operator>>(istream &in, BigReal &num);

    void setSign(char sign);
};
#endif //CLION_BIGREAL_H
