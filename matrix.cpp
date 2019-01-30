#include "matrix.hpp"

Matrix::Matrix()
{
    if(verbose)
        cout<<"In default constructor.\n";

    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(ulong rows, ulong cols) : rows(rows), cols(cols)
{
    if(verbose)
        cout<<"In parameterised constructor.\n";

    this->matrix = new double*[this->rows];
    for(ulong i=0; i<this->rows; i++)
        this->matrix[i] = new double[this->cols];
    if(verbose)
        cout<<"Memory allocated.\n";

    for(ulong i=0; i<this->rows; i++)
        for(ulong j=0; j<this->cols; j++)
            this->matrix[i][j] = 0;
    if(verbose)
        cout<<"Values initialised to 0.\n";
}

Matrix::Matrix(const Matrix &matrixToBeCopied)
{
    if(verbose)
        cout<<"In copy constructor.\n";

    this->rows = matrixToBeCopied.rows;
    this->cols = matrixToBeCopied.cols;

    this->matrix = new double*[this->rows];
    for(ulong i=0; i<this->rows; i++)
        this->matrix[i] = new double[this->cols];
    if(verbose)
        cout<<"Memory allocated.\n";

    for(ulong i=0; i<this->rows; i++)
        for(ulong j=0; j<this->cols; j++)
            this->matrix[i][j] = matrixToBeCopied.matrix[i][j];
    if(verbose)
        cout<<"Values copied.\n";
}

Matrix::~Matrix()
{
    if(verbose)
        cout<<"In destructor.\n";

    if(this->exists())
    {
        for (ulong i = 0; i < this->rows; i++)
            delete[]this->matrix[i];
        delete[]this->matrix;
    }

    if(verbose)
        cout<<"Matrix de linked successfully.\n";

}

ulong Matrix::getRows()
{
    if(verbose)
        cout<<"In getter getRows.\n";

    if(this->exists())
        return rows;
}

void Matrix::setRows(ulong rows)
{
    if(verbose)
        cout<<"In setter setRows.\n";

    if(this->exists())
        this->rows = rows;
}

ulong Matrix::getCols()
{
    if(verbose)
        cout<<"In getter getCols.\n";

    if(this->exists())
        return cols;
}

void Matrix::setCols(ulong cols)
{
    if(verbose)
        cout<<"In setter setCols.\n";

    if(this->exists())
        this->cols = cols;
}

bool Matrix::exists()
{
    if(verbose)
        cout<<"In function exists().\n";
    return !(rows < 1 || cols < 1);
}

void Matrix::displayMatrix()
{
    if(verbose)
        cout<<"In function display().\n";

    if(this->exists())
    {
        for (ulong i = 0; i < this->rows; i++)
        {
            for (ulong j = 0; j < this->cols; j++)
                cout << this->matrix[i][j] << " ";
            cout << endl;
        }
    }
}

Matrix Matrix::operator=(const Matrix &matrixToBeAssigned)
{
    if(verbose)
        cout<<"Operator '=' overloaded.\n";

    if(this->exists())
    {
        for (ulong i = 0; i < this->rows; i++)
            for (ulong j = 0; j < this->cols; j++)
                this->matrix[i][j] = matrixToBeAssigned.matrix[i][j];
    }

    if(verbose)
        cout<<"Values assigned successfully.\n";

    return(*this);
}

void Matrix::generateRandomMatrix()
{
    if(verbose)
        cout<<"In function generateRandomMatrix().\n";

    if(this->exists())
    {
        for (ulong i = 0; i < this->rows; i++)
            for (ulong j = 0; j < this->cols; j++)
                this->matrix[i][j] = random() % 100;
    }

    if(verbose)
        cout<<"Random values assigned successfully.\n";

}