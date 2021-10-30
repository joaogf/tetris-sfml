#ifndef DRAWABLE_TETRIS_MINOS_FACTORY
#define DRAWABLE_TETRIS_MINOS_FACTORY

#include "tetris-header.h"
#include <functional>

class DrawableTetrisMinosFactory
{
    using Lambda = std::function<SHPtrDrawableTetrisMinos()>;
    using VectorOfMakes = std::vector<Lambda>;
    static const VectorOfMakes vecMakes;
    static const float xInitialPosition;

    static SHPtrDrawableTetrisMinos makeOne();
    static SHPtrDrawableTetrisMinos makeTwo();
    static SHPtrDrawableTetrisMinos makeThree();
    static SHPtrDrawableTetrisMinos makeThreeInverted();
    static SHPtrDrawableTetrisMinos makeFour();
    static SHPtrDrawableTetrisMinos makeFive();

public:
    DrawableTetrisMinosFactory();
    SHPtrDrawableTetrisMinos make();
};

#endif //DRAWABLE_TETRIS_MINOS_FACTORY
