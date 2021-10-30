#ifndef GAME_SCENERY
#define GAME_SCENERY

#include "tetris-header.h"
#include "drawable-tetrisminos-factory.h"

class GameScenery
{
    sf::RenderWindow &window;
    SHPtrDrawableSystem drawableSystem;
    SHPtrRectangleShape floor;
    SHPtrRectangleShape leftWall;
    SHPtrRectangleShape rightWall;
    DrawableTetrisMinosFactory drawableTetrisMinosFactory;
    SHPtrEventSystem eventSystem;
    SHPtrCollisionSystem collisionSystem;
    SHPtrDrawableTetrisMinos drawableTetris = nullptr;
    void makeNewDrawableTetris();
    void init();
public:
    GameScenery(sf::RenderWindow &window);
    void draw();
    void update();
    void checkEvents(sf::Event &event);
    void checkTheLines();
};


#endif //GAME_SCENERY
