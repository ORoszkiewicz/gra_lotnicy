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

    sf::Texture czolg;
    if(!czolg.loadFromFile("czolg.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    bron czolg2(czolg, 680, 530);
    obiekty.emplace_back(std::make_unique<bron>(czolg2));

    sf::RenderWindow window(sf::VideoMode(800.0, 600.0), "Lotnicy");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    sf::Texture serduszko;
    if(!serduszko.loadFromFile("heart.png")) { std::cout<<"Texture not loaded"<<std::endl; }
    serca zycie(serduszko, 10,10);
    srand(time(NULL));
    sf::Clock clock;
    sf::Time time_sum;
    string imie;
    std::cout<<"Podaj imie: ";
    std::cin>>imie;
    while (window.isOpen()) {


        if(zycie.get_serca()>0){
            sf::Time elapsed = clock.restart();
            sf::Event event;


            while (window.pollEvent(event)) {

                if (event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
                        //std::cout << "Mouse clicked: " << mouse_pos_i.x << ", " << mouse_pos_i.y << std::endl;

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
             sf::Time elapsed = clock.restart();
             time_sum+=elapsed;
             if(time_sum.asSeconds()>2){
                 std::cout<<"Zatrzymuję"<<std::endl;
                 window.close();
             }
            sf::Event event;
            punkty.setString("You lost");
            punkty.setScale({2,2});
            punkty.setPosition(300,250);//ustawienie nappisu
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed) {
                    std::cout << "Closing Window" << std::endl;
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            window.draw(punkty);
            window.display();
        }

    }
    ofstream file;
    file.open("punkty.txt", std::ios::out| std::ios::app);
    if(!file.is_open())std::cout<<"Nie otwarto pliku"<<std::endl;
    file<<imie<<" "<<ilosc_punktow<<std::endl;
    sf::RenderWindow window2(sf::VideoMode(800.0, 600.0), "Lotnicy");
    window2.setVerticalSyncEnabled(true);
    window2.setFramerateLimit(30);


    ifstream file_open;
    file_open.open("punkty.txt", std::ios::in);
    if(!file_open.is_open())std::cout<<"Nie otwarto pliku"<<std::endl;
    std::vector<pair<string, int>> ranking;

    string napis_;
        while (!file_open.eof())
        {
            std::getline(file_open, napis_);
            for (int i = 0; i <= napis_.length(); i++)
            {
                if (napis_[i] == ' ')
                {

                    string imie = napis_.substr(0, i);
                    string punktu = napis_.substr(i + 1);
                    ranking.push_back({imie,std::stoi(punktu)});
                }
            }
        }
        sort(ranking.begin(), ranking.end(),sortbysec);
        string position_1=ranking[ranking.size()-1].first+"             "+std::to_string(ranking[ranking.size()-1].second);
        string position_2=ranking[ranking.size()-2].first+"             "+std::to_string(ranking[ranking.size()-2].second);
        string position_3=ranking[ranking.size()-3].first+"             "+std::to_string(ranking[ranking.size()-3].second);
        string position_4=ranking[ranking.size()-4].first+"             "+std::to_string(ranking[ranking.size()-4].second);
        string position_5=ranking[ranking.size()-5].first+"             "+std::to_string(ranking[ranking.size()-5].second);
        sf::Text pos_1(position_1, MyFont);
        pos_1.setFillColor({0,0,0});
        pos_1.setPosition(250,100);
        sf::Text pos_2(position_2, MyFont);
        pos_2.setFillColor({0,0,0});
        pos_2.setPosition(250,150);
        sf::Text pos_3(position_3, MyFont);
        pos_3.setFillColor({0,0,0});
        pos_3.setPosition(250,200);
        sf::Text pos_4(position_4, MyFont);
        pos_4.setFillColor({0,0,0});
        pos_4.setPosition(250,250);
        sf::Text pos_5(position_5, MyFont);
        pos_5.setFillColor({0,0,0});
        pos_5.setPosition(250,300);

        sf::Text rankingg("Top 5 Graczy:", MyFont);
        rankingg.setFillColor({2,1,3});
        rankingg.setPosition(250,50);

        while (window2.isOpen()){
        sf::Event event;
        while (window2.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                std::cout << "Closing Window" << std::endl;
                window2.close();
            }

            window2.clear(sf::Color::White);
            window2.draw(pos_1);
            window2.draw(pos_2);
            window2.draw(pos_3);
            window2.draw(pos_4);
            window2.draw(pos_5);
            window2.draw(rankingg);
            window2.display();
        }
    }
    return 0;
}
