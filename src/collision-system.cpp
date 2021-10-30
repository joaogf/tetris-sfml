#include "collision-system.h"
#include "drawable-tetrisminos.h"

CollisionSystem::CollisionSystem
(
    SHPtrRectangleShape floor,
    SHPtrRectangleShape leftWall,
    SHPtrRectangleShape rightWall
)
    : floor (floor), leftWall (leftWall), rightWall (rightWall)
{

}

bool CollisionSystem::checkCollision(SHPtrRectangleShape rect)
{
    float bX = rect->getPosition().x;
    float bY = rect->getPosition().y;
    float bW = rect->getSize().x;
    float bH = rect->getSize().y;
    for (auto tetrisRect : this->currentDrawableTetrisMinos->getRectangles())
    {
        float aX = tetrisRect->getPosition().x;
        float aY = tetrisRect->getPosition().y;
        float aW = tetrisRect->getSize().x;
        float aH = tetrisRect->getSize().y;

        if
        (
            aX < bX + bW &&
            bX < aX + aW &&
            aY < bY + bH &&
            bY < aY + aH
        )
        {
            return true;
        }
    }
    return false;
}

bool CollisionSystem::checkWallCollision()
{
    return this->checkCollision(this->rightWall) || this->checkCollision(this->leftWall);
}

bool CollisionSystem::checkFloorCollision()
{
    return this->checkCollision(this->floor);
}

bool CollisionSystem::checkCurrentCollision()
{
    if (this->checkFloorCollision() || this->checkDrawableTetrisMinosCollision())
    {
        return true;
    }
    return false;
}

void CollisionSystem::destroyStoppedDrawableTetrisMinos(int yPos)
{
    for (auto drawMinos : this->stoppedDrawableTetrisMinos)
    {
        drawMinos->deleteRectangles(yPos);
    }
    VectorOfDrawableTetris newDrawableTetris;
    for (auto drawMinos : this->stoppedDrawableTetrisMinos)
    {
        if (drawMinos->getRectangles().size() > 0)
        {
            newDrawableTetris.push_back(drawMinos);
        }
    }
    this->stoppedDrawableTetrisMinos = newDrawableTetris;
    for (auto drawMinos: this->stoppedDrawableTetrisMinos)
    {
        VectorOfRetangleShape rectangles = drawMinos->getRectangles();
        for (auto rectangle : rectangles)
        {
            if (static_cast<int>(rectangle->getPosition().y) < yPos)
            {
                rectangle->setPosition(rectangle->getPosition().x, rectangle->getPosition().y + TetrisVars::rectLength);
            }
        }
        drawMinos->setRectangles(rectangles);
    }
}

bool CollisionSystem::checkDrawableTetrisMinosCollision()
{
    for (auto drawableTetrisMinos : this->stoppedDrawableTetrisMinos)
    {
        for (auto rectangle : drawableTetrisMinos->getRectangles())
        {
            if (this->checkCollision(rectangle)) return true;
        }
    }
    return false;
}

void CollisionSystem::setCurrentDrawableTetrisMinos(SHPtrDrawableTetrisMinos currentDrawableTetrisMinos)
{
    this->currentDrawableTetrisMinos = currentDrawableTetrisMinos;
}

void CollisionSystem::addToStopped(SHPtrDrawableTetrisMinos drawableTetrisMinos)
{
    this->stoppedDrawableTetrisMinos.push_back(drawableTetrisMinos);
}

std::map<int, int> CollisionSystem::makeMapOfLines()
{
    std::map<int, int> mapOfLines;
    for (auto drawMinos : this->stoppedDrawableTetrisMinos)
    {
        for (auto rec : drawMinos->getRectangles())
        {
            mapOfLines[rec->getPosition().y]++;
        }
    }
    return mapOfLines;
}
