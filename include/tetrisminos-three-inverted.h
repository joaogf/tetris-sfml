#ifndef TETRIS_MINOS_THREE_INVERTED
#define TETRIS_MINOS_THREE_INVERTED

#include "tetris-minos.h"


class TetrisMinosThreeInverted : public TetrisMinos
{

public:
    TetrisMinosThreeInverted ()
        : TetrisMinos
          (
            {
                {false, false, false, false},
                {false, false, false, false},
                {false, true, true, false},
                {true, true, false, false}
            }, 1
          )
    {}
};

#endif //TETRIS_MINOS_THREE_INVERTED
