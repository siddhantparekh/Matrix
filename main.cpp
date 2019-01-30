//
// Created by siddhant on 31/1/19.
//

#include "matrix.hpp"

int main()
{
    Matrix m1;
    ulong rows, cols;

    cout<<"Enter rows and cols : ";
    cin>>rows>>cols;

    m1.setRows(rows);
    m1.setCols(cols);

    m1.generateRandomMatrix();

    m1.displayMatrix();
}