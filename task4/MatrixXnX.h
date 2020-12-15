#pragma once
class MatrixXnX
{
public:
	MatrixXnX(const unsigned int iDim) : elems(new int[iDim * iDim]), dim(iDim) {};
	~MatrixXnX() { delete[] elems; }
	MatrixXnX(const MatrixXnX&) = delete;
	MatrixXnX& operator=(const MatrixXnX&) = delete;

	int element(const int i, const int j) const;
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;
	int GetDim() const { return dim; };
private:
	int* elems;
	int dim;
};

