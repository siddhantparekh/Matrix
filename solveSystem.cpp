//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

void Matrix::pivotMatrix(ulong rowToBeInterchanged)
{
    CONDITIONAL_PRINT<<"In Function pivotMatrix().\n";

    ulong i = rowToBeInterchanged + 1;

    //Search for a row with non-zero diagonal element.
    while(i < this->rows && this->matrix[i][rowToBeInterchanged]==0)
        i++;

    if(i == this->rows)
    {
        cout<<"Cannot pivot.\n";
        exit(4);
    }

    //Interchange the rowToBeInterchanged with the row found.
    this->interchangeRows(rowToBeInterchanged, i);
}

Matrix Matrix::backSubstitution() const
{
    CONDITIONAL_PRINT<<"In function backSubstitution().\n";

    double sum;
    Matrix solutionMatrix(this->rows, 1);

    for(ulong i=solutionMatrix.rows; i > 0; i--)
    {
        sum = 0;
        for(ulong j=solutionMatrix.rows; j > i; j--)
        {
            sum += this->matrix[i-1][j-1] * solutionMatrix.matrix[j-1][0];
        }

        solutionMatrix.matrix[i-1][0] = this->matrix[i-1][this->cols-1] - sum;
    }
}

Matrix Matrix::solveTriangularMatrix() const
{
    CONDITIONAL_PRINT<<"In function solveSystemOfEquations().\n";

    Matrix triangularMatrices = this->triangularFactorizationCrouts();

    Matrix Z(this->rows, 1);

    double sum;

    //Compute Z
    for(ulong i=0; i < this->rows; i++)
    {
        sum = 0;
        for(ulong j=0; j < i; j++)
            sum += triangularMatrices.matrix[i][j] * Z.matrix[j][0];

        Z.matrix[i][0] = (this->matrix[i][this->cols-1] - sum) / triangularMatrices.matrix[i][i];
    }

    Matrix upperTriangular(this->rows, this->cols);

    //Create upper triangular matrix
    for(ulong i=0; i < this->rows; i++)
    {
        for(ulong j=0; j < this->rows; j++)
            this->matrix[i][j] = triangularMatrices.matrix[i][j];
        this->matrix[i][this->cols-1] = Z.matrix[i][0];
    }

    return upperTriangular.backSubstitution();
}