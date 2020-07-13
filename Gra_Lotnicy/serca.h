#ifndef SERCA_H
#define SERCA_H
#include <obiekt.h>

class serca : public obiekt{
    int zycia=3;
public:
    serca(sf::Texture &tekstura, int x, int y);
    int get_serca();
    void odejmij();
    void moving();
};
bool sortbysec(const std::pair<std::string,int> &a,const std::pair<std::string,int> &b) ;

#endif // SERCA_H
