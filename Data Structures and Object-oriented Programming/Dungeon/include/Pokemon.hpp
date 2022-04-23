#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "../include/Character.hpp"
#include "../include/Item.hpp"

using namespace std;


class Pokemon: public Character
{
private:
    int COIN;
public:
    //constructors
    //NAME , TYPE , ATK , DEF , HP_MAX , MP_MAX
    Pokemon(Pokemon&);
    Pokemon(string,string,int,int,int,int,int);

    //SHOW functions
    virtual void SHOW_DETAIL();

    //GET functions
    int get_COIN();

    //set
    void take_damage(int);
};

#endif // POKEMON_H_INCLUDED