#include <iostream>
#include <test.h>
#include <SFML/Graphics.hpp>

int main(){

    Test test;
    test.testfunc();

    std::cout << "Hello, World!" << std::endl;

    sf::Texture texture(RESOURCES_PATH "tank.png");
    sf::Sprite sprite(texture);
    sprite.scale({0.25,0.25});

   
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}