#include "matrix.hpp"

Matrix::Matrix()
{
    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(ulong rows, ulong cols) : rows(rows), cols(cols)
{
    this->matrix = new double*[this->rows];
    for(ulong i=0; i<this->rows; i++)
        this->matrix[i] = new double[this->cols];
}

ulong Matrix::getRows() const
{
    return rows;
}

void Matrix::setRows(ulong rows)
{
    this->rows = rows;
}

ulong Matrix::getCols() const
{
    return cols;
}

void Matrix::setCols(ulong cols)
{
    this->cols = cols;
}
