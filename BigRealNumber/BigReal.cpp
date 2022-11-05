#include "BigReal.h"

BigReal::BigReal(double realNumber) {
    int integer = realNumber;
    double fraction = realNumber - integer;

    string tempInteger = to_string(integer);
    string tempFraction = to_string(fraction);
    if (realNumber < 0)
        tempFraction = tempFraction.substr(3, tempFraction.size() - 3);
    else
        tempFraction = tempFraction.substr(2, tempFraction.size() - 2);
    this->pReal = new BigDecimalInt(tempInteger);
    this->pFraction = new BigDecimalInt(tempFraction);
    this->sign = (realNumber < 0 ? 0 : 1);
    if (!sign) {
        this->pReal->setSign('-');
        this->pFraction->setSign('-');
    }
}


BigReal::BigReal(string realNumber) {
    bool isValid = regex_match(realNumber, regex("[-+]?[0-9]+[.]?[0-9]+"));

    if (!isValid) {
        throw std::invalid_argument("Invalid decimal string");
        return;
    }

    string tempInteger, tempFraction;
    bool flag = false;
    for (char i: realNumber) {
        if (i == '.') {
            flag = true;
            continue;
        }
        if (flag) {
            tempFraction.push_back(i);
        } else tempInteger.push_back(i);
    }
    this->pReal = new BigDecimalInt(tempInteger);
    this->pFraction = new BigDecimalInt(tempFraction);
    this->sign = (realNumber[0] == '-' ? 0 : 1);
    if (!sign) {
        this->pReal->setSign('-');
        this->pFraction->setSign('-');
    }
}


BigReal::BigReal(BigDecimalInt bigInteger) {
    this->pReal = &bigInteger;
    this->pFraction = new BigDecimalInt("0");
    this->sign = bigInteger.sign();
    if (!sign) {
        this->pReal->setSign('-');
        this->pFraction->setSign('-');
    }
}


BigReal::BigReal(const BigReal &other) {
    this->pReal = other.pReal;
    this->pFraction = other.pFraction;
    this->sign = other.sign;
}


BigReal::BigReal(BigReal &&other) {
    if (this != &other) {
        this->pReal = other.pReal;
        this->pFraction = other.pFraction;
        this->sign = other.sign;
        // delete &other;
    }
}


BigReal &BigReal::operator=(BigReal &other) {
    this->pReal = other.pReal;
    this->pFraction = other.pFraction;
    this->sign = other.sign;

    return *this;
}


BigReal &BigReal::operator=(BigReal &&other) {
    if (this != &other) {
        this->pReal = other.pReal;
        this->pFraction = other.pFraction;
        this->sign = other.sign;
        delete &other;
    }
    return *this;
}


bool BigReal::operator<(BigReal anotherReal) {
    if (this->pReal < anotherReal.pReal) {
        return true;
    } else if (this->pReal == anotherReal.pReal) {
        if (this->pFraction < anotherReal.pFraction) {
            return true;
        } else
            return false;
    }
    return false;
}


bool BigReal::operator>(BigReal anotherReal) {
    return anotherReal < *this;
}

bool BigReal::operator==(BigReal anotherReal) {
    return (!(anotherReal < *this) && !(anotherReal > *this));
}

int BigReal::size() {
    int sz = this->pReal->size() + this->pFraction->size();
    return sz;
}

int BigReal::getSign() {
    return this->sign;
}


