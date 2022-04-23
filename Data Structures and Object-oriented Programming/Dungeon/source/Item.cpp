#include "../include/Item.hpp"

Item::Item(){}

Item::Item(string _NAME , char _TYPE , int _HP , int _MP , int _ATK , int _DEF , int _PRICE , string _PART)
:NAME(_NAME) , TYPE(_TYPE) , HP(_HP) , MP(_MP) , ATK(_ATK) , DEF(_DEF) , PRICE(_PRICE) , PART(_PART){}

//get functions
string Item::get_NAME(){
	return NAME;
}
char Item::get_TYPE(){
	return TYPE;
}
int Item::get_HP(){
	return HP;
}
int Item::get_MP(){
	return MP;
}
int Item::get_ATK(){
	return ATK;
}
int Item::get_DEF(){
	return DEF;
}
int Item::get_PRICE(){
	return PRICE;
}
string Item::get_PART(){
	return PART;
}


//show functions
void Item::SHOW_DETAIL(){
	if(TYPE == 'E') SHOW_Equip();
	if(TYPE == 'K') SHOW_Key();
	if(TYPE == 'P') SHOW_Potion();
}

void Item::SHOW_Key(){
	cout << "----------------------" << endl;
	cout << "    " << "Item NAME : " << get_NAME() << endl;
	cout << "    " << "Price : $" << get_PRICE() << endl;
	cout << "----------------------" << endl;
}

void Item::SHOW_Equip(){
	cout << "----------------------" << endl;
	cout << "    " << "Item NAME : " << get_NAME() << endl;
	cout << "    " << "+ " << get_HP() << "HP" << endl;
	cout << "    " << "+ " << get_MP() << "MP" << endl;
	cout << "    " << "+ " << get_ATK() << "ATK" << endl;
	cout << "    " << "+ " << get_DEF() << "DEF" << endl;
	cout << "    " << "Equip Part : " << get_PART() << endl;
	cout << "    " << "Price : $" << get_PRICE() << endl;
	cout << "----------------------" << endl;
}

void Item::SHOW_Potion(){
	cout << "----------------------" << endl;
	cout << "    " << "Item NAME : " << get_NAME() << endl;
	cout << "    " << "+ " << get_HP() << "HP" << endl;
	cout << "    " << "+ " << get_MP() << "MP" << endl;
	cout << "    " << "Price : $" << get_PRICE() << endl;
	cout << "----------------------" << endl;
}