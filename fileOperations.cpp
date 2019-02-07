//
// Created by siddhant on 4/2/19.
//

#include "matrix.hpp"

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