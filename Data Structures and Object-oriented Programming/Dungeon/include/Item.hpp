#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
private:
    string NAME;
    char TYPE; // Potion(P), Equipment(E), Key(K)
    int HP,MP,ATK,DEF,PRICE;
    string PART; // Body, Head, Hand
public:
    Item();
    Item(string, char, int, int, int, int, int , string);

    //GET functions
    string get_NAME();
    char get_TYPE();
    int get_HP();
    int get_MP();
    int get_ATK();
    int get_DEF();
    int get_PRICE();
    string get_PART();
    void SHOW_DETAIL();
    void SHOW_Key();
    void SHOW_Equip();
    void SHOW_Potion();
};

#endif // ITEM_H_INCLUDED
