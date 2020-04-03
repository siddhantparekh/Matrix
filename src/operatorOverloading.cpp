//
// Created by siddhant on 18/2/19.
//

#include "matrix.hpp"

double*& Matrix::operator[](ulong index) const
{
    if(index >= this->rows)
    {
        cerr<<"Invalid index.\n";
        exit(1);
    }
    return (matrix[index]);
}

bool Matrix::operator==(const Matrix &rop) const
{
    if(this->rows != rop.rows || this->cols != rop.cols)
        return false;

    //Compare every element of both matrices
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            if(this->matrix[i][j] != rop.matrix[i][j])
                return false;

    return true;
}