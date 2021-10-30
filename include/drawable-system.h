#ifndef DRAWABLE_SYSTEM
#define DRAWABLE_SYSTEM

#include "tetris-header.h"

class DrawableSystem
{
    sf::RenderWindow &window;
    VectorOfDrawableTetris drawablesTetrisMinos;
    SHPtrRectangleShape floor;
    SHPtrRectangleShape leftWall;
    SHPtrRectangleShape rightWall;
    sf::Texture background;
    sf::Sprite sBackground;
public:
    DrawableSystem
    (
        sf::RenderWindow &window,
        SHPtrRectangleShape floor,
        SHPtrRectangleShape leftWall,
        SHPtrRectangleShape rightWall
    );
    void draw();
    void update();
    void addTetrisMinosDrawable(SHPtrDrawableTetrisMinos drawableTetrisMinos);
};

#endif //DRAWABLE_SYSTEM
