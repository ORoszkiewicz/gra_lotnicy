#ifndef BALON_SOJ_H
#define BALON_SOJ_H
#include<iostream>
#include<vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<math.h>
#include<memory>
#include <cstdlib>
#include<fstream>
#include<string>
#include<sstream>

class obiekt: public sf::Sprite{
public:
    //virtual void moving(sf::Time elapsed) = 0;
};

class balon_soj : public obiekt{
    sf::IntRect lewy;
    sf::IntRect prawy;
    bool left;
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    balon_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void moving(sf::Time elapsed);
};

class balon_wr : public obiekt{
private:
    sf::IntRect lewy;
    sf::IntRect prawy;
    bool left;
    float speed_x;
    float speed_y;
    int hearts;
public:
    balon_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void moving(sf::Time elapsed);
};

class bron : public obiekt{
private:
    int hearts;
public:
    bron(sf::Texture &tekstura, int x, int y);
    void moving(sf::Time elapsed);
};

class samolot_soj : public obiekt{
private:
    sf::IntRect lewy;
    sf::IntRect prawy;
    bool left;
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy, sf::IntRect lewy_,sf::IntRect prawy_);
    void moving(sf::Time elapsed);
};


class samolot_wr : public obiekt{
private:
    sf::IntRect lewy;
    sf::IntRect prawy;
    bool left;
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy, sf::IntRect lewy_,sf::IntRect prawy_);
    void moving(sf::Time elapsed);
};

class tlo : public obiekt{
public:
    tlo(sf::Texture &tekstura, int x, int y);
};

class serca : public obiekt{
    int zycia=3;
public:
    serca(sf::Texture &tekstura, int x, int y);
    int get_serca();
    void odejmij();
    void moving();
};
bool sortbysec(const std::pair<std::string,int> &a,const std::pair<std::string,int> &b) ;
#endif // BALON_SOJ_H
