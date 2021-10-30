#ifndef COLLISION_SYSTEM
#define COLLISION_SYSTEM

#include "tetris-header.h"

class CollisionSystem
{
    SHPtrRectangleShape floor;
    SHPtrDrawableTetrisMinos currentDrawableTetrisMinos = nullptr;
    VectorOfDrawableTetris stoppedDrawableTetrisMinos;
    SHPtrRectangleShape leftWall;
    SHPtrRectangleShape rightWall;
    bool checkCollision(SHPtrRectangleShape rect);
public:
    CollisionSystem
    (
        SHPtrRectangleShape floor,
        SHPtrRectangleShape leftWall,
        SHPtrRectangleShape rightWall
    );
    bool checkWallCollision();
    bool checkFloorCollision();
    bool checkCurrentCollision();
    bool checkDrawableTetrisMinosCollision();
    void setCurrentDrawableTetrisMinos(SHPtrDrawableTetrisMinos currentDrawableTetrisMinos);
    void destroyStoppedDrawableTetrisMinos(int yPos);
    void addToStopped(SHPtrDrawableTetrisMinos drawableTetrisMinos);
    std::map<int, int> makeMapOfLines();

};

#endif //COLLISION_SYSTEM
