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
    //virtual void move() = 0;
};

class balon_soj : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    balon_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void move();
};

class balon_wr : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    balon_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void move();
};

class bron : public obiekt{
private:
    int hearts;
public:
    bron(sf::Texture &tekstura, int x, int y);
    void strzelaj();
    void move();
};

class samolot_soj : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void move();
};


class samolot_wr : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy);
    void move();
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
