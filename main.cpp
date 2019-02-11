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
    //A_B.displayMatrix();

    cout<<"Enter fname for gaussian : ";
    getline(cin, fname);
    //Solve using Gaussian
    X = A_B.gaussianElimination();
    cout<<"By Gaussian Elimination\n";
    X.writeMatrixToFile(fname);

    cout<<"Enter fname for LU : ";
    getline(cin, fname);
    //Solve using LU
    X = A_B.solveTriangularMatrix();
    cout<<"By triangular factorization\n";
    X.writeMatrixToFile(fname);

    /*
    //Solve using Gauss Jacobi
    X = A_B.gaussSeidel();
    cout<<"By Gauss Seidel\n";
    X.displayMatrix();
    */
}