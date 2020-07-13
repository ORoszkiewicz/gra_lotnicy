#ifndef SAMOLOT_WR_H
#define SAMOLOT_WR_H
#include <obiekt.h>

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

#endif // SAMOLOT_WR_H
