//
// Created by siddhant on 11/2/19.
//

#include "matrix.hpp"

Matrix Matrix::gaussSeidel() const
{
    if(!this->isDiagonallyDominant())
    {
        cerr<<"Matrix is not a diagonally dominant matrix.\n";
        exit(1);
    }

    Matrix solutionMatrix(this->rows, 1);

    double sum, difference, thershold;

    thershold = 0.0000001;
    difference = 1;

    //Perform Gauss Seidel
    while(difference > thershold)
    {
        //Compute all unknowns in every iteration
        for(ulong i = 0; i < this->rows; ++i)
        {
            sum = 0;
            for(ulong j = 0; j < this->rows; ++j)
                if(i != j)
                    sum += this->matrix[i][j] * solutionMatrix.matrix[j][0];

            difference = solutionMatrix.matrix[0][0];

            solutionMatrix.matrix[i][0] =
                    (this->matrix[i][this->cols - 1] - sum) / this->matrix[i][i];
        
            difference = abs(difference - solutionMatrix[0][0]);
        }
    }

    return solutionMatrix;
}