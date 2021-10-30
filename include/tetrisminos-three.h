#ifndef TETRIS_MINOS_THREE
#define TETRIS_MINOS_THREE

#include "tetris-minos.h"


class TetrisMinosThree : public TetrisMinos
{

public:
    TetrisMinosThree ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, false, false, false},
                {false, true, true, false},
                {false, false, true, true}
            }, 1
          )
    {}
};

#endif //TETRIS_MINOS_THREE
