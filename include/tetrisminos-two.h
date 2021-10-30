#ifndef TETRIS_MINOS_TWO
#define TETRIS_MINOS_TWO

#include "tetris-minos.h"


class TetrisMinosTwo : public TetrisMinos
{

public:
    TetrisMinosTwo ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, true, false, false},
                {true, true, true, false},
                {false, false, false, false}
            }, 3
          )
    {}
};

#endif //TETRIS_MINOS_TWO
