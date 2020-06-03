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
    balon_soj();
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
    bron();
    void strzelaj();
    void move();
};

class samolot_soj : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_soj();
    void move();
};


class samolot_wr : public obiekt{
private:
    float speed_x;
    float speed_y;
    int hearts;
public:
    samolot_wr();
    void move();
};

#endif // BALON_SOJ_H
