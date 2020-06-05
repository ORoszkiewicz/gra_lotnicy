#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    std::vector<std::unique_ptr<obiekt>> obiekty;

    sf::Texture tloo;
    if(!tloo.loadFromFile("gorki.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    tlo gory(tloo, 1, 1);
    obiekty.emplace_back(std::make_unique<tlo>(gory));

    sf::Texture samolot_wrogi;
    if(!samolot_wrogi.loadFromFile("Biplane.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    samolot_wr samolot1(samolot_wrogi, 1, 1, 1, 1);
    obiekty.emplace_back(std::make_unique<samolot_wr>(samolot1));

    sf::RenderWindow window(sf::VideoMode(800.0, 600.0), "Lotnicy");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    srand(time(NULL));
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                std::cout << "Closing Window" << std::endl;
                window.close();
            }

        }
        window.clear(sf::Color::White);
         for(auto &e:obiekty) window.draw(*e);
        window.display();
    }
    return 0;
}
