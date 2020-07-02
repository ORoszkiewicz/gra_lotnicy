#include <header.h>

balon_wr :: balon_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}

void balon_wr :: moving(sf::Time elapsed){
    float time=elapsed.asSeconds();
    if(left==1){
        move(speed_x*time, speed_y*time);
        if((getGlobalBounds().height+getGlobalBounds().top)<=0){
            left=0;
        }
    }
    if(left==0){
        move(-speed_x*time, -speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().top)>=780){
            left=1;

        }
    }
}

balon_soj :: balon_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy){
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    setTexture(tekstura);
}
void balon_soj :: moving(sf::Time elapsed){
    float time=elapsed.asSeconds();
    if(left==1){
        move(speed_x*time, speed_y*time);
        if((getGlobalBounds().height+getGlobalBounds().top)<=0){
            left=0;
        }
    }
    if(left==0){
        move(-speed_x*time, -speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().top)>=730){
            left=1;

        }
    }
}

samolot_wr :: samolot_wr(sf::Texture &tekstura, int x, int y, float speedx, float speedy,sf::IntRect lewy_,sf::IntRect prawy_){
    lewy=lewy_;
    prawy=prawy_;
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    left=1;
    setTexture(tekstura);
    setTextureRect(lewy);

}
void samolot_wr::moving(sf::Time elapsed){
    float time=elapsed.asSeconds();
    if(left==1){
        setTextureRect(lewy);
        move(speed_x*time, speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)>=1000){
            left=0;
        }
    }
    if(left==0){
        setTextureRect(prawy);
        move(-speed_x*time, -speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)<=-100){
            left=1;

        }
    }
}
void samolot_soj::moving(sf::Time elapsed){
    float time=elapsed.asSeconds();
    if(left==1){
        setTextureRect(lewy);
        move(speed_x*time, speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)>=1000){
            left=0;
        }
    }
    if(left==0){
        setTextureRect(prawy);
        move(-speed_x*time, -speed_y*time);
        if((getGlobalBounds().width+getGlobalBounds().left)<=-100){
            left=1;

        }
    }

}


samolot_soj :: samolot_soj(sf::Texture &tekstura, int x, int y, float speedx, float speedy, sf::IntRect lewy_,sf::IntRect prawy_){
    lewy=lewy_;
    prawy=prawy_;
    speed_x = speedx;
    speed_y = speedy;
    setPosition(x, y);
    left=1;
    setTexture(tekstura);
    setTextureRect(lewy);

}

bron :: bron(sf::Texture &tekstura, int x, int y){
    setPosition(x, y);
    setTexture(tekstura);
    setScale({0.2,0.2});
}

tlo :: tlo(sf::Texture &tekstura, int x, int y){
    setPosition(x, y);
    setTexture(tekstura);
}

serca :: serca(sf::Texture &tekstura, int x, int y){
    setPosition(x, y);
    setTexture(tekstura);
    setScale({2,2});
}
void serca::moving(){
    if(zycia==2) setTextureRect({0, 0, 32, 15});
    if(zycia==1) setTextureRect({0, 0, 15, 15});
}
int serca::get_serca(){return zycia;}
void serca::odejmij(){zycia-=1;}

bool sortbysec(const std::pair<std::string,int> &a,const std::pair<std::string,int> &b)
{
    return (a.second < b.second);
}
