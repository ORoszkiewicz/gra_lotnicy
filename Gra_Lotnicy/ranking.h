#ifndef RANKING_H
#define RANKING_H
#include <obiekt.h>

std::vector<std::pair<std::string,int>> otwieranie_rankingu();

std::vector<std::string> uzupelnianie_rankingu(std::vector<std::pair<std::string,int>> &ranking);

std::vector<sf::Text> tworzenie_tekstu(std::vector<std::string> &uzupelnianie_rankingu, sf::Font &MyFont);

void zapisywanie(std::string imie, int ilosc_punktow);

#endif // RANKING_H

