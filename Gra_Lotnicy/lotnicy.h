#ifndef LOTNICY_H
#define LOTNICY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#endif // LOTNICY_H


class obiekt{
public:
    void setsize();
    void setcolour();
};

class latajace : public obiekt{
private:

public:
    virtual void move() = 0;
};

class samolot_wr : public latajace{
private:
    int hearts;
    int colour;
public:
    void move();
};

class balon_wr : public latajace{
private:
    int hearts;
    int colour;
public:
    void move();
};

class samolot_soj : public latajace{
private:
    int hearts;
    int colour;
public:
    void move();
};

class balon_soj : public latajace{
private:
    int hearts;
    int colour;
public:
    void move();
};

class bron : public obiekt{
private:
    int hearts;
public:
    void strzelaj();
};
