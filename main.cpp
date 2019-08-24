#include "matrix.hpp"

void simplex(Matrix &coefficients, Matrix &A, Matrix &B)
{
    Matrix Z(1, coefficients.getCols()-1);
    Matrix ratio(B.getRows(), 1);

    int tempIndex, count=2;
    ulong minCol=0, minRow;
    double pivotElement, tempElement;

    cout<<"Working 1\n";
    //Find min col Z
    for(ulong i=0; i < Z.getCols(); ++i)
    {
        Z[0][i] = 0;
        cout<<"Working "<<count++<<endl;
        for(ulong j=0; j < A.getRows(); ++j)
        {
            //Matrix is of type double
            tempIndex = B[j][0] - 1;
            cout<<tempIndex<<endl;
            Z[0][i] += coefficients[0][tempIndex] * A[i+1][j];
        }
        Z[0][i] -= coefficients[0][i+1];

        if(Z[0][i] < Z[0][minCol])
            minCol = i;
    }

    //indices of A are (Z.cols + 1)
    ++minCol;

    while(Z[0][minCol] < 0)
    {
        //find min row using ratio
        minRow = 0;
        for(ulong i=0; i < A.getRows(); ++i)
        {
            //avoid division by 0
            if(A[i][minCol] == 0)
            {
                if(minRow == i)
                    ++i;
                continue;
            }

            ratio[i][0] = A[i][0]/A[i][minCol];
            if(ratio[i][0] < ratio[minRow][0])
                minRow = i;
        }

        //Update B
        B[0][minRow] = minCol;

        //Make pivot element i.e. A[minRow][minCol] = 1
        pivotElement = A[minRow][minCol];
        for(ulong i=0; i < A.getCols(); ++i)
            A[minRow][i] /= pivotElement;

        //Gaussian elimination like thing
        for(ulong i=0; i < A.getRows() && i != minRow; ++i)
        {
            tempElement = A[i][minCol];
            for(ulong j=0; j < A.getCols(); ++j)
            {
                A[i][j] -= (tempElement * A[minRow][j]);
            }
        }

        //Find min col Z
        for(ulong i=0; i < Z.getCols(); ++i)
        {
            Z[0][i] = 0;
            for(ulong j=0; j < A.getRows(); ++j)
            {
                //Matrix is of type double
                tempIndex = B[j][0] - 1;
                Z[0][i] += coefficients[0][tempIndex] * A[i+1][j];
            }
            Z[0][i] -= coefficients[0][i+1];

            if(Z[0][i] < Z[0][minCol])
                minCol = i;
        }

        //indices of A are (Z.cols + 1)
        ++minCol;

        cout<<"Coefficients : \n";
        coefficients.displayMatrix();
        cout<<"A : \n";
        A.displayMatrix();
        cout<<"B : \n";
        B.displayMatrix();

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
    coefficients.readMatrixFromFile("/home/siddhant/inputs/01C");
    A.readMatrixFromFile("/home/siddhant/inputs/01A");
    B.readMatrixFromFile("/home/siddhant/inputs/01B");

    /*
    cout<<"Coefficients : \n";
    coefficients.displayMatrix();
    cout<<"A : \n";
    A.displayMatrix();
    cout<<"B : \n";
    B.displayMatrix();
    */

    simplex(coefficients, A, B);
}