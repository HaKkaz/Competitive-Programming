#include "../include/Player.hpp"
#include "../include/Character.hpp"

Player::Player(string _NAME , string _TYPE , int _ATK , int _DEF , int _HP_MAX , int _MP_MAX)
:Character(_NAME,_TYPE,_ATK,_DEF,_HP_MAX,_MP_MAX,"Player") , MONEY(1000) , cur_room(nullptr){
	body = nullptr;
	head = nullptr;
	hand = nullptr;
}


//get functions
vector< Item* > Player::get_Potions(){
	return Potions;
}
vector< Item* > Player::get_Equips(){
	return Equips;
}
vector< Item* > Player::get_Keys(){
	return Keys;
}

int Player::get_MONEY(){
	return MONEY;
}


Room* Player::get_cur_room(){
	return cur_room;
}

//SHOW functions
void Player::SHOW_DETAIL(){
    cout << "--------Your Status--------" << endl;
    cout << "Name : " << get_NAME() << endl;
    cout << "Type : " << get_TYPE() << endl;
    cout << "HP : " << get_HP_CUR() << " / " << get_HP_MAX() << endl;
    cout << "MP : " << get_MP_CUR() << " / " << get_MP_MAX() << endl;
    cout << "ATK/DEF : " << get_ATK() << " / " << get_DEF() << endl;
    cout << "MONEY : " << get_MONEY() << endl;
    cout << "Location : " << get_cur_room() -> get_NAME() << endl;
    cout << "---------------------------" << endl;
}

void Player::put_off_equip(Item *item){
	Item *temp = nullptr;
	if(item -> get_PART() == "Body" && body){
		Equips.emplace_back(body);
		temp = body;
		body = nullptr;
	}
	if(item -> get_PART() == "Head" && head){
		Equips.emplace_back(head);
		temp = head;
		head = nullptr;
	}
	if(item -> get_PART() == "Hand"  && hand){
		Equips.emplace_back(hand);
		temp = hand;
		hand = nullptr;
	}
	if(temp){
		set_HP_MAX(get_HP_MAX() - temp->get_HP());//-HP
		set_MP_MAX(get_MP_MAX() - temp->get_MP());//-MP
		set_ATK(get_ATK() - temp->get_ATK());//-ATK
		set_DEF(get_DEF() - temp->get_DEF());//-DEF
	}
}

void Player::put_on_equip(Item *item , int id){
	set_HP_MAX(get_HP_MAX() + item->get_HP());//+HP
	set_MP_MAX(get_MP_MAX() + item->get_MP());//+MP
	set_ATK(get_ATK() + item->get_ATK());//+ATK
	set_DEF(get_DEF() + item->get_DEF());//+DEF

	if(item -> get_PART() == "Body"){
		body = item;
	}
	if(item -> get_PART() == "Head"){
		head = item;
	}
	if(item -> get_PART() == "Hand"){
		hand = item;
	}
	set_HP_CUR(min(get_HP_CUR(),get_HP_MAX()));
	set_MP_CUR(min(get_MP_CUR(),get_MP_MAX()));
	Equips.erase(Equips.begin() + id);
}

void Player::use_potion(Item *item , int id){
	int max_hp = get_HP_MAX();
	int cur_hp = get_HP_CUR();
	int max_mp = get_MP_MAX();
	int cur_mp = get_MP_CUR();
	int add_hp = item -> get_HP();
	int add_mp = item -> get_MP();
	set_HP_CUR(min(max_hp , cur_hp + add_hp));
	set_MP_CUR(min(max_mp , cur_mp + add_mp));
	Potions.erase(Potions.begin() + id);
}

void Player::SHOW_PACK(){
	if(Equips.size() + Potions.size() + Keys.size() == 0){
		cout << "You have nothing QQQQQQQ !!!!" << endl;
	}
	else {
		cout << "-------Your Pack------" << endl;
		if(Equips.size()){
			cout << "Your Equips : " << endl;
			for(auto &item : Equips){
				item -> SHOW_Equip();
			}
		}
		if(Potions.size()){
			cout << "Your Potions : " << endl;
			for(auto &item : Potions){
				item -> SHOW_Potion();
			}
		}
		if(Keys.size()){
			cout << "Your Keys : " << endl;
			for(auto &item : Keys){
				item -> SHOW_Key();
			}
		}
		if(Equips.size()){
			
			cout << "Do you want to equip anyone?" << endl;
			cout << "Enter Y or N" << endl;
			string YN; cin >> YN;
			if(YN == "Y"){
				cout << "------------------------------" << endl;
				for(int i=0 ; i<(int)Equips.size() ; ++i){
					cout << "(" + to_string(i) + ")" + Equips[i]->get_NAME() << endl;
				}
				cout << "Which one do you want to equip?" << endl;
				cout << "Enter the id" << endl;
				int id ; cin >> id;
				if(id >= 0 && id <(int)Equips.size()){
					Item *temp = Equips[id];
					put_off_equip(temp);
					put_on_equip(temp , id);
				}
				else{
					cout << "Wrong id!" << endl;
				}
				cout << "------------------------------" << endl;
			}

		}
		if(Potions.size()){
			
			cout << "Do you want to use potions?" << endl;
			cout << "Enter Y or N" << endl;
			string YN; cin >> YN;
			if(YN == "Y"){
				cout << "------------------------------" << endl;
				for(int i=0 ; i<(int)Potions.size() ; ++i){
					cout << "(" + to_string(i) + ")" + Potions[i]->get_NAME() << endl;
				}
				cout << "Which one do you want to use?" << endl;
				cout << "Enter the id" << endl;
				int id ; cin >> id;
				if(id >= 0 && id <(int)Potions.size()){
					Item *temp = Potions[id];
					use_potion(temp , id);
				}
				else{
					cout << "Wrong id!" << endl;
				}
				cout << "------------------------------" << endl;
			}
		}
	}
	
}

void Player::SHOW_POKEMONS(){
	if( (pokemons).size() == 0){
		cout << "You do not have any pokemons." << endl;
	}
	else{
		cout << "-------Your Pokemons------" << endl;
		for(auto &pokemon : pokemons){
			cout << "-----------------------------" << endl;
			pokemon -> SHOW_DETAIL();
		}
	}
	cout << "-----------------------------" << endl;
}

//set functions
void Player::set_cur_room(Room* room){
	cur_room = room;
}

void Player::set_new_pokemons(Pokemon *pokemon){
	pokemons.emplace_back(pokemon);
}

void Player::set_new_Potions(Item *item){
	Potions.emplace_back(item);
}

void Player::set_new_Equips(Item *item){
	Equips.emplace_back(item);
}

void Player::set_new_Keys(Item *item){
	Keys.emplace_back(item);
}

void Player::set_MONEY(int money){
	MONEY = money;
}

void Player::set_new_item(Item *item){
	if(item -> get_TYPE() == 'P'){
		Potions.emplace_back(item);
	}
	else if(item -> get_TYPE() == 'E'){
		Equips.emplace_back(item);
	}
	else if(item -> get_TYPE() == 'K'){
		Keys.emplace_back(item);
	}
	else{
		cout << "Fail push item." << endl;
	}
}