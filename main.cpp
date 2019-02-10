//
// Created by Siddhant on 31/1/19.
//

#include "matrix.hpp"

int main()
{
    string fname;
    ulong rows, cols;

    cout<<"Enter dimensions of coefficient matrix : ";
    cin>>rows>>cols;

    Matrix A(rows, cols), X(cols, 1), B(cols, 1);

    getchar();

    cout<<"Enter fname for A : ";
    getline(cin, fname);
    A.readMatrixFromFile(fname), A.displayMatrix();

    cout<<"Enter fname for B : ";
    getline(cin, fname);
    B.readMatrixFromFile(fname), B.displayMatrix();

    Matrix A_B = augmentMatrices(A, B);
    A_B.displayMatrix();

    //Solve using Gaussian
    X = A_B.gaussianElimination();
    cout<<"By Gaussian Elimination\n";
    X.displayMatrix();

    //Solve using LU
    X = A_B.solveTriangularMatrix();
    cout<<"By triangular factorization\n";
    X.displayMatrix();
}