#include "header.h"

using namespace std;

int main()
{
    sf::Font MyFont;
    if (!MyFont.loadFromFile("bahnschrift.ttf"))
    {
       std::cout<<"Font not loaded"<<std::endl;
    }
    int ilosc_punktow=0;
    sf::Text punkty(std::to_string(ilosc_punktow), MyFont);
    punkty.setFillColor({0,0,0});
    punkty.setPosition(700,0);
    std::vector<std::unique_ptr<obiekt>> obiekty;

    sf::Texture tloo;
    if(!tloo.loadFromFile("gorki.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    tlo gory(tloo, 1, 1);
    obiekty.emplace_back(std::make_unique<tlo>(gory));

    sf::Texture samolot_wrogi;
    if(!samolot_wrogi.loadFromFile("samolot_red.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    samolot_wr samolot1(samolot_wrogi, -500, 300, 200, -50,{100,0,100,50},{0,0,100,50});
    obiekty.emplace_back(std::make_unique<samolot_wr>(samolot1));
    samolot_wr samolot1_1(samolot_wrogi, -200, 700, 200, -50,{100,0,100,50},{0,0,100,50});
    obiekty.emplace_back(std::make_unique<samolot_wr>(samolot1_1));


    sf::Texture samolot_dobry;
    if(!samolot_dobry.loadFromFile("samolot_blue.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    samolot_soj samolot2(samolot_dobry, -200, 100, 200, 50, {100,0,100,50},{0,0,100,50});
    obiekty.emplace_back(std::make_unique<samolot_soj>(samolot2));

    sf::Texture balon_wrogi;
    if(!balon_wrogi.loadFromFile("baloon_red.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    balon_wr balon1(balon_wrogi, 100, 300, 0, -60);
    obiekty.emplace_back(std::make_unique<balon_wr>(balon1));

    sf::Texture balon_dobry;
    if(!balon_dobry.loadFromFile("baloon_blue.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    balon_soj balon2(balon_dobry, 400, 300, 0, -60);
    obiekty.emplace_back(std::make_unique<balon_soj>(balon2));

    sf::RenderWindow window(sf::VideoMode(800.0, 600.0), "Lotnicy");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    sf::Texture serduszko;
    if(!serduszko.loadFromFile("heart.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    serca zycie(serduszko, 10,10);
    srand(time(NULL));
    sf::Clock clock;
    while (window.isOpen()) {


        if(zycie.get_serca()>0){
            sf::Time elapsed = clock.restart();
            sf::Event event;


            while (window.pollEvent(event)) {

                if (event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
                        std::cout << "Mouse clicked: " << mouse_pos_i.x << ", " << mouse_pos_i.y << std::endl;

                        sf::Vector2f mouse_pos_f = sf::Vector2f(mouse_pos_i);

                        for(int i=0; i<obiekty.size(); i++){

                            samolot_wr *temp_samolot_wr=dynamic_cast<samolot_wr*>(obiekty[i].get());
                            samolot_soj *temp_samolot_soj=dynamic_cast<samolot_soj*>(obiekty[i].get());
                            balon_wr *temp_balon_wr=dynamic_cast<balon_wr*>(obiekty[i].get());
                            balon_soj *temp_balon_soj=dynamic_cast<balon_soj*>(obiekty[i].get());
                            if(temp_samolot_wr!=nullptr){
                                if(temp_samolot_wr->getGlobalBounds().contains(mouse_pos_f))
                                {obiekty.erase(obiekty.begin()+i);
                                    samolot_wr nowy(samolot_wrogi, -((rand()%300)+350), (rand()%400)+200, 200, -50,{100,0,100,50},{0,0,100,50});
                                    obiekty.emplace_back(std::make_unique<samolot_wr>(nowy));
                                    ilosc_punktow++;
                                    punkty.setString(std::to_string(ilosc_punktow));
                                }
                            }
                            if(temp_samolot_soj!=nullptr){
                                if(temp_samolot_soj->getGlobalBounds().contains(mouse_pos_f)){
                                    obiekty.erase(obiekty.begin()+i);
                                    zycie.odejmij();
                                    samolot_soj nowy(samolot_dobry, -((rand()%300)+350), (rand()%400)+200, 200, 50, {100,0,100,50},{0,0,100,50});
                                    obiekty.emplace_back(std::make_unique<samolot_soj>(nowy));
                                }
                            }
                            if(temp_balon_wr!=nullptr){
                                if(temp_balon_wr->getGlobalBounds().contains(mouse_pos_f)){
                                    obiekty.erase(obiekty.begin()+i);
                                    balon_wr nowy(balon_wrogi, rand()%600+100, rand()%300+700, 0, -60);
                                    obiekty.emplace_back(std::make_unique<balon_wr>(nowy));
                                    ilosc_punktow++;
                                    punkty.setString(std::to_string(ilosc_punktow));
                                }
                            }
                            if(temp_balon_soj!=nullptr){
                                if(temp_balon_soj->getGlobalBounds().contains(mouse_pos_f)){
                                    balon_soj nowy(balon_dobry, rand()%600+100, rand()%300+700, 0, -60);
                                    obiekty.erase(obiekty.begin()+i);
                                    obiekty.emplace_back(std::make_unique<balon_soj>(nowy));
                                    zycie.odejmij();
                                }
                            }
                        }

                    }
                }
                if (event.type == sf::Event::Closed) {
                    std::cout << "Closing Window" << std::endl;
                    window.close();
                }

            }
            for (auto &ob:obiekty){
                samolot_wr *temp_samolot_wr=dynamic_cast<samolot_wr*>(ob.get());
                samolot_soj *temp_samolot_soj=dynamic_cast<samolot_soj*>(ob.get());
                balon_wr *temp_balon_wr=dynamic_cast<balon_wr*>(ob.get());
                balon_soj *temp_balon_soj=dynamic_cast<balon_soj*>(ob.get());
                if(temp_samolot_wr!=nullptr){
                    temp_samolot_wr->moving( elapsed);
                }
                if(temp_samolot_soj!=nullptr){
                    temp_samolot_soj->moving( elapsed);
                }
                if(temp_balon_wr!=nullptr){
                    temp_balon_wr->moving( elapsed);
                }
                if(temp_balon_soj!=nullptr){
                    temp_balon_soj->moving( elapsed);
                }
            }

            zycie.moving();
            window.clear(sf::Color::White);
            for(auto &e:obiekty) window.draw(*e);
            window.draw(zycie);
            window.draw(punkty);
            window.display();
        }
        else if(zycie.get_serca()<=0){
            sf::Event event;
            cout<<"Przegrales"<<endl;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed) {
                    std::cout << "Closing Window" << std::endl;
                    window.close();
                }
            }
            window.clear(sf::Color::White);
            window.display();
        }








    }
    return 0;
}
