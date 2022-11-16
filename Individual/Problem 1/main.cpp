#include <bits/stdc++.h>
using namespace std;

class Function{
public:
    virtual double evaluateAt(double value) = 0;
};


class SimpleFunction : public Function{
private :
    function<double(double)> fun;

public :
    SimpleFunction(function<double(double)>fun){
        this->fun = fun;
    }

    double evaluateAt(double value) override{
        return fun(value);
    }
};

double funsqrt(double x){
    return sqrt(x);
}


class DervativeFunction : public Function{
private:
    double changeX;
    function<double(double)> fun;
public:
    DervativeFunction(function<double(double)> fun, double changeX){
        this->fun = fun;
        this->changeX = changeX;
    }
    double evaluateAt(double value) override{
        double res = (fun(value + changeX) - fun(value - changeX)) / (2 * changeX);
        return res;
    }
};

class CompostionFunction : public Function{
private:
    function<double(double)> fun;
    function<double(double)> fun2;
public:
    CompostionFunction(function<double(double)> fun,function<double(double)> fun2){
        this->fun = fun;
        this->fun2 = fun2;
    }
    double evaluateAt(double value) override{
        return fun(fun2(value));
    }
};

int main() {
    SimpleFunction sqrtFun(funsqrt);
    cout << sqrtFun.evaluateAt(25) << endl;

    cout << funsqrt(25) << endl;

    SimpleFunction cubicFun([](double x){return x * x * x;});
    cout << cubicFun.evaluateAt(5) << endl;

    DervativeFunction dervFun([](double x){return (x * x - 5 * x - 4);}, 5);
    cout << dervFun.evaluateAt(5) << endl;

    CompostionFunction compFun([](double d){return d * d - 3 * d - 4;}, [](double n){return n * n * n;});
    cout << compFun.evaluateAt(5) << endl;
    return 0;
}
