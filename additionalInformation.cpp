//
// Created by siddhant on 7/2/19.
//

#include "matrix.hpp"

double Matrix::traceOfMatrix() const
{
    CONDITIONAL_PRINT<<"In function traceOfMatrix().\n";

    if(!isSquareMatrix())
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    double sum=0;
    for(ulong i=0; i<this->rows; ++i)
        sum += this->matrix[i][i];

    return sum;
}