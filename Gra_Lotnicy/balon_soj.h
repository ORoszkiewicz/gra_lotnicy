#ifndef BALON_SOJ_H
#define BALON_SOJ_H
#include <obiekt.h>

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

#endif // BALON_SOJ_H
