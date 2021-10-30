#include "event-system.h"
#include "drawable-tetrisminos.h"
#include "collision-system.h"


EventSystem::EventSystem(SHPtrCollisionSystem collisionSystem)
    : collisionSystem (collisionSystem)
{

}

void EventSystem::checkRotation(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Z)
        {
            this->currentDrawableTetrisMinos->rotation();
            if (this->collisionSystem->checkWallCollision() || this->collisionSystem->checkCurrentCollision())
            {
                this->currentDrawableTetrisMinos->revertRotation();
            }
        }
    }
}

void EventSystem::checkMove(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            this->xMove = -TetrisVars::rectLength;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            this->xMove = TetrisVars::rectLength;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            this->yMove = TetrisVars::rectLength;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            this->xMove = 0.0;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            this->xMove = 0.0;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            this->yMove = 0.0;
        }
    }
    this->currentDrawableTetrisMinos->move(this->xMove, this->yMove);
    if (this->collisionSystem->checkWallCollision() || this->collisionSystem->checkCurrentCollision())
    {
        this->currentDrawableTetrisMinos->move(-this->xMove, -this->yMove);
    }
    else if (this->yMove > 0.0)
    {
        TetrisVars::countTime = 0.0;
    }
}

void EventSystem::setCurrentDrawableTetrisMinos(SHPtrDrawableTetrisMinos currentDrawableTetrisMinos)
{
    this->currentDrawableTetrisMinos = currentDrawableTetrisMinos;
}
