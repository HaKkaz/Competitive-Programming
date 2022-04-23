#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include <iostream>
#include <vector>
#include "../include/Character.hpp"

class Room
{
	private:
		string NAME;
		vector<Room*> neighbors;
		vector<Character*> characters;
	public:
		// Room();
		Room(string,vector<Character*>);
		void connect_room(Room*);

		//get functions
		string get_NAME();
		vector< Room* > get_neighbors();
		vector< Character* > get_characters();

		//set functions
		void clear_characters();
};
#endif // ROOM_H_INCLUDED
