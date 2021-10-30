#include "tetris-minos.h"
#include "tetris-header.h"


TetrisMinos::TetrisMinos(const MatrixOfBool &matrix, unsigned int numMaxOfRotations)
    : matrix (matrix), numMaxOfRotations (numMaxOfRotations)
{

}

const MatrixOfBool &TetrisMinos::getMatrix()
{
    return this->matrix;
}

void TetrisMinos::doRotation()
{
    MatrixOfBool newMatrix = this->matrix;
    unsigned int newColMatrix = 0;
    for (int row = this->matrix.size() - 1; row >= 0; --row)
    {
        for (int col = 0; col < this->matrix[row].size(); ++col)
        {
            newMatrix[col][newColMatrix] = this->matrix[row][col];
        }
        ++newColMatrix;
    }
    this->matrix = newMatrix;
}

void TetrisMinos::rotation()
{
    this->matrixBeforeRotate = this->matrix;
    if (this->numOfRotations < this->numMaxOfRotations)
    {
        this->doRotation();
        ++this->numOfRotations;
    }
    else
    {
        do
        {
            this->doRotation();
            ++this->numOfRotations;
        }while (this->numOfRotations < TetrisVars::maxNumberOfTetrisRotation);
        this->numOfRotations = 0;
    }
}

void TetrisMinos::revertRotation()
{
    this->matrix = this->matrixBeforeRotate;
}
