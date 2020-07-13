#ifndef SAMOLOT_SOJ_H
#define SAMOLOT_SOJ_H
#include <obiekt.h>

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

#endif // SAMOLOT_SOJ_H
