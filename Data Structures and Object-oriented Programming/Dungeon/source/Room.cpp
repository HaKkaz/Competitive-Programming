#include<../include/Room.hpp>

Room::Room(string _NAME , vector<Character*> _temp):
NAME(_NAME),characters(_temp){}


void Room::connect_room(Room* con){
	neighbors.emplace_back(con);
}

//get functions
string Room::get_NAME(){
	return NAME;
}

vector< Room* > Room::get_neighbors(){
	return neighbors;
}

vector< Character* > Room::get_characters(){
	return characters;
}


//set functions
void Room::clear_characters(){
	characters.clear();
}