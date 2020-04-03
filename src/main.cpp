#include "matrix.hpp"

/**
 * @brief Computes (Zj-Cj)
 * @return min value index + 1
 */
ulong getMinCol(Matrix &coefficients, Matrix &A, Matrix &B, Matrix &Z)
{
    ulong minCol=0, tempIndex;

    //Find min col Z
    for(ulong i=0; i < Z.getCols(); ++i)
    {
        Z[0][i] = 0;
        for(ulong j=0; j < A.getRows(); ++j)
        {
            //Matrix is of type double
            tempIndex = B[j][0] - 1;
            Z[0][i] += coefficients[0][tempIndex] * A[j][i+1];
        }
        Z[0][i] -= coefficients[0][i];

        if(Z[0][i] < Z[0][minCol])
            minCol = i;
    }

    //indices of A are (Z.cols + 1)
    return minCol+1;
}

/**
 * @brief computes the ratios if divisor non-zero
 * @return min ratio index
 */
ulong getMinRow(Matrix &coefficients, Matrix &A, Matrix &B, Matrix &ratio, ulong minCol)
{
    ulong minRow = 0;

    for(ulong i=0; i < A.getRows(); ++i)
    {
        //avoid division by 0
        if(A[i][minCol] <= 0)
        {
            if(minRow == i)
                ++minRow;
            continue;
        }

        ratio[i][0] = A[i][0]/A[i][minCol];
        if(ratio[i][0] < ratio[minRow][0])
            minRow = i;
    }

    return minRow;
}

void simplex(Matrix &coefficients, Matrix &A, Matrix &B)
{
    Matrix Z(1, coefficients.getCols());
    Matrix ratio(B.getRows(), 1);

    ulong minCol=0, minRow, tempIndex;
    double pivotElement, tempElement;

    //Get min column using Z
    minCol = getMinCol(coefficients, A, B, Z);

    while(Z[0][minCol-1] < 0)
    {
        //find min row using ratio
        minRow = getMinRow(coefficients, A, B, ratio, minCol);

        cout<<minRow<<", "<<minCol<<endl;

        //Update B
        B[minRow][0] = minCol;

        getchar();getchar();

        //Make pivot element i.e. A[minRow][minCol] = 1
        pivotElement = A[minRow][minCol];
        for(ulong i=0; i < A.getCols(); ++i)
            A[minRow][i] /= pivotElement;

        //Gaussian elimination like thing
        for(ulong i=0; i < A.getRows(); ++i)
        {
            if(i == minRow)
                continue;
            tempElement = A[i][minCol];
            for(ulong j=0; j < A.getCols(); ++j)
            {
                A[i][j] -= (tempElement * A[minRow][j]);
            }
        }

        minCol = getMinCol(coefficients, A, B, Z);
    }
}

int main()
{
    int numberOfVariables, numberOfConstraints;

    cout<<"Enter no. of variables : ";
    cin>>numberOfVariables;

    cout<<"Enter no. of constraints : ";
    cin>>numberOfConstraints;

    //Create matrices
    Matrix coefficients(1, numberOfVariables);
    Matrix B(numberOfConstraints, 1);
    Matrix A(numberOfConstraints, numberOfVariables+1);

    //Get matrices
    coefficients.readMatrixFromFile("/home/siddhant/inputs/02C");
    A.readMatrixFromFile("/home/siddhant/inputs/02A");
    B.readMatrixFromFile("/home/siddhant/inputs/02B");

    /*
    cout<<"Coefficients : \n";
    coefficients.displayMatrix();
    cout<<"A : \n";
    A.displayMatrix();
    cout<<"B : \n";
    B.displayMatrix();
    */

    simplex(coefficients, A, B);

    ulong tempIndex;
    double solution = 0;
    for(ulong i=0; i < A.getRows(); ++i)
    {
        tempIndex = B[i][0] - 1;
        solution += (A[i][0] * coefficients[0][tempIndex]);
    }

    cout<<"Solution = "<<solution<<endl;
}