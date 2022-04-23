#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
#include "../include/Room.hpp"
#include "../include/Character.hpp"
#include "../include/Item.hpp"
#include "../include/Pokemon.hpp"

using namespace std;

class Player: public Character
{
    private:
        int MONEY;
        vector< Item* > Potions;
        vector< Item* > Equips;
        vector< Item* > Keys;
        vector< Pokemon* > pokemons;
        Room *cur_room; 
        Item *body,*head,*hand;
    public:
        // Player();
        Player(string,string,int,int,int,int);

        //get functions
        int get_MONEY();
        Room* get_cur_room();
        vector< Item* > get_Potions();
        vector< Item* > get_Equips();
        vector< Item* > get_Keys();
        
        //SHOW functions
        void SHOW_DETAIL();
        void SHOW_POKEMONS();
        void SHOW_PACK();


        //set functions
        void set_cur_room(Room*);
        void set_new_pokemons(Pokemon*);
        void set_new_Potions(Item*);
        void set_new_Equips(Item*);
        void set_new_Keys(Item*);
        void set_new_item(Item*);
        void set_MONEY(int);
        void put_off_equip(Item*);
        void put_on_equip(Item* , int);
        void use_potion(Item* , int);
};
#endif // PLAYER_H_INCLUDED