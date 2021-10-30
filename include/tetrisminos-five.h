#ifndef TETRIS_MINOS_FIVE
#define TETRIS_MINOS_FIVE

#include "tetris-minos.h"


class TetrisMinosFive : public TetrisMinos
{

public:
    TetrisMinosFive ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, false, true, false},
                {true, true, true, false},
                {false, false, false, false}
            }, 3
          )
    {}
};

#endif //TETRIS_MINOS_FOUR
