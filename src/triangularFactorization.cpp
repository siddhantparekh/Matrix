//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

Matrix Matrix::triangularFactorizationCrouts()
{
    CONDITIONAL_PRINT<<"In function triangularFactorizationCrouts().\n";

    if(this->rows != this->cols-1)
    {
        cerr<<"Invalid operation.\n";
        exit(2);
    }

    Matrix triangularMatrices(this->rows, this->cols);

    bool flag;
    double sum;

    //Calculates the Upper and Lower Triangular matrices.
    ulong i=0;
    while(i < this->rows)
    {
        flag = true;
        for(ulong j=i; j < this->rows; ++j)
        {
            sum = 0;

            //if flag is true the elements of the lower triangular matrix are computed.
            if(flag)
            {
                for(ulong k = 0; k < i; ++k)
                    sum += triangularMatrices.matrix[j][k] * triangularMatrices.matrix[k][i];
                triangularMatrices.matrix[j][i] = this->matrix[j][i] - sum;

                //Pivot matrices if required and start again
                if(i == j && triangularMatrices.matrix[i][j] == 0)
                {
                    this->pivotMatrix(i);
                    i = 0;
                    break;
                }

                if(j == this->cols - 2)
                {
                    j = i;
                    flag = false;
                }
            }
            //else the elements of the upper triangular matrix are computed.
            else
            {
                for(ulong k = 0; k < i; ++k)
                    sum += triangularMatrices.matrix[i][k] * triangularMatrices.matrix[k][j];
                triangularMatrices.matrix[i][j] = (this->matrix[i][j] - sum) / triangularMatrices.matrix[i][i];
            }
        }
        ++i;
    }

    return triangularMatrices;
}