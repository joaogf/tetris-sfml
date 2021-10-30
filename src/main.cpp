#include "game-scenery.h"

float TetrisVars::countTime = 0.0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(TetrisVars::winWidth + 100, TetrisVars::winHeight), "Simple Tetris");
    GameScenery game(window);
    window.setFramerateLimit(30);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            game.checkEvents(event);
        }
        sf::Time elapsed = clock.restart();
        TetrisVars::countTime += elapsed.asSeconds();
        window.clear();
        game.update();
        game.draw();
        window.display();
        if (TetrisVars::countTime > TetrisVars::deltaTime)
        {
            TetrisVars::countTime = sf::Time::Zero.asSeconds();
        }

    }

    return 0;
}
