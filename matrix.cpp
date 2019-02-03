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

    cout<<"Rows : "<<rows<<endl;
    cout<<"Columns : "<<cols<<endl;

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

void Matrix::readMatrixFromFile(const string &fname)
{
    CONDITIONAL_PRINT<<"In function readMatrixFromFile().\n";

    ifstream infile;
    infile.open(fname);

    ulong rows, cols;

    if(infile)
    {
        infile>>rows>>cols;

        if(this->rows == rows && this->cols == cols)
        {
            //Assign values from file to matrix elements.
            for(ulong i = 0; i < this->rows; i++)
                for(ulong j = 0; j < this->cols; j++)
                    infile>>this->matrix[i][j];
        }
        else
        {
            cout<<"Invalid operation.\n";
            exit(2);
        }

        infile.close();
    }
    else
    {
        cout<<"Error opening file.\n";
        exit(3);
    }
}

void Matrix::writeMatrixToFile(const string &fname)
{
    CONDITIONAL_PRINT<<"In function writeMatrixToFile().\n";

    ofstream outfile;
    outfile.open(fname);

    if(this->exists())
    {
        if(outfile)
        {
            outfile<<rows<<" "<<cols<<endl;

            //Write the matrix to the file.
            for(ulong i = 0; i < this->rows; i++)
            {
                for(ulong j = 0; j < this->cols; j++)
                    outfile<<this->matrix[i][j]<<" ";
                outfile<<endl;
            }

            outfile.close();
        }
        else
        {
            cout<<"Error opening file.\n";
            exit(3);
        }
    }
    else
    {
        cout<<"Matrix does not exist.\n";
        exit(1);
    }
}

Matrix Matrix::operator=(const Matrix &matrixToBeAssigned)
{
    CONDITIONAL_PRINT<<"In function operator=().\n";

    if(this->exists())
        this->deallocateMemory();

    this->setDimensions(matrixToBeAssigned.rows, matrixToBeAssigned.cols);

    //Assign the elements from one matrix to another.
    for(ulong i = 0; i < this->rows; i++)
        for(ulong j = 0; j < this->cols; j++)
            this->matrix[i][j] = matrixToBeAssigned.matrix[i][j];

    CONDITIONAL_PRINT<<"Values assigned successfully.\n";

    //By convention return *this.
    return(*this);

}

Matrix Matrix::operator+(const Matrix &matrixToBeAdded)
{
    CONDITIONAL_PRINT<<"In function operator+().\n";

    if(this->rows != matrixToBeAdded.rows || this->cols != matrixToBeAdded.cols)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    Matrix sum(this->rows, this->cols);

    //Add the elements of the two matrices.
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            sum.matrix[i][j] = this->matrix[i][j] + matrixToBeAdded.matrix[i][j];

    return sum;
}

Matrix Matrix::operator-(const Matrix &matrixToBeSubtracted)
{
    CONDITIONAL_PRINT<<"In function operator-().\n";

    if(this->rows != matrixToBeSubtracted.rows || this->cols != matrixToBeSubtracted.cols)
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    Matrix difference(this->rows, this->cols);

    //Subtract the elements of one matrix from another.
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            difference.matrix[i][j] = this->matrix[i][j] - matrixToBeSubtracted.matrix[i][j];

    return difference;
}

Matrix Matrix::operator*(double scalar)
{
    CONDITIONAL_PRINT<<"In function operator*(scalar). Multiplication by a scalar.\n";

    Matrix product(this->rows, this->cols);

    //Multiply the elements of the matrix with the scalar.
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            product.matrix[i][j] = this->matrix[i][j] * scalar;

    return product;
}

Matrix Matrix::operator*(const Matrix &matrixToBeMultiplied)
{
    CONDITIONAL_PRINT<<"In function operator*(matrix). Multiplication by another matrix.\n";

    if(this->cols == matrixToBeMultiplied.rows)
    {
        Matrix product(this->rows, matrixToBeMultiplied.cols);

        //Multiply the elements of each row of matrix 1 and column of matrix 2 and sum them.
        for(ulong i=0; i < this->rows; i++)
            for(ulong j=0; j < matrixToBeMultiplied.cols; j++)
                for(ulong k=0; k < matrixToBeMultiplied.rows; k++)
                    product.matrix[i][j] += this->matrix[i][k] * matrixToBeMultiplied.matrix[k][j];

        return product;
    }
    else
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }
}

bool Matrix::isSquareMatrix()
{
    CONDITIONAL_PRINT<<"In function isSquareMatrix().\n";

    return this->rows==this->cols;
}

bool Matrix::isIdentityMatrix()
{
    CONDITIONAL_PRINT<<"In function isIdentityMatrix().\n";

    if(!this->isSquareMatrix())
        return false;

    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
        {
            //check whether the diagonal elements are one
            if(i==j && this->matrix[i][j]!=1)
                return false;

            //check whether the non-diagonal elements are zero
            else if(i!=j && this->matrix[i][j]!=0)
                return false;
        }

    return true;
}

bool Matrix::isSymmetricMatrix()
{
    CONDITIONAL_PRINT<<"In function isSymmetricMatrix().\n";

    if(!this->isSquareMatrix())
        return false;

    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < i; j++)
        {
            //check whether the mirror elements are equal.
            if(this->matrix[i][j] != this->matrix[j][i])
                return false;
        }

    return true;
}

