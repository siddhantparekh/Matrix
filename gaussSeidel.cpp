//
// Created by siddhant on 11/2/19.
//

#include "matrix.hpp"

Matrix Matrix::gaussSeidel() const
{
    Matrix temporaryMatrix(*this), solutionMatrix(this->rows, 1);

    double sum;

    //Perform Gauss Seidel
    for(ulong k = 0; k < 10; ++k)
    {
        //Compute all unknowns in every iteration
        for(ulong i = 0; i < temporaryMatrix.rows; ++i)
        {
            sum = 0;
            for(ulong j = 0; j < temporaryMatrix.rows; ++j)
                if(i != j)
                    sum += temporaryMatrix.matrix[i][j] * solutionMatrix.matrix[j][0];

            solutionMatrix.matrix[i][0] =
                    (temporaryMatrix.matrix[i][temporaryMatrix.cols - 1] - sum) / temporaryMatrix.matrix[i][i];
        }

    }

    return solutionMatrix;
}