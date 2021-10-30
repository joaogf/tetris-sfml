#include "game-scenery.h"
#include "drawable-system.h"
#include "drawable-tetrisminos.h"
#include "event-system.h"
#include "collision-system.h"

GameScenery::GameScenery(sf::RenderWindow &window)
    : window(window)
{
    this->floor = SHPtrRectangleShape(new sf::RectangleShape(sf::Vector2f{TetrisVars::winWidth, TetrisVars::rectLength}));
    this->floor->setFillColor(sf::Color(255, 0, 0));
    this->floor->setPosition(sf::Vector2f{0.0, TetrisVars::winHeight - TetrisVars::rectLength});
    this->leftWall = SHPtrRectangleShape(new sf::RectangleShape(sf::Vector2f{TetrisVars::rectLength, TetrisVars::winHeight}));
    this->rightWall = SHPtrRectangleShape(new sf::RectangleShape (sf::Vector2f{TetrisVars::rectLength, TetrisVars::winHeight}));
    this->rightWall->setPosition(sf::Vector2f{TetrisVars::winWidth - TetrisVars::rectLength, 0.f});
    this->rightWall->setFillColor(sf::Color(255, 0, 0));
    this->leftWall->setFillColor(sf::Color(255, 0, 0));
    this->init();
}

void GameScenery::makeNewDrawableTetris()
{
    this->drawableTetris = this->drawableTetrisMinosFactory.make();
    this->drawableSystem->addTetrisMinosDrawable(this->drawableTetris);
    this->eventSystem->setCurrentDrawableTetrisMinos(this->drawableTetris);
    this->collisionSystem->setCurrentDrawableTetrisMinos(this->drawableTetris);
}

void GameScenery::init()
{
    this->drawableSystem = SHPtrDrawableSystem(new DrawableSystem(this->window, this->floor, this->leftWall, this->rightWall));
    this->collisionSystem = SHPtrCollisionSystem(new CollisionSystem(this->floor, this->leftWall, this->rightWall));
    this->eventSystem = SHPtrEventSystem(new EventSystem(this->collisionSystem));
    this->makeNewDrawableTetris();
}

void GameScenery::draw()
{
    this->drawableSystem->draw();
}

void GameScenery::update()
{
    this->drawableTetris->update();
    if (this->collisionSystem->checkCurrentCollision())
    {
        this->drawableTetris->move(0, -TetrisVars::rectLength);
        this->collisionSystem->addToStopped(this->drawableTetris);
        this->checkTheLines();
        this->makeNewDrawableTetris();
    }
}

void GameScenery::checkEvents(sf::Event &event)
{
    this->eventSystem->checkRotation(event);
    this->eventSystem->checkMove(event);
}

void GameScenery::checkTheLines()
{
    bool hasComplete;
    do
    {
        hasComplete = true;
        auto mapOfLines = this->collisionSystem->makeMapOfLines();
        for (auto &kv : mapOfLines)
        {
            if (kv.second == (TetrisVars::winWidth / TetrisVars::rectLength) - 2)
            {
                this->collisionSystem->destroyStoppedDrawableTetrisMinos(kv.first);
                hasComplete = false;
            }
        }
    } while(hasComplete == false);
}
