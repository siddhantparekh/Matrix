#include "matrix.hpp"

//Private functions
void Matrix::setDimensions(ulong rows, ulong cols)
{
    CONDITIONAL_PRINT<<"In function setDimensions().\n";

    this->rows = rows;
    this->cols = cols;

    allocateMemory();
}

void Matrix::allocateMemory()
{
    CONDITIONAL_PRINT<<"In function allocateMemory().\n";

    this->matrix = new double*[this->rows];
    for(ulong i=0; i < this->rows; i++)
        this->matrix[i] = new double[this->cols];

    CONDITIONAL_PRINT<<"Memory allocated.\n";
}

void Matrix::deallocateMemory()
{
    CONDITIONAL_PRINT<<"In function deallocateMemory().\n";

    for(ulong i = 0; i < this->rows; i++)
        delete[]this->matrix[i];
    delete[]this->matrix;

    CONDITIONAL_PRINT<<"Memory de linked successfully.\n";
}

//Public functions
Matrix::Matrix()
{
    CONDITIONAL_PRINT<<"In default constructor.\n";

    this->rows = 0;
    this->cols = 0;

}

Matrix::Matrix(ulong rows, ulong cols) : rows(rows), cols(cols)
{
    CONDITIONAL_PRINT<<"In parameterised constructor.\n";

    allocateMemory();

    //Initialising matrix elements to 0
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            this->matrix[i][j] = 0;

    CONDITIONAL_PRINT<<"Values initialised to 0.\n";
}

Matrix::Matrix(const Matrix &matrixToBeCopied)
{
    CONDITIONAL_PRINT<<"In copy constructor.\n";

    this->rows = matrixToBeCopied.rows;
    this->cols = matrixToBeCopied.cols;

    allocateMemory();

    //Copying matrix elements from argument object.
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            this->matrix[i][j] = matrixToBeCopied.matrix[i][j];

    CONDITIONAL_PRINT<<"Values copied.\n";
}

Matrix::~Matrix()
{
    CONDITIONAL_PRINT<<"In destructor.\n";

    deallocateMemory();

    CONDITIONAL_PRINT<<"Matrix de linked successfully.\n";
}

ulong Matrix::getRows()
{
    CONDITIONAL_PRINT<<"In getter getRows.\n";

    return rows;
}

ulong Matrix::getCols()
{
    CONDITIONAL_PRINT<<"In getter getCols.\n";

    return cols;
}

bool Matrix::exists()
{
    CONDITIONAL_PRINT<<"In function exists().\n";

    return rows > 0 && cols > 0;
}

void Matrix::displayMatrix()
{
    CONDITIONAL_PRINT<<"In function displayMatrix().\n";

    cout<<"Matrix("<<this->rows<<", "<<this->cols<<")\n";

    if(!this->exists())
    {
        cout<<"Matrix does not exist.\n";
        exit(1);
    }

    for(ulong i = 0; i < this->rows; i++)
    {
        for(ulong j = 0; j < this->cols; j++)
        {
            cout<<this->matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

void Matrix::generateRandomMatrix()
{
    CONDITIONAL_PRINT<<"In function generateRandomMatrix().\n";
    if(!this->exists())
    {
        cout<<"Matrix does not exist.\n";
        exit(1);
    }

    //Assigning random values to the matrix elements.
    for(ulong i = 0; i < this->rows; i++)
        for(ulong j = 0; j < this->cols; j++)
            this->matrix[i][j] = random()%100;
    CONDITIONAL_PRINT<<"Random values assigned successfully.\n";
}
