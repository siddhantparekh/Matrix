/** @author Siddhant Parekh*/

#ifndef MATRIX_LIBRARY_HPP
#define MATRIX_LIBRARY_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/**A boolean variable to toggle the extra couts.*/
static bool verbose=true;

/**
 * A library to perform operations on matrices.
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
     * @brief Default constructor.
     * @details Initialises values of rows and cols to 0.
    */
    Matrix();

    /**
     * @brief Parameterized constructor.
     * @details Memory is allocated to the member **matrix pointer.
     * The matrix elements are initialized to 0.
     * @param rows is of the type unsigned long, used to initialise the member rows.
     * @param cols is of the type unsigned long, used to initialise the member cols.
    */
    Matrix(ulong rows, ulong cols);

    /**
     * @brief Copy constructor.
     * @details The contents of the object received in the argument list are copied to the current objects memory.
     * @param matrixToBeCopied is a reference to another object of the Matrix class.
    */
    Matrix(const Matrix &matrixToBeCopied);

    /** @brief Destructor. */
    virtual ~Matrix();

    /** @brief Getter for member rows.*/
    ulong getRows();

    /** @brief Getter for member cols.*/
    ulong getCols();

    /** @brief Returns true if matrix exists else false.*/
    bool exists();

    /** @brief Display the matrix.*/
    void displayMatrix();

    /**
     * @brief Overloaded the operator '=' to assign elements of one matrix to another.
     *
     * @param matrixToBeAssigned is a reference to another object of the Matrix class.
    */
    Matrix operator=(const Matrix &matrixToBeAssigned);

    /** @brief Assigns random values to the matrix if exists.*/
    void generateRandomMatrix();

    /**
     * @brief Reads a matrix from a file.
     *
     * @param fname contains the file name from which the matrix is to be read.
    */
    void readMatrixFromFile(const string &fname);

    /**
     * @brief Writes the matrix to the file.
     *
     * @param fname contains the file name to which the matrix is to be written.
    */
    void writeMatrixToFile(const string &fname);
};

#endif