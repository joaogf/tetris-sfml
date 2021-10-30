#ifndef DRAWABLE_TETRIS_MINOS
#define DRAWABLE_TETRIS_MINOS

#include "tetris-header.h"

class DrawableTetrisMinos
{
    float x, y;
    SHPtrTetrisMinos tetrisMinos;
    sf::Texture texture;
    VectorOfRetangleShape rectangles;
    static constexpr int numberOfColors = 5;
public:
    DrawableTetrisMinos(SHPtrTetrisMinos tetrisMinos, float x, float y);
    const VectorOfRetangleShape& getRectangles();
    void setRectangles(const VectorOfRetangleShape &rectangles);
    void deleteRectangles(int yPos);
    void draw(sf::RenderWindow &window);
    void configure();
    void rotation();
    void revertRotation();
    void move(float xMove, float yMove);
    void update();
};

#endif //DRAWABLE_TETRIS_MINOS
