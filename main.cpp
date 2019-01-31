//
// Created by Siddhant on 31/1/19.
//

#include "matrix.hpp"

int main()
{
    Matrix *m1;
    ulong rows, cols;
    string fname;

    // Get rows and cols from the user.
    cout<<"Enter rows and cols : ";
    cin>>rows>>cols;

    // Create an object of type Matrix.
    m1 = new Matrix(rows, cols);

    // To get rid of the character in the buffer.
    getchar();

    // Get the file name from the user.
    cout<<"Enter file name : ";
    getline(cin, fname);

    // Read the file provided by the user.
    m1->readMatrixFromFile(fname);

    m1->displayMatrix();

    return 0;
}