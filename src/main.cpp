#include <iostream>
#include <test.h>
#include <SFML/Graphics.hpp>

int main(){

    Test test;
    test.testfunc();

    std::cout << "Hello, World!" << std::endl;

    sf::Window window(sf::VideoMode({ 800, 600 }), "My window");

    sf::Texture texture(RESOURCES_PATH "tank.png");
    sf::Sprite sprite(texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

     
        window.draw(sprite);

       
        window.display();
    }
    return 0;
}