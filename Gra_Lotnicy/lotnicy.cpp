#include <balon_soj.h>
#include <balon_wr.h>
#include <bron.h>
#include <obiekt.h>
#include <samolot_soj.h>
#include <samolot_wr.h>
#include <serca.h>
#include <tlo.h>
#include <ranking.h>

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

std::vector<std::pair<std::string,int>> otwieranie_rankingu(){
    std::ifstream file_open;
    file_open.open("punkty.txt", std::ios::in);
    if(!file_open.is_open())std::cout<<"Nie otwarto pliku"<<std::endl;
    std::vector<std::pair<std::string, int>> ranking;
    std::string napis_;
        while (!file_open.eof())
        {
            std::getline(file_open, napis_);
            for (int i = 0; i <= napis_.length(); i++)
            {
                if (napis_[i] == ' '){
                    std::string imie = napis_.substr(0, i);
                    std::string punktu = napis_.substr(i + 1);
                    ranking.push_back({imie,std::stoi(punktu)});
                }
            }
        }
        sort(ranking.begin(), ranking.end(),sortbysec);
        return ranking;
}

std::vector<std::string> uzupelnianie_rankingu(std::vector<std::pair<std::string,int>> &ranking){
    std::vector<std::string> temp;
    std::string position_1=ranking[ranking.size()-1].first+"             "+std::to_string(ranking[ranking.size()-1].second);
    std::string position_2=ranking[ranking.size()-2].first+"             "+std::to_string(ranking[ranking.size()-2].second);
    std::string position_3=ranking[ranking.size()-3].first+"             "+std::to_string(ranking[ranking.size()-3].second);
    std::string position_4=ranking[ranking.size()-4].first+"             "+std::to_string(ranking[ranking.size()-4].second);
    std::string position_5=ranking[ranking.size()-5].first+"             "+std::to_string(ranking[ranking.size()-5].second);
    temp.push_back(position_1);
    temp.push_back(position_2);
    temp.push_back(position_3);
    temp.push_back(position_4);
    temp.push_back(position_5);
    return temp;
}

std::vector<sf::Text> tworzenie_tekstu(std::vector<std::string> &uzupelnianie_rankingu, sf::Font &MyFont){
    std::vector<sf::Text> teksty;
    int i=100;
    for(auto &a:uzupelnianie_rankingu){
        sf::Text temp(a, MyFont) ;
                temp.setFillColor({0,0,0});
                temp.setPosition(250,i);
                i=i+50;
                teksty.push_back(std::move(temp));
    }
    sf::Text rankingg("Top 5 Graczy:", MyFont);
    rankingg.setFillColor({2,1,3});
    rankingg.setPosition(250,50);
    teksty.push_back(std::move(rankingg));
    return teksty;
}

void zapisywanie(std::string imie, int ilosc_punktow){
    std::ofstream file;
    file.open("punkty.txt", std::ios::out| std::ios::app);
    if(!file.is_open())std::cout<<"Nie otwarto pliku"<<std::endl;
    file<<imie<<" "<<ilosc_punktow<<std::endl;
}
