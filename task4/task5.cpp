#include <iostream>
#include "Matrix3x3.h"
#include "MatrixXnX.h"

void WorkWithMatrix3x3();
void WorkWithMatrixXnX();

int main()
{
    WorkWithMatrix3x3();
    WorkWithMatrixXnX();
    return 0;
}

void WorkWithMatrix3x3()
{
    std::cout << "______________Matrix3x3______________\n";
    Matrix3x3 matr3;
    matr3.fillRandomElements(-10, 10);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << matr3.element(i, j) << '\t';
        std::cout << '\n';
    }

    for (int i = 0; i < 3; i++)
        std::cout << "row " << i << ' ' << matr3.sumRow(i) << '\n';

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Column " << i
            << " max: " << matr3.maxColumn(i)
            << " min: " << matr3.minColumn(i) << '\n';
    }

    std::cout << "sumPrincipal = " << matr3.sumPrincipalDiag() << '\n'
              << "sumSecondary = " << matr3.sumSecondaryDiag() << '\n'
              << "productPrincipal = " << matr3.productPrincipalDiag() << '\n'
              << "productSecondary = " << matr3.productSecondaryDiag() << '\n';
}

void WorkWithMatrixXnX()
{
    std::cout << "______________MatrixXnX______________\n";
    MatrixXnX matrn(4);
    matrn.fillRandomElements(-10, 10);

    for (int i = 0; i < matrn.GetDim(); i++)
    {
        for (int j = 0; j < matrn.GetDim(); j++)
            std::cout << matrn.element(i, j) << '\t';
        std::cout << '\n';
    }

    for (int i = 0; i < matrn.GetDim(); i++)
        std::cout << "row " << i << ' ' << matrn.sumRow(i) << '\n';

    for (int i = 0; i < matrn.GetDim(); i++)
    {
        std::cout << "Column " << i 
                  << " max: " << matrn.maxColumn(i)
                  << " min: " << matrn.minColumn(i) << '\n';
    }

    std::cout << "sumPrincipal = " << matrn.sumPrincipalDiag() << '\n'
              << "sumSecondary = " << matrn.sumSecondaryDiag() << '\n'
              << "productPrincipal = " << matrn.productPrincipalDiag() << '\n'
              << "productSecondary = " << matrn.productSecondaryDiag() << '\n';
}
