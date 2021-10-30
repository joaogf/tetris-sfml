#include "drawable-system.h"
#include "drawable-tetrisminos.h"

DrawableSystem::DrawableSystem
(
    sf::RenderWindow &window,
    SHPtrRectangleShape floor,
    SHPtrRectangleShape leftWall,
    SHPtrRectangleShape rightWall
)
    : window(window), floor(floor), leftWall(leftWall), rightWall(rightWall)
{
    this->background.loadFromFile("img/frame.png");
    this->sBackground.setTexture(this->background);
}

void DrawableSystem::draw()
{
    window.draw(this->sBackground);
    for (auto drawableTetrisMinos : this->drawablesTetrisMinos)
    {
        drawableTetrisMinos->draw(this->window);
    }
}

void DrawableSystem::update()
{

}

void DrawableSystem::addTetrisMinosDrawable(SHPtrDrawableTetrisMinos drawableTetrisMinos)
{
    this->drawablesTetrisMinos.push_back(drawableTetrisMinos);
}
