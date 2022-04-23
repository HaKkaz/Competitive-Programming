#include "../include/Character.hpp"
// Character(){};
Character::Character(string _NAME , string _TYPE , int _ATK , int _DEF , int _HP_MAX , int _MP_MAX , string _DERIVE)
:NAME(_NAME) , TYPE(_TYPE) , ATK(_ATK) , DEF(_DEF) , HP_MAX(_HP_MAX) , MP_MAX(_MP_MAX)
 , HP_CUR(_HP_MAX) ,MP_CUR(_MP_MAX) , DERIVE(_DERIVE){}


void Character::SHOW_DETAIL(){
    cout << "Name : " << get_NAME() << endl;
    cout << "Type : " << get_TYPE() << endl;
    cout << "HP : " << get_HP_CUR() << " / " << get_HP_MAX() << endl;
    cout << "MP : " << get_MP_CUR() << " / " << get_MP_MAX() << endl;
    cout << "ATK/DEF : " << get_ATK() << " / " << get_DEF() << endl;
    cout << "DERIVE : " << get_DERIVE() << endl;
}


//GET functions
string Character::get_NAME(){
    return NAME;
}
string Character::get_TYPE(){
    return TYPE;
}
string Character::get_DERIVE(){
    return DERIVE;
}
int Character::get_ATK(){
    return ATK;
}
int Character::get_DEF(){
    return DEF;
}
int Character::get_HP_MAX(){
    return HP_MAX;
}
int Character::get_MP_MAX(){
    return MP_MAX;
}
int Character::get_HP_CUR(){
    return HP_CUR;
}
int Character::get_MP_CUR(){
    return MP_CUR;
}

//set functions
void Character::set_ATK(int atk){
    ATK = atk;
}

void Character::set_DEF(int def){
    DEF = def;
}

void Character::set_HP_CUR(int HP_NEW){
    HP_CUR = max(0,HP_NEW);
}
void Character::set_MP_CUR(int MP_NEW){
    MP_CUR = max(0,MP_NEW);
}

void Character::set_HP_MAX(int hp){
    HP_MAX = hp;
}

void Character::set_MP_MAX(int mp){
    MP_MAX = mp;
}
