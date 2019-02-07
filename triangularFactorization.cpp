//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

Matrix Matrix::triangularFactorizationCrouts() const
{
    CONDITIONAL_PRINT<<"In function triangularFactorizationCrouts().\n";

    if(this->rows != this->cols-1)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    //Create a temporary matrix object so that if pivoting occurs, the original matrix won't be changed.
    Matrix temporaryMatrix(*this);

    Matrix triangularMatrices(temporaryMatrix.rows, temporaryMatrix.cols);

    bool flag;
    double sum;

    //Calculates the Upper and Lower Triangular matrices.
    again:
    for(ulong i=0; i < temporaryMatrix.rows; i++)
    {
        flag = true;
        for(ulong j=i; j < temporaryMatrix.rows; j++)
        {
            sum = 0;

            //if flag is true the elements of the upper triangular matrix are computed.
            if(flag)
            {
                for(ulong k = 0; k < i; k++)
                    sum += triangularMatrices.matrix[j][k] * triangularMatrices.matrix[k][i];
                triangularMatrices.matrix[j][i] = temporaryMatrix.matrix[j][i] - sum;

                //Pivot matrices if required and start again
                if(i == j && triangularMatrices.matrix[i][j] == 0)
                {
                    temporaryMatrix.pivotMatrix(i);
                    goto again;
                }

                if(j == temporaryMatrix.cols - 1)
                {
                    j = i;
                    flag = false;
                }
            }
            //else the elements of the lower triangular matrix are computed.
            else
            {
                for(ulong k = 0; k < i; k++)
                    sum += triangularMatrices.matrix[i][k] * triangularMatrices.matrix[k][j];
                triangularMatrices.matrix[i][j] = (temporaryMatrix.matrix[i][j] - sum) / triangularMatrices.matrix[i][i];
            }
        }
    }

    return triangularMatrices;
}