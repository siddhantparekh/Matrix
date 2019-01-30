#ifndef MATRIX_LIBRARY_HPP
#define MATRIX_LIBRARY_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/**A boolean variable to toggle the extra couts.*/
static bool verbose=true;

/**
 * @class A library to perform operations on matrices.
*/
class Matrix
{
private:

    /**
     * @var rows is a private data member which contains the number of rows of the matrix.
     * @var cols is a private data member which contains the number of columns of the matrix.
    */
    ulong rows, cols;

    /** **matrix is a private data member which points to a 2D array which contains the matrix elements.*/
    double **matrix;

public:
    /**
     * Default constructor.
     * Initialises values of rows and cols to 0.
    */
    Matrix();

    /**
     * Parameterized constructor.
     * Memory is allocated to the member **matrix pointer.
     * The matrix elements are initialized to 0.
     * @param rows is of the type unsigned long, used to initialise the member rows.
     * @param cols is of the type unsigned long, used to initialise the member cols.
    */
    Matrix(ulong rows, ulong cols);

    /**
     * Copy constructor.
     * The contents of the object received in the argument list are copied to the current objects memory.
     * @param matrixToBeCopied is a reference to another object of the Matrix class.
    */
    Matrix(const Matrix &matrixToBeCopied);

    /** Destructor. */
    virtual ~Matrix();

    /** Getter for @var rows.*/
    ulong getRows();

    /** Setter for @var rows.*/
    void setRows(ulong rows);

    /** Getter for @var cols.*/
    ulong getCols();

    /** Setter for @var cols.*/
    void setCols(ulong cols);

    /** Returns true of matrix exists else false.*/
    bool exists();

    /** Display the matrix.*/
    void displayMatrix();

    /**
     * Overlaoded the operator '=' to assign elements of one matrix to another.
     * @param matrixToBeAssigned is a reference to another object of the Matrix class.
    */
    Matrix operator=(const Matrix &matrixToBeAssigned);

    /** Assigns random values to the matrix if exists.*/
    void generateRandomMatrix();
};

#endif