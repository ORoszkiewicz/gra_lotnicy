#ifndef BALON_WR_H
#define BALON_WR_H
#include <obiekt.h>

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

#endif // BALON_WR_H
