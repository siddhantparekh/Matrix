//
// Created by Siddhant on 31/1/19.
//

#include "matrix.hpp"

int main()
{
    string fname;
    ulong rows, cols;

    cout<<"Enter dimensions of A : ";
    cin>>rows>>cols;

    Matrix A(rows, cols), X(cols, 1), B(cols, 1);

    cout<<"File name to read A from : ";
    cin>>fname;

    A.readMatrixFromFile(fname);

    cout<<"File name to read B from : ";
    cin>>fname;

    B.readMatrixFromFile(fname);

    X.solveSystemOfEquations(A, B);

    X.displayMatrix();
}