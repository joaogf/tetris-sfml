#include "drawable-tetrisminos-factory.h"
#include "drawable-tetrisminos.h"
#include "tetrisminos-one.h"
#include "tetrisminos-two.h"
#include "tetrisminos-three.h"
#include "tetrisminos-three-inverted.h"
#include "tetrisminos-four.h"
#include "tetrisminos-five.h"
#include <cstdlib>
#include <ctime>

const DrawableTetrisMinosFactory::VectorOfMakes DrawableTetrisMinosFactory::vecMakes =
{
    &DrawableTetrisMinosFactory::makeOne,
    &DrawableTetrisMinosFactory::makeTwo,
    &DrawableTetrisMinosFactory::makeThree,
    &DrawableTetrisMinosFactory::makeThreeInverted,
    &DrawableTetrisMinosFactory::makeFour,
    &DrawableTetrisMinosFactory::makeFive,
};

const float DrawableTetrisMinosFactory::xInitialPosition = (TetrisVars::winWidth / 2) - TetrisVars::rectLength;


SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeOne()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosOne()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeTwo()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosTwo()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeThree()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosThree()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeThreeInverted()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosThreeInverted()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeFour()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosFour()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::makeFive()
{
    return SHPtrDrawableTetrisMinos
            (
                new DrawableTetrisMinos(SHPtrTetrisMinos(new TetrisMinosFive()), DrawableTetrisMinosFactory::xInitialPosition, TetrisVars::rectLength)
            );
}

DrawableTetrisMinosFactory::DrawableTetrisMinosFactory()
{
    srand((unsigned) time(0));
}

SHPtrDrawableTetrisMinos DrawableTetrisMinosFactory::make()
{
    unsigned int index = rand() % 6;
    return vecMakes[index]();
}
