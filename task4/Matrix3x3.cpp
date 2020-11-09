#include <cstdlib>
#include <stdexcept>
#include "MyMinMax.h"
#include "Matrix3x3.h"

inline bool equal(const int i, const int j)
{
	return i == j;
}

inline bool sumEqual2(const int i, const int j)
{
	return (i + j) == 2;
}

int getSumDiag(bool (*cmp)(const int i, const int j), const Matrix3x3& m)
{
	int res = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			res += cmp(i, j) * m.element(i, j);
	return res;
}

int getProductDiag(bool (*cmp)(const int i, const int j), const Matrix3x3& m)
{
	int res = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			res *= cmp(i, j) ? m.element(i, j) : 1;
	return res;
}

int Matrix3x3::element(const int i, const int j) const
{
	if (i >= 3 || i < 0 || j >= 3 || j < 0)
		throw std::range_error("Out of bounds of an array\n");
	return elems[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	if (i >= 3 || i < 0 || j >= 3 || j < 0)
		throw std::range_error("Out of bounds of an array\n");
	elems[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			elems[i][j] = rand() % (maxVal - minVal + 1) + minVal;
}

int Matrix3x3::sumPrincipalDiag() const
{
	return getSumDiag(equal, *this);
}

int Matrix3x3::sumSecondaryDiag() const
{
	return getSumDiag(sumEqual2, *this);
}

int Matrix3x3::productPrincipalDiag() const
{
	return getProductDiag(equal, *this);
}

int Matrix3x3::productSecondaryDiag() const
{
	return getProductDiag(sumEqual2, *this);
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (int j = 0; j < 3; j++)
		sum += elems[iRow][j];
	return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
	return min(elems[0][iCol], min(elems[1][iCol], elems[2][iCol]));
}

int Matrix3x3::maxColumn(const int iCol) const
{
	return max(elems[0][iCol], max(elems[1][iCol], elems[2][iCol]));
}
