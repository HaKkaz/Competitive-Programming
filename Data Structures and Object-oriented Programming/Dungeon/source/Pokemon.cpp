#include "../include/Pokemon.hpp"
#include "../include/Character.hpp"

//constructors
Pokemon::Pokemon(Pokemon &tmp)
:Character(tmp.get_NAME() , tmp.get_TYPE() , tmp.get_ATK() , tmp.get_DEF() , tmp.get_HP_MAX() , tmp.get_MP_MAX() , "Pokemon"),COIN(tmp.get_COIN()){}

Pokemon::Pokemon(string _NAME , string _TYPE , int _ATK , int _DEF , int _HP_MAX , int _MP_MAX , int _COIN)
:Character(_NAME,_TYPE,_ATK,_DEF,_HP_MAX,_MP_MAX,"Pokemon") , COIN(_COIN){}

// get functions
int Pokemon::get_COIN(){
	return COIN;
}



void Pokemon::SHOW_DETAIL(){
    cout << "--------Pokemon Status--------" << endl;
    cout << "Name : " << get_NAME() << endl;
    cout << "Type : " << get_TYPE() << endl;
    cout << "HP : " << get_HP_CUR() << " / " << get_HP_MAX() << endl;
    cout << "MP : " << get_MP_CUR() << " / " << get_MP_MAX() << endl;
    cout << "ATK/DEF : " << get_ATK() << " / " << get_DEF() << endl;
    cout << "---------------------------" << endl;
}

//set functions
void Pokemon::take_damage(int _ATK){
    int hp_cur = get_HP_CUR();
    int dmg = max(0,_ATK - get_DEF());
    set_HP_CUR(hp_cur - dmg);
    cout << get_NAME() + " take " + to_string(dmg) << " damage." << endl;
}

