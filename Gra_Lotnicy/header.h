#ifndef BALON_SOJ_H
#define BALON_SOJ_H
#include<iostream>
#include<vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<math.h>
#include<memory>


class obiekt: public sf::Sprite{
public:
    //virtual void moving() = 0;
};

class balon_soj : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    balon_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void moving();
};

class balon_wr : public obiekt{
private:
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
    void strzelaj();
    void moving();
};

class samolot_soj : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void moving(sf::Time elapsed);
};


class samolot_wr : public obiekt{
    sf::IntRect lewy;
    sf::IntRect prawy;
    bool left;
private:
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
public:
    serca(sf::Texture &tekstura, int x, int y, int liczba_serc);
};

#endif // BALON_SOJ_H
