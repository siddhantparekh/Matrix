//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

bool Matrix::exists() const
{
    CONDITIONAL_PRINT<<"In function exists().\n";

    return rows > 0 && cols > 0;
}


bool Matrix::isSquareMatrix() const
{
    CONDITIONAL_PRINT<<"In function isSquareMatrix().\n";

    return this->rows==this->cols;
}

bool Matrix::isIdentityMatrix() const
{
    CONDITIONAL_PRINT<<"In function isIdentityMatrix().\n";

    if(!this->isSquareMatrix())
        return false;

    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
        {
            //check whether the diagonal elements are one
            if(i==j && this->matrix[i][j]!=1)
                return false;

                //check whether the non-diagonal elements are zero
            else if(i!=j && this->matrix[i][j]!=0)
                return false;
        }

    return true;
}

bool Matrix::isSymmetricMatrix() const
{
    CONDITIONAL_PRINT<<"In function isSymmetricMatrix().\n";

    if(!this->isSquareMatrix())
        return false;

    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < i; ++j)
        {
            //check whether the mirror elements are equal.
            if(this->matrix[i][j] != this->matrix[j][i])
                return false;
        }

    return true;
}

bool Matrix::isNullMatrix() const
{
    CONDITIONAL_PRINT<<"In function isNullMatrix().\n";

    //check whether all the elements are zero.
    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
            if(matrix[i][j] != 0)
                return false;

    return true;
}

bool Matrix::isDiagonalMatrix() const
{
    CONDITIONAL_PRINT<<"In function isIdentityMatrix().\n";

    for(ulong i=0; i < this->rows; ++i)
        for(ulong j=0; j < this->cols; ++j)
        {
            //check whether the diagonal elements are non-zero.
            if(i==j && this->matrix[i][j]==0)
                return false;

                //check whether the non-diagonal elements are zero.
            else if(i!=j && this->matrix[i][j]!=0)
                return false;
        }

    return true;
}

bool Matrix::isDiagonallyDominant() const
{
    CONDITIONAL_PRINT<<"In function isDiagonallyDominant().\n";

    double sum;

    //sum the non-diagonal elements in every row and check whether it is less than the diagonal element of that row.
    for(ulong i=0; i < this->rows; ++i)
    {
        sum = 0;
        for(ulong j = 0; j < this->cols; ++j)
            if(i!=j)
                sum += abs(this->matrix[i][j]);
        if(sum >= abs(this->matrix[i][i]))
            return false;
    }

    return true;
}

bool Matrix::isOrthogonal() const
{
    CONDITIONAL_PRINT<<"In function isOrthogonal().\n";

    Matrix A_transpose = this->transpose();
    Matrix product = (*this)*A_transpose;

    return product.isIdentityMatrix();
}