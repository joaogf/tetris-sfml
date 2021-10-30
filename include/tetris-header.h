#ifndef TETRIS_HEADER
#define TETRIS_HEADER

#include <SFML/Graphics.hpp>
#include <memory>

class DrawableSystem;
class TetrisMinos;
class DrawableTetrisMinos;
class EventSystem;
class CollisionSystem;

using SHPtrDrawableSystem = std::shared_ptr<DrawableSystem>;
using SHPtrTetrisMinos = std::shared_ptr<TetrisMinos>;
using SHPtrRectangleShape = std::shared_ptr<sf::RectangleShape>;
using VectorOfRetangleShape = std::vector<SHPtrRectangleShape>;
using SHPtrDrawableTetrisMinos = std::shared_ptr<DrawableTetrisMinos>;
using VectorOfDrawableTetris = std::vector<SHPtrDrawableTetrisMinos>;
using SHPtrEventSystem = std::shared_ptr<EventSystem>;
using SHPtrCollisionSystem = std::shared_ptr<CollisionSystem>;



struct TetrisVars
{
    static const int winWidth = 280;
    static const int winHeight = 400;
    static const int numberOfRects = 4;
    static const int rectLength = 20;
    static const int maxNumberOfTetrisRotation = 4;
    static float countTime;
    static constexpr float deltaTime = 0.25;

};

#endif //TETRIS_HEADER
