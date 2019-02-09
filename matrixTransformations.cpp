//
// Created by siddhant on 7/2/19.
//

#include "matrix.hpp"

void Matrix::interchangeRows(ulong r1, ulong r2)
{
    double temp;
    for(ulong j=0; j < this->cols; ++j)
    {
        temp = this->matrix[r1][j];
        this->matrix[r1][j] = this->matrix[r2][j];
        this->matrix[r2][j] = temp;
    }
}

Matrix Matrix::transpose() const
{
    CONDITIONAL_PRINT<<"In function transpose().\n";

    Matrix transposedMatrix(this->cols, this->rows);

    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
            transposedMatrix.matrix[j][i] = this->matrix[i][j];

    return transposedMatrix;
}

//Friend function
Matrix augmentMatrices(const Matrix &A, const Matrix &B)
{
    CONDITIONAL_PRINT<<"In function augmentMatrices().n";

    if(A.rows != B.rows)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    Matrix augmentedMatrix(A.rows, A.cols+B.cols);

    //Assign elements of A and B
    for(ulong i=0; i<A.rows; ++i)
    {
        //Assign elements of A
        for(ulong j=0; j<A.cols; ++j)
            augmentedMatrix.matrix[i][j] = A.matrix[i][j];
        //Assign elements of B
        for(ulong j=A.cols; j<augmentedMatrix.cols; ++j)
            augmentedMatrix.matrix[i][j] = B.matrix[i][j-A.cols];
    }

    return augmentedMatrix;
}