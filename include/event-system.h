#ifndef EVENT_SYSTEM
#define EVENT_SYSTEM

#include "tetris-header.h"

class EventSystem
{
    SHPtrDrawableTetrisMinos currentDrawableTetrisMinos = nullptr;
    SHPtrCollisionSystem collisionSystem;
    float xMove = 0.0, yMove = 0.0;
public:
    EventSystem(SHPtrCollisionSystem collisionSystem);
    void checkRotation(sf::Event &event);
    void checkMove(sf::Event &event);
    void setCurrentDrawableTetrisMinos(SHPtrDrawableTetrisMinos currentDrawableTetrisMinos);
};

#endif //EVENT_SYSTEM
