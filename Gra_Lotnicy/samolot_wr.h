#ifndef SAMOLOT_WR_H
#define SAMOLOT_WR_H
#include<latajace.h>

class samolot_wr : public latajace{
private:
    int hearts;
    int colour;
public:
    void move();
};

#endif // SAMOLOT_WR_H
