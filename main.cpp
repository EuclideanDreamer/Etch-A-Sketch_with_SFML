#include "SFML/Graphics.hpp"
int main() {

    //give us some floats
    float x = 0, y = 50, z = 250;


    //Opens window creates event
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Etch-A-Sketch");
    sf::Event e;
    //
    window.setFramerateLimit(400); // call it once, after creating the window
    // 
    // window.setVerticalSyncEnabled(window.isOpen()); // call it once, after creating the window, 
    //if window is open it will sync the framerate to monitor
    sf::Vector2f size(3.0f, 3.0f);


    //this section 											   
    sf::RectangleShape rect(size);
    sf::Vector2f rectPos(800, 450);
    sf::Vector2f movement(0, 0);
    rect.setPosition(rectPos);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.clear();

            //bindings to make square move
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y = -2;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y = 2;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x = -2;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x = 2;
        }
        rect.move(movement);//move dot
        movement.x = 0; movement.y = 0;//return movement to 0
        rect.setFillColor(sf::Color(x, y, z));//set color
        if (x > 255) { x = 0; y += 50; }//return x to 0 if > 255 add 50 to y
        x++;//change color up
        if (y > 255) { y = 50; z--; }
        if (z < 2) { z = 250; }

        window.draw(rect);//render dot
        // end the current frame
        window.display();//frame
    }
    return 0;
}
