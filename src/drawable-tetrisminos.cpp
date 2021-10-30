#include "drawable-tetrisminos.h"
#include "tetris-minos.h"

DrawableTetrisMinos::DrawableTetrisMinos(SHPtrTetrisMinos tetrisMinos, float x, float y)
    : tetrisMinos (tetrisMinos), x(x), y(y)
{
    std::string name = "img/b" + std::to_string(rand() % numberOfColors) + ".png";
    this->texture.loadFromFile(name);
    this->configure();
}

const VectorOfRetangleShape &DrawableTetrisMinos::getRectangles()
{
    return this->rectangles;
}

void DrawableTetrisMinos::setRectangles(const VectorOfRetangleShape &rectangles)
{
    this->rectangles = rectangles;
}

void DrawableTetrisMinos::deleteRectangles(int yPos)
{
    VectorOfRetangleShape newRectangles;
    for (auto rectangle : this->rectangles)
    {
        if (static_cast<int>(rectangle->getPosition().y) != yPos)
        {
            newRectangles.push_back(rectangle);
        }
    }
    this->setRectangles(newRectangles);
}

void DrawableTetrisMinos::draw(sf::RenderWindow &window)
{
    for (auto rectangle : this->rectangles)
    {
        window.draw(*(rectangle.get()));
    }
}

void DrawableTetrisMinos::configure()
{
    auto const &matrix = tetrisMinos->getMatrix();
    this->rectangles.clear();
    for (unsigned int cnt = 0; cnt < TetrisVars::numberOfRects; ++cnt)
    {
        this->rectangles.push_back(SHPtrRectangleShape(new sf::RectangleShape(sf::Vector2f(TetrisVars::rectLength, TetrisVars::rectLength))));
        this->rectangles.back()->setTexture(&this->texture);
    }
    float currentX;
    float currentY = this->y;
    unsigned int currentRectangle = 0;
    for (int row = matrix.size() - 1; row >= 0; --row)
    {
        currentX = this->x;
        for (int col = 0; col < matrix[row].size(); ++col)
        {
            if (matrix[row][col] == true)
            {
                this->rectangles[currentRectangle]->setPosition(currentX, currentY);
                ++currentRectangle;
            }
            currentX += TetrisVars::rectLength;
        }
        currentY -= TetrisVars::rectLength;
    }
}

void DrawableTetrisMinos::rotation()
{
    this->tetrisMinos->rotation();
    this->configure();
}

void DrawableTetrisMinos::revertRotation()
{
    this->tetrisMinos->revertRotation();
    this->configure();
}

void DrawableTetrisMinos::move(float xMove, float yMove)
{
    this->x += xMove;
    this->y += yMove;
    this->configure();
}

void DrawableTetrisMinos::update()
{
    if (TetrisVars::countTime > TetrisVars::deltaTime)
    {
        this->y += TetrisVars::rectLength;
        this->configure();
    }
}
