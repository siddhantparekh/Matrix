//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

Matrix& Matrix::operator=(const Matrix &matrixToBeAssigned)
{
    CONDITIONAL_PRINT<<"In function operator=().\n";

    if(this->exists())
        this->deallocateMemory();

    this->setDimensions(matrixToBeAssigned.rows, matrixToBeAssigned.cols);

    //Assign the elements from one matrix to another.
    for(ulong i = 0; i < this->rows; ++i)
        for(ulong j = 0; j < this->cols; ++j)
            this->matrix[i][j] = matrixToBeAssigned.matrix[i][j];

    CONDITIONAL_PRINT<<"Values assigned successfully.\n";

    //By convention return *this.
    return(*this);

}

Matrix Matrix::operator+(const Matrix &matrixToBeAdded) const
{
    CONDITIONAL_PRINT<<"In function operator+().\n";

    if(this->rows != matrixToBeAdded.rows || this->cols != matrixToBeAdded.cols)
    {
        cerr<<"Invalid operation.\n";
        exit(2);
    }

    Matrix sum(this->rows, this->cols);

    //Add the elements of the two matrices.
    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
            sum.matrix[i][j] = this->matrix[i][j] + matrixToBeAdded.matrix[i][j];

    return sum;
}

Matrix Matrix::operator-(const Matrix &matrixToBeSubtracted) const
{
    CONDITIONAL_PRINT<<"In function operator-().\n";

    if(this->rows != matrixToBeSubtracted.rows || this->cols != matrixToBeSubtracted.cols)
    {
        cerr<<"Invalid operation.\n";
        exit(2);
    }

    Matrix difference(this->rows, this->cols);

    //Subtract the elements of one matrix from another.
    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
            difference.matrix[i][j] = this->matrix[i][j] - matrixToBeSubtracted.matrix[i][j];

    return difference;
}

Matrix Matrix::operator*(double scalar) const
{
    CONDITIONAL_PRINT<<"In function operator*(scalar). Multiplication by a scalar.\n";

    Matrix product(this->rows, this->cols);

    //Multiply the elements of the matrix with the scalar.
    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
            product.matrix[i][j] = this->matrix[i][j] * scalar;

    return product;
}

Matrix Matrix::operator*(const Matrix &matrixToBeMultiplied) const
{
    CONDITIONAL_PRINT<<"In function operator*(matrix). Multiplication by another matrix.\n";

    if(this->cols == matrixToBeMultiplied.rows)
    {
        Matrix product(this->rows, matrixToBeMultiplied.cols);

        //Multiply the elements of each row of matrix 1 and column of matrix 2 and sum them.
        for(ulong i=0; i < this->rows; ++i)
            for(ulong j=0; j < matrixToBeMultiplied.cols; ++j)
                for(ulong k=0; k < matrixToBeMultiplied.rows; ++k)
                    product.matrix[i][j] += this->matrix[i][k] * matrixToBeMultiplied.matrix[k][j];

        return product;
    }
    else
    {
        cerr<<"Invalid operation.\n";
        exit(2);
    }
}