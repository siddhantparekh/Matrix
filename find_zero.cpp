//
// Created by siddhant on 21/5/19.
//

#include "matrix.hpp"

ulong factorial(ulong n)
{
    ulong factorial = 1;
    for(ulong i=2; i <= n; ++i)
        factorial *= i;

    return factorial;
}

Matrix Matrix::find_zero() const
{
    if(this->rows != this->cols)
    {
        cerr<<"Matrix is not a square matrix.\n";
        exit(1);
    }

    ulong count = 0, number_of_combinations = factorial(this->rows)/(factorial(this->rows - 2) * 2);
    ulong combinations[number_of_combinations][4];
    Matrix result(2, 2);

    for(ulong i1=0; i1 < this->rows; ++i1)
        for(ulong j1=0; j1 < this->rows; ++j1)
            for(ulong i2=0; i2 < this->rows; ++i2)
                for(ulong j2=0; j2 < this->rows; ++j2)
                    if(i1 != i2 && j1 != j2)
                    {
                        cout<<"("<<i1+1<<", "<<j1+1<<") : ("<<i2+1<<", "<<j2+1<<")"<<endl;
                        combinations[count][0] = i1;
                        combinations[count][1] = j1;
                        combinations[count][2] = i2;
                        combinations[count][3] = j2;
                        ++count;
                        getchar();getchar();
                    }

    if(count == number_of_combinations)
        cout<<"True.\n";

    ulong row1, col1, row2, col2;
    for(ulong i=0; i < number_of_combinations; ++i)
    {
        col1 = combinations[i][0];
        row1 = combinations[i][1];
        col2 = combinations[i][2];
        row2 = combinations[i][3];

        if(this->matrix[row1][col1]*this->matrix[row1][col2] -
                this->matrix[row2][col1]*this->matrix[row2][col2] == 0)
        {
            result.matrix[0][0] = row1;
            result.matrix[0][1] = col1;
            result.matrix[1][0] = row2;
            result.matrix[1][1] = col2;

            return result;
        }
    }

    result.matrix[0][0] = -1;
    result.matrix[0][1] = -1;
    result.matrix[1][0] = -1;
    result.matrix[1][1] = -1;

    return result;
}