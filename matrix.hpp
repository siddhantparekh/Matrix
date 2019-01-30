#ifndef MATRIX_LIBRARY_HPP
#define MATRIX_LIBRARY_HPP

#include <iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

/**
 * A library to perform operations on matrices.
 * */
class Matrix
{
private:
    /**
     * @var rows is a private data member which contains the number of rows of the matrix.
     * @var cols is a private data member which contains the number of columns of the matrix.
     * */
    ulong rows, cols;

    /**
     * **matrix is a private data member which points to a 2D array which contains the matrix elements.*/
    double **matrix;

public:
    /**
     * Default constructor.
     * Initialises values of rows and cols to 0.
     * */
    Matrix();

    /**
     * Parameterized constructor.
     * @param rows is of the type unsigned long, used to initialise the @var rows.
     * @param cols is of the type unsigned long, used to initialise the @var cols.
     * Memory is allocated to the @var **matrix pointer.*/
    Matrix(ulong rows, ulong cols);

    /** Getter for @var rows.*/
    ulong getRows() const;

    /** Setter for @var rows.*/
    void setRows(ulong rows);

    /** Getter for @var cols.*/
    ulong getCols() const;

    /** Setter for @var cols.*/
    void setCols(ulong cols);
};

#endif