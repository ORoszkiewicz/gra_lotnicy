#include <header.h>

balon_wr :: balon_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}
