#include "../include/NPC.hpp"
#include "../include/Item.hpp"
#include "../include/Character.hpp"
// NPC::NPC(){};

NPC::NPC(string _NAME , string _TYPE , int _ATK , int _DEF , int _HP_MAX , int _MP_MAX, vector<Item> _commodities,string _TALK)
:Character(_NAME,_TYPE,_ATK,_DEF,_HP_MAX,_MP_MAX,"NPC") , commodities(_commodities) , TALK(_TALK){}



void NPC::setCommodities(vector<Item>){
	cout << "Nothing happend in set commodities" << endl;
}

void NPC::script(){
	cout << get_NAME() << " : " << TALK << endl;
}

vector<Item> NPC::get_commodities(){
	return commodities;
}