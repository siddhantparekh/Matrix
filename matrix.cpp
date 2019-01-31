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

    //Request to allocate memory
    this->matrix = new double*[this->rows];
    for(ulong i=0; i<this->rows; i++)
        this->matrix[i] = new double[this->cols];
    if(verbose)
        cout<<"Memory allocated.\n";

    //Initialising matrix elements to 0
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

    //Initialising members rows & cols
    this->rows = matrixToBeCopied.rows;
    this->cols = matrixToBeCopied.cols;

    //Request to allocate memory
    this->matrix = new double*[this->rows];
    for(ulong i=0; i<this->rows; i++)
        this->matrix[i] = new double[this->cols];
    if(verbose)
        cout<<"Memory allocated.\n";

    //Copying matrix elements from argument object
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

    //Request to de link memory.
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

ulong Matrix::getCols()
{
    if(verbose)
        cout<<"In getter getCols.\n";

    if(this->exists())
        return cols;
}

bool Matrix::exists()
{
    if(verbose)
        cout<<"In function exists().\n";

    return (this->rows > 0 && this->cols > 0);
}

void Matrix::displayMatrix()
{
    if(verbose)
        cout<<"In function displayMatrix().\n";

    cout<<"Rows : "<<rows<<endl;
    cout<<"Columns : "<<cols<<endl;

    if(this->exists())
    {
        for (ulong i = 0; i < this->rows; i++)
        {
            for (ulong j = 0; j < this->cols; j++)
                cout<<this->matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"Matrix does not exist.\n";
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
                this->matrix[i][j] = random()%100;
    }

    if(verbose)
        cout<<"Random values assigned successfully.\n";

}

void Matrix::readMatrixFromFile(const string &fname)
{
    if(verbose)
        cout<<"In function readMatrixFromFile().\n";

    ifstream infile;
    infile.open(fname);

    ulong rows, cols;

    if(infile)
    {
        infile>>rows>>cols;
        if(this->rows == rows && this->cols == cols)
        {
            for(ulong i=0; i<this->rows; i++)
                for(ulong j=0; j<this->cols; j++)
                    infile>>this->matrix[i][j];
        }
        else
            cout<<"Invalid rows and columns.\n";

        infile.close();
    }
    else
        cout<<"Error opening file.\n";
}

void Matrix::writeMatrixToFile(const string &fname)
{
    if(verbose)
        cout<<"In function writeMatrixToFile().\n";

    ofstream outfile;
    outfile.open(fname);

    if(this->exists())
    {
        if(outfile)
        {
            outfile<<rows<<" "<<cols<<endl;
            for (ulong i = 0; i < this->rows; i++)
            {
                for (ulong j = 0; j < this->cols; j++)
                    outfile<<this->matrix[i][j]<<" ";
                outfile<<endl;
            }
            outfile.close();
        }
        else
            cout<<"Error opening file.\n";
    }
}