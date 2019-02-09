//
// Created by siddhant on 2/9/19.
//

#include "matrix.hpp"

Matrix Matrix::gaussianElimination() const
{
    if(this->rows != this->cols-1)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    Matrix temporaryMatrix(*this);

    
}