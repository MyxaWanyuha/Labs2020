#include <cstdlib>
#include <stdexcept>
#include "MyMinMax.h"
#include "MatrixXnX.h"

inline bool equal(const int i, const int j, const int dim)
{
	return i == j;
}

inline bool sumEqualDimMinus1(const int i, const int j, const int dim)
{
	return (i + j) == (dim - 1);
}

int getSumDiag(bool (*cmp)(const int i, const int j, const int dim), const MatrixXnX& m)
{
	int res = 0;
	for (int i = 0; i < m.GetDim(); i++)
		for (int j = 0; j < m.GetDim(); j++)
			res += cmp(i, j, m.GetDim()) * m.element(i, j);
	return res;
}

int getProductDiag(bool (*cmp)(const int i, const int j, const int dim), const MatrixXnX& m)
{
	int res = 1;
	for (int i = 0; i < m.GetDim(); i++)
		for (int j = 0; j < m.GetDim(); j++)
			res *= cmp(i, j, m.GetDim()) ? m.element(i, j) : 1;
	return res;
}

int MatrixXnX::element(const int i, const int j) const
{
	if (i >= dim || i < 0 || j >= dim || j < 0)
		throw std::range_error("Out of bounds of an array\n");
	return elems[dim * i + j];
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	if (i >= dim || i < 0 || j >= dim || j < 0)
		throw std::range_error("Out of bounds of an array\n");
	elems[dim * i + j] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			elems[dim * i + j] = rand() % (maxVal - minVal + 1) + minVal;
}

int MatrixXnX::sumPrincipalDiag() const
{
	return getSumDiag(equal, *this);
}

int MatrixXnX::sumSecondaryDiag() const
{
	return getSumDiag(sumEqualDimMinus1, *this);
}

int MatrixXnX::productPrincipalDiag() const
{
	return getProductDiag(equal, *this);
}

int MatrixXnX::productSecondaryDiag() const
{
	return getProductDiag(sumEqualDimMinus1, *this);
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (int j = 0; j < dim; j++)
		sum += elems[dim * iRow + j];
	return sum;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = elems[iCol];
	for (int i = 0; i < dim; i++)
		min = elems[dim * i + iCol] < min ? elems[dim * i + iCol] : min;
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = elems[iCol];
	for (int i = 0; i < dim; i++)
		max = elems[dim * i + iCol] > max ? elems[dim * i + iCol] : max;
	return max;
}
