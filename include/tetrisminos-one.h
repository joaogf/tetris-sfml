#ifndef TETRIS_MINOS_ONE
#define TETRIS_MINOS_ONE

#include "tetris-minos.h"


class TetrisMinosOne : public TetrisMinos
{

public:
    TetrisMinosOne ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, false, false, false},
                {false, false, false, false},
                {true, true, true, true}
            }, 1
          )
    {}
};

#endif //TETRIS_MINOS_ONE
