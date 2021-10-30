#ifndef TETRIS_MINOS
#define TETRIS_MINOS

#include <vector>

using MatrixOfBool = std::vector<std::vector<bool>>;


class TetrisMinos
{
    MatrixOfBool matrix;
    MatrixOfBool matrixBeforeRotate;
    unsigned int numOfRotations = 0;
    unsigned int numMaxOfRotations;
public:
    TetrisMinos (const MatrixOfBool &matrix, unsigned int numMaxOfRotations);
    const MatrixOfBool &getMatrix();
    void doRotation();
    void rotation();
    void revertRotation();
};

#endif //TETRIS_MINOS