bool Matrix::isNullMatrix()
{
    CONDITIONAL_PRINT<<"In function isNullMatrix().\n";

    //check whether all the elements are zero.
    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            if(matrix[i][j] != 0)
                return false;

    return true;
}

bool Matrix::isDiagonalMatrix()
{
    CONDITIONAL_PRINT<<"In function isIdentityMatrix().\n";

    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
        {
            //check whether the diagonal elements are non-zero.
            if(i==j && this->matrix[i][j]==0)
                return false;

                //check whether the non-diagonal elements are zero.
            else if(i!=j && this->matrix[i][j]!=0)
                return false;
        }

    return true;
}

bool Matrix::isDiagonallyDominant()
{
    CONDITIONAL_PRINT<<"In function isDiagonallyDominant().\n";

    double sum;

    //sum the non-diagonal elements in every row and check whether it is less than the diagonal element of that row.
    for(ulong i=0; i < this->rows; i++)
    {
        sum = 0;
        for(ulong j = 0; j < this->cols; j++)
            if(i!=j)
                sum += abs(this->matrix[i][j]);
        if(sum >= abs(this->matrix[i][i]))
            return false;
    }

    return true;
}

Matrix Matrix::transpose()
{
    CONDITIONAL_PRINT<<"In function transpose().\n";

    Matrix transposedMatrix(this->cols, this->rows);

    for(ulong i=0; i < this->rows; i++)
        for(ulong j=0; j < this->cols; j++)
            transposedMatrix.matrix[j][i] = this->matrix[i][j];

    return transposedMatrix;
}

void Matrix::pivotMatrix(ulong rowToBeInterchanged)
{
    cout<<"In Function pivotMatrix().\n";

    ulong i = rowToBeInterchanged + 1;

    //Search for a row with non-zero diagonal element.
    while(i < this->rows && this->matrix[i][rowToBeInterchanged]==0)
        i++;

    if(i == this->rows)
    {
        cout<<"Cannot pivot.\n";
        exit(4);
    }

    double temp;

    //Interchange the rowToBeInterchanged with the row found.
    for(ulong j=0; j < this->cols; j++)
    {
        temp = this->matrix[i][j];
        this->matrix[i][j] = this->matrix[rowToBeInterchanged][j];
        this->matrix[rowToBeInterchanged][j] = temp;
    }
}

Matrix Matrix::triangularFactorizationCrouts(Matrix &B)
{
    CONDITIONAL_PRINT<<"In function triangularFactorizationCrouts().\n";

    if(!this->isSquareMatrix())
    {
        cout<<"Invalid operation.\n";
        exit(2);
    }

    //Create a temporary matrix object so that if pivoting occurs, the original matrix won't be changed.
    Matrix temporaryMatrix(*this);

    Matrix triangularMatrices(temporaryMatrix.rows, temporaryMatrix.cols);

    bool flag;
    double sum;

    //Calculates the Upper and Lower Triangular matrices.
    for(ulong i=0; i < temporaryMatrix.rows; i++)
    {
        flag = true;
        for(ulong j=i; j < temporaryMatrix.cols; j++)
        {
            sum = 0;

            //if flag is true the elements of the upper triangular matrix are computed.
            if(flag)
            {
                for(ulong k = 0; k < i; k++)
                    sum += triangularMatrices.matrix[j][k] * triangularMatrices.matrix[k][i];
                triangularMatrices.matrix[j][i] = temporaryMatrix.matrix[j][i] - sum;

                //Pivot matrices if required and start again
                if(i == j && triangularMatrices.matrix[i][j] == 0)
                {
                    temporaryMatrix.pivotMatrix(i);
                    B.pivotMatrix(i);
                    i = -1;
                    break;
                }

                if(j == temporaryMatrix.cols - 1)
                {
                    j = i;
                    flag = false;
                }
            }
            //else the elements of the lower triangular matrix are computed.
            else
            {
                for(ulong k = 0; k < i; k++)
                    sum += triangularMatrices.matrix[i][k] * triangularMatrices.matrix[k][j];
                triangularMatrices.matrix[i][j] = (temporaryMatrix.matrix[i][j] - sum) / triangularMatrices.matrix[i][i];
            }
        }
    }

    return triangularMatrices;
}

void Matrix::solveSystemOfEquations(Matrix &A, Matrix &B)
{
    CONDITIONAL_PRINT<<"In function solveSystemOfEquations().\n";

    Matrix triangularMatrices = A.triangularFactorizationCrouts(B);

    cout<<"Triangular matrix : \n";
    triangularMatrices.displayMatrix();

    Matrix Z(this->rows, 1);

    double sum;

    //Compute Z
    for(ulong i=0; i < this->rows; i++)
    {
        sum = 0;
        for(ulong j=0; j < i; j++)
            sum += triangularMatrices.matrix[i][j] * Z.matrix[j][0];

        Z.matrix[i][0] = (B.matrix[i][0] - sum) / triangularMatrices.matrix[i][i];
    }

    cout<<"Z : \n";
    Z.displayMatrix();

    //Compute X
    for(ulong i=this->rows; i > 0; i--)
    {
        sum = 0;
        for(ulong j=this->rows; j > i; j--)
        {
            sum += triangularMatrices.matrix[i-1][j-1] * this->matrix[j-1][0];
        }

        this->matrix[i-1][0] = Z.matrix[i-1][0] - sum;
    }
}