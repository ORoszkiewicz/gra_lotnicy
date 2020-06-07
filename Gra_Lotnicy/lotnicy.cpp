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

samolot_wr :: samolot_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy,sf::IntRect lewy_,sf::IntRect prawy_){
    lewy=lewy_;
    prawy=prawy_;
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
    //setTexture(left);
    left=1;
}
void samolot_wr::moving(sf::Time elapsed){
    float time=elapsed.asSeconds();
    if(left==1){
        move(speed_x*time, speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)>=1000){
            left=0;
        }
    }
    if(left==0){
        move(-speed_x*time, -speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)<=-100){
            left=1;

        }
    }
}
void samolot_soj::moving(sf::Time elapsed){


    float time=elapsed.asSeconds();
    move(speed_x*time, speed_y*time);

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
