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
    if(!samolot_wrogi.loadFromFile("Biplane-kopia.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    samolot_wr samolot1(samolot_wrogi, -500, 300, 200, -5,{0,0,0,0},{0,0,0,0});
    obiekty.emplace_back(std::make_unique<samolot_wr>(samolot1));

    sf::Texture samolot_dobry;
    if(!samolot_dobry.loadFromFile("Biplane2.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    samolot_soj samolot2(samolot_dobry, -200, 100, 200, 5);
    obiekty.emplace_back(std::make_unique<samolot_soj>(samolot2));

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

        samolot_wr &temp_sam_1=dynamic_cast<samolot_wr&>(*obiekty[1]);
        temp_sam_1.moving( elapsed);
        samolot_soj &temp_sam_2=dynamic_cast<samolot_soj&>(*obiekty[2]);
        temp_sam_2.moving( elapsed);

        window.clear(sf::Color::White);
        for(auto &e:obiekty) window.draw(*e);
        window.display();
    }
    return 0;
}
