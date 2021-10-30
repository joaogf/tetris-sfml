#ifndef TETRIS_MINOS_FOUR
#define TETRIS_MINOS_FOUR

#include "tetris-minos.h"


class TetrisMinosFour : public TetrisMinos
{

public:
    TetrisMinosFour ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, false, false, false},
                {true, true, false, false},
                {true, true, false, false}
            }, 0
          )
    {}
};

#endif //TETRIS_MINOS_FOUR