BigReal BigReal::operator+(BigReal &other) {
    if (this->getSign() && !other.getSign()) {
        BigReal temp = other;
        temp.setSign('+');
        temp.pReal->setSign('+');
        temp.pFraction->setSign('+');
        return *this - temp;
    } else if (!this->getSign() && other.getSign()) {
        BigReal temp = *this;
        temp.setSign('+');
        temp.pReal->setSign('+');
        temp.pFraction->setSign('+');
        BigReal temp2 = temp - other;
        temp2.setSign('-');
        temp2.pReal->setSign('-');
        temp2.pFraction->setSign('-');
        return temp2;
    } else if (!this->getSign() && !other.getSign()) {
        BigReal temp = other - *this;
        temp.setSign('-');
        temp.pReal->setSign('-');
        temp.pFraction->setSign('-');
        return temp;
    }

    BigReal ans("0.0");
    BigDecimalInt integer = *this->pReal + *other.pReal;
    int sz1 = this->pFraction->size();
    int sz2 = other.pFraction->size();

    string temp = (sz1 < sz2 ? this->pFraction->getNumber() : other.pFraction->getNumber());
    bool first = true;
    while (sz1 > sz2) {
        temp.push_back('0');
        sz2++;
    }

    while (sz1 < sz2) {
        temp.push_back('0');
        sz1++;
        first = false;
    }

    BigDecimalInt tempFraction(temp);
    string addition;
    int i = 0;
    int carry = 0;

    while (i < sz1 && i < sz2) {
        int sum;

        if (first) {
            sum = this->pFraction->getNumber()[i] + tempFraction.getNumber()[i] - 2 * '0' + carry;
        } else {
            sum = other.pFraction->getNumber()[i] + tempFraction.getNumber()[i] - 2 * '0' + carry;
        }

        addition.push_back((sum % 10) + '0');
        carry = sum / 10;
        i++;
    }
    if (carry) {
        integer = integer + BigDecimalInt("1");
    }

    ans.pReal = &integer;
    ans.pFraction = new BigDecimalInt(addition);
    ans.sign = (integer.sign() == 1 ? 1 : 0);

    return ans;
}

BigReal BigReal::operator-(BigReal &other) {
    if (this->getSign() && !other.getSign()) {
        BigReal temp = other;
        temp.setSign('+');
        temp.pReal->setSign('+');
        temp.pFraction->setSign('+');
        return *this + temp;
    } else if (!this->getSign() && other.getSign()) {
        BigReal temp = (*this + other);
        temp.setSign('-');
        temp.pReal->setSign('-');
        temp.pFraction->setSign('-');
        return temp;
    } else if (!this->getSign() && !other.getSign()) {
        BigReal temp = other;
        temp.setSign('+');
        temp.pReal->setSign('+');
        temp.pFraction->setSign('+');
        return temp + *this;
    }


    BigReal ans("0.0");
    BigDecimalInt integer = *this->pReal - *other.pReal;
    int sz1 = this->pFraction->size();
    int sz2 = other.pFraction->size();

    string temp = (sz1 < sz2 ? this->pFraction->getNumber() : other.pFraction->getNumber());
    bool first = true;
    while (sz1 > sz2) {
        temp.push_back('0');
        sz2++;
    }

    while (sz1 < sz2) {
        temp.push_back('0');
        sz1++;
        first = false;
    }

    BigDecimalInt tempFraction(temp);
    string subtraction;
    int i = 0;
    int carry = 0;

    while (i < sz1 && i < sz2) {
        int sub;
        if (first) {
            sub = this->pFraction->getNumber()[i] - tempFraction.getNumber()[i] - carry;
        } else {
            sub = other.pFraction->getNumber()[i] - tempFraction.getNumber()[i] - carry;
        }
        if (sub < 0) {
            carry = 1;
            sub += 10;
        } else {
            carry = 0;
        }
        subtraction.push_back(sub + '0');
        i++;
    }
    if (carry) {
        integer = integer - BigDecimalInt("1");
    }

    ans.pReal = &integer;
    ans.pFraction = new BigDecimalInt(subtraction);
    ans.sign = (integer.sign() == 1 ? 1 : 0);

    return ans;
}


ostream &operator<<(ostream &out, BigReal &num) {
    if (!num.sign) out << '-';
    out << num.pReal->getNumber();
    if (num.pFraction->getNumber() != "0") {
        out << ".";
        out << num.pFraction->getNumber();
    }
    return out;
}


istream &operator>>(istream &in, BigReal &num) {
    string s;
    in >> s;
    num = BigReal(s);
    return in;
}

void BigReal::setSign(char sign) {
    this->sign = (sign == '-' ? 0 : 1);
}
