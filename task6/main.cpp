#include <iostream>
#include "values.h"

void Test();

int main()
{
    Test();
    Cvalue c{ 10. * 1e-6 };
    Rvalue r{ 200. * 1000 };
    Uvalue u{ 1. };
    Ivalue i{ u / r };
    for (auto t = 0.; (t - 2.) < 1e-6; t += 0.1)
    {
        Qvalue q{ i * Tvalue{t} };
        u = q / c;
        std::cout << "t = " << t << '\t'
                  <<  u << '\n';
    }
}

void Test()
{
    Rvalue r{ 4. };
    Ivalue i{ 2. };
    Uvalue u{ i * r };
    std::cout << "i * r = " << i.getValue() << " * " << r.getValue() << " = " << u << '\n';
    std::cout << "u / r = " << u.getValue() << " / " << r.getValue() << " = " << u / r << '\n';
    std::cout << "u / i = " << u.getValue() << " / " << i.getValue() << " = " << u / i << '\n';

    Rvalue r1{ 1. };
    Rvalue r2{ 2. };
    std::cout << "r1 + r2 = " << r1.getValue() << " + " << r2.getValue() << " = " << r1 + r2 << '\n';
    std::cout << "r1 % r2 = (" << r1.getValue() << " + " << r2.getValue()  << ")/(" 
              << r1.getValue() << " * " << r2.getValue() << ") = " << r1 % r2 << '\n';

    Cvalue c1{ 1. };
    Cvalue c2{ 6. };
    std::cout << "c1 + c2 = " << c1.getValue() << " + " << c2.getValue() << " = " << c1 + c2 << '\n';
    std::cout << "c1 % c2 = (" << c1.getValue() << " + " << c2.getValue() << ")/("
              << c1.getValue() << " * " << c2.getValue() << ") = " << c1 % c2 << "\n\n";
}
