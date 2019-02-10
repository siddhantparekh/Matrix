//
// Created by siddhant on 2/9/19.
//

#include "matrix.hpp"

Matrix Matrix::gaussianElimination() const
{
    CONDITIONAL_PRINT<<"In function gaussianElimination().\n";

    if(this->rows != this->cols-1)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    Matrix temporaryMatrix(*this);

    ulong i=0;
    //Perform gaussian elimination
    while(i < temporaryMatrix.rows)
    {
        if(temporaryMatrix.matrix[i][i] == 0)
        {
            temporaryMatrix.pivotMatrix(i);
            i = 0;
            continue;
        }

        //Row multiplied with a scalar.
        for(ulong j=i+1; j < temporaryMatrix.cols; ++j)
        {
            temporaryMatrix.matrix[i][j] /= temporaryMatrix.matrix[i][i];

            //Row(k) - Row(i)*element[k][i]
            for(ulong k=i+1; k < temporaryMatrix.rows; ++k)
                temporaryMatrix.matrix[k][j] -= temporaryMatrix.matrix[i][j]*temporaryMatrix.matrix[k][i];
        }

        temporaryMatrix.matrix[i][i] = 1;

        //Making coefficients 0
        for(ulong j=i+1; j < temporaryMatrix.rows; j++)
            temporaryMatrix.matrix[j][i] = 0;

        ++i;
    }

    return temporaryMatrix.backSubstitution();
}