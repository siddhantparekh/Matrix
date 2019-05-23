//
// Created by Siddhant on 31/1/19.
//

#include "matrix.hpp"

int main()
{
    Matrix randomMatrix(3, 3), zero(2, 2);
    randomMatrix.generateRandomMatrix();

    randomMatrix.displayMatrix();
    zero = randomMatrix.find_zero();

    cout<<"Zero : \n";
    zero.displayMatrix();
}