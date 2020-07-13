#ifndef BRON_H
#define BRON_H
#include <obiekt.h>

class bron : public obiekt{
private:
    int hearts;
public:
    bron(sf::Texture &tekstura, int x, int y);
    void moving(sf::Time elapsed);
};

#endif // BRON_H
