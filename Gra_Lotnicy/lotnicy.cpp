#include <header.h>

balon_wr :: balon_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}

balon_soj :: balon_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}

samolot_wr :: samolot_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}

samolot_soj :: samolot_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}

bron :: bron(sf::Texture &tekstura, int x, int y){
    setPosition(x, y);
    setTexture(tekstura);
}

tlo :: tlo(sf::Texture &tekstura, int x, int y){
    setPosition(x, y);
    setTexture(tekstura);
}

serca :: serca(sf::Texture &tekstura, int x, int y, int liczba_serc){
    setPosition(x, y);
    setTexture(tekstura);
    int zycia = liczba_serc;
}
