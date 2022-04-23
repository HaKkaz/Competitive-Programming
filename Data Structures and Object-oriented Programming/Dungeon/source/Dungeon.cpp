#include "../include/Dungeon.hpp"
#include "../include/Pokemon.hpp"
#include <stdlib.h>
#include <assert.h>

Dungeon::Dungeon():player(nullptr){}

//game logo
//Generate by 'https://patorjk.com/software/taag'.
void Dungeon::GameLogo(){
	cout << "________                 ________                      " 		<< endl;
	cout << "\\______ \\  __ __  ____  /  _____/  ____  ____   ____   " 	<< endl;
	cout << " |    |  \\|  |  \\/    \\/   \\  ____/ __ \\/  _ \\ /    \\  "<< endl;
	cout << " |    `   \\  |  /   |  \\    \\_\\  \\  ___(  <_> )   |  \\ " << endl;
	cout << "/_______  /____/|___|  /\\______  /\\___  >____/|___|  / " 	<< endl;
	cout << "        \\/           \\/        \\/     \\/           \\/  " 	<< endl;
}


//Room Operations
Room* Dungeon::Current_Room(){
	return (player) -> get_cur_room();
}


void Dungeon::set_Current_Room(Room* room){
	(player) -> set_cur_room(room);
}

//build map
void Dungeon::createMap(){
	//Items
	Item Useless_Sword = Item("Useless  Sword" , 'E' , 50 , 50 , 20 , 20 , 0 , "Hand");
	Item Strong_Sword = Item("Strong Sword" , 'E' , 0 , 0 , 100 , 100 , 400 , "Hand");
	Item Fire_Tank = Item("Fire Tank" , 'E' , 200, 200, 0, 500, 50, "Body");
	Item Finish_key = Item("Finish Key" , 'K' , 0,0,0,0,200 , "None");
	Item Small_HP_Potion = Item("Small HP Potion" , 'P' , 50, 0, 0, 0, 0, "None");

	//Monsters
	Character* Pokemon_Fire	= new Pokemon("Rocket Turtle", "Fire"	, 120  , 5  , 100 , 50 , 50);
	Character* Pokemon_Grass	= new Pokemon("GG Monkey" 	 , "Grass" 	, 140 , 20 , 150 , 100 , 200);
	Character* Pokemon_Water	= new Pokemon("Gawr Gura" 		 , "Water" 	, 140 , 20 , 150 , 100 , 200);
	Character* Pokemon_Boss1	= new Pokemon("Gawr Gura" 		 , "Water" 	, 140 , 20 , 150 , 100 , 200);
	Character* Pokemon_Boss2	= new Pokemon("Gawr Gura" 		 , "Water" 	, 140 , 20 , 150 , 100 , 200);
	Character* Pokemon_Boss3	= new Pokemon("Gawr Gura" 		 , "Water" 	, 140 , 20 , 150 , 100 , 200);
	Character* Pokemon_Boss4	= new Pokemon("Gawr Gura" 		 , "Water" 	, 140 , 20 , 150 , 100 , 200);
	auto empty_vector = vector<Character*>();

	//NPCs
	Character* NPC_0 = static_cast<Character*>( new NPC("Ken" , "Water" , 10000 , 10000 , 10000 , 10000 , vector<Item>{ Useless_Sword} ,
						"Give you a sword, bro! Good luck~"));
	Character* NPC_1 = static_cast<Character*>( new NPC("Lawrence" , "Normal" , 1000 , 1000 , 10 , 10 , vector<Item>{ Strong_Sword , Small_HP_Potion } ,
						"Hey! I have a good item for you."));
	Character* NPC_2 = static_cast<Character*>( new NPC("Horo" , "Normal" , 0 , 10 , 10 , 10 , vector<Item>{ Strong_Sword , Finish_key , Small_HP_Potion } , 
						"I think Finish is nearby me."));
	Character* NPC_3 = static_cast<Character*>( new NPC("Fire Controller" , "Fire" ,  10000 , 10000 , 10000 , 10000 , vector<Item>{ Fire_Tank } , 
						"Give you a best equip! You are so WEAK. Pay me $50."));

	//create rooms
	Room *Start_Room 	= 	new Room("Start Room"		,vector<Character*>{NPC_0});
	Room *Monster1 		= 	new Room("Monster Room"		,vector<Character*>{Pokemon_Fire});
	Room *NPC1 			= 	new Room("NPC Room1"		,vector<Character*>{NPC_1});
	Room *NPC2 			=	new Room("NPC Room2"		,vector<Character*>{NPC_2});
	Room *Monster_Grass = 	new Room("Fight Room Left"	,vector<Character*>{Pokemon_Grass});
	Room *Monster_Water = 	new Room("Fight Room Right"	,vector<Character*>{Pokemon_Water});
	Room *Rest_Room 	= 	new Room("Rest Room"		,vector<Character*>{NPC_3});
	Room *Boss_Room1 	= 	new Room("Boss Room1"		,vector<Character*>{Pokemon_Boss1});
	Room *Boss_Room2 	= 	new Room("Boss Room2"		,vector<Character*>{Pokemon_Boss2});
	Room *Boss_Room3 	= 	new Room("Boss Room3"		,vector<Character*>{Pokemon_Boss3});
	Room *Boss_Room4 	= 	new Room("Boss Room4"		,vector<Character*>{Pokemon_Boss4});
	Room *Finish_Room 	= 	new Room("Finish Room"		,vector<Character*>());


	//connect rooms
	Start_Room	 ->	connect_room(Monster1)			,	Monster1 	 -> connect_room(Start_Room);
	Monster1	 ->	connect_room(NPC1)				,	NPC1		 ->	connect_room(Monster1);
	Monster1	 ->	connect_room(NPC2)				,	NPC2	 	 -> connect_room(Monster1);
	NPC1		 ->	connect_room(Monster_Grass)		,	Monster_Grass->	connect_room(NPC1);
	NPC2		 ->	connect_room(Monster_Water)		,	Monster_Water-> connect_room(NPC2);
	Monster_Grass->	connect_room(Rest_Room)			,	Rest_Room	 -> connect_room(Monster_Grass);
	Monster_Grass->	connect_room(Boss_Room3)		,	Boss_Room3	 -> connect_room(Monster_Grass);
	Monster_Water-> connect_room(Rest_Room)			,	Rest_Room	 -> connect_room(Monster_Water);
	Monster_Water-> connect_room(Boss_Room4)		,	Boss_Room4	 -> connect_room(Monster_Water);
	Rest_Room	 ->	connect_room(Boss_Room1)		,	Boss_Room1	 -> connect_room(Rest_Room);
	Boss_Room1	 -> connect_room(Boss_Room2)		,	Boss_Room2	 -> connect_room(Boss_Room1);
	Boss_Room1	 -> connect_room(Boss_Room3)		,	Boss_Room3	 -> connect_room(Boss_Room1);
	Boss_Room1	 -> connect_room(Boss_Room4)		,	Boss_Room4	 -> connect_room(Boss_Room1);
	Boss_Room2	 -> connect_room(Finish_Room);
	Boss_Room3	 -> connect_room(Finish_Room);
	Boss_Room4	 -> connect_room(Finish_Room);

	//Player location
	(player) -> set_cur_room(Start_Room);
}

//Player operations
void Dungeon::createPlayer(){
	cout << "Please Input your name : ";
	string Player_Name;
	getline(cin , Player_Name);
	player = new Player(Player_Name,"FIRE",100,100,50,50);
}

bool Dungeon::IsAlive(){
    return (player) -> get_HP_CUR() > 0;
}

bool Dungeon::Finish_Game(){
	return !IsAlive() or Current_Room() -> get_NAME() == "Finish Room";
}

void Dungeon::NPC_Action(NPC *npc){
	npc -> script();
}

void Dungeon::Pokemon_Action(Pokemon *pokemon){
	cout << pokemon->get_NAME() << " shout at you !!" << endl;
}


void Dungeon::EnterRoom(Room* room){
	vector< Character* > characters = room -> get_characters();
	for(Character* ch_iter: characters){
		if(ch_iter -> get_DERIVE() == "NPC"){
			NPC* npc = dynamic_cast<NPC*>(ch_iter);
			NPC_Action(npc);
		}
		if(ch_iter -> get_DERIVE() == "Pokemon"){
			Pokemon* pokemon = dynamic_cast<Pokemon*>(ch_iter);
			Pokemon_Action(pokemon);
			cout << "This Room has a pokemon. You have to beat the pokemon before you leave this room." << endl;
		}
	}
}

void Dungeon::PlayerAction(){
	bool have_NPC = false;
	bool have_Pokemon = false;
	Pokemon *pokemon = nullptr;
	NPC *npc = nullptr;

	for(auto &ch_it : (Current_Room() -> get_characters())){
		if(ch_it -> get_DERIVE() == "NPC") have_NPC = true , npc = dynamic_cast<NPC*>(ch_it);
		if(ch_it -> get_DERIVE() == "Pokemon") have_Pokemon = true , pokemon = dynamic_cast<Pokemon*>(ch_it);
	}



	bool done = false;
	while(!done){
		cout << "What do you want to do now?" << endl;
		cout << "-------------------------" << endl;
		if(have_Pokemon==0) cout << "(M)ove." << endl;
		cout << "(S)tatus check." << endl;
		cout << "(P)ack check." << endl;
		cout << "(C)ollected pokemon Check." << endl;
		if(have_NPC) cout << "(T)alk with NPC." << endl;
		if(have_Pokemon) cout << "(B)attle with Pokemon." << endl;
		cout << "-------------------------" << endl;
		string input;
		cin >> input;
		cout << "-------------------------" << endl;
		if(!have_Pokemon && input == "M"){
			done |= PlayerMove();
		}
		else if(input == "S"){
			done |= PlayerStatusCheck();
		}
		else if(input == "P"){
			done |= PlayerPackCheck();
		}
		else if(input == "C"){
			done |= PlayerPokemonCheck();
		}
		else if(have_NPC && input == "T"){
			done |= PlayerTalkNPC(npc);
		}
		else if(input == "B"){
			done |= PlayerBattlePokemon(pokemon);
		}
		else{
			cout << "Nothing happened......." << endl;
			cout << "Please enter the action again !!" << endl;
		}

		//player dead
		if(!IsAlive()){
			cout << "You Dead, GAME OVER !" << endl;
			exit(0);
		}
	}

}


bool Dungeon::PlayerMove(){
	cout << "you have several options about move :" << endl;
	auto Neighbor_Rooms = Current_Room() -> get_neighbors();
	for(int i=0 ; i < (int)Neighbor_Rooms.size() ; ++i){
		cout << '(' << i << ')' << " Go to " << Neighbor_Rooms[i]->get_NAME() << endl;
	}
	cout << "Or you want to back to previous options, then Enter '9'.";
	cout << "Enter number " << 0 << "~" <<Neighbor_Rooms.size()-1  << " of Your Choice" << endl;
	cout << "-------------------------------" << endl;

	int id;
	cin >> id;

	
	if(id == 9){//back to previous options
		return false;
	}
	else{//go to id room
		set_Current_Room(Neighbor_Rooms[id]);
		player -> SHOW_DETAIL();
		return true;
	}
}


bool Dungeon::PlayerStatusCheck(){
//Player Status Check
cout << " ________  _________  ________  _________  ___  ___  ________      " << endl;
cout << "|\\   ____\\|\\___   ___\\\\   __  \\|\\___   ___\\\\  \\|\\  \\|\\   ____\\     " << endl;
cout << "\\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\\\\\  \\ \\  \\___|_    " << endl;
cout << " \\ \\_____  \\   \\ \\  \\ \\ \\   __  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\_____  \\   " << endl;
cout << "  \\|____|\\  \\   \\ \\  \\ \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\\\\\  \\|____|\\  \\  " << endl;
cout << "    ____\\_\\  \\   \\ \\__\\ \\ \\__\\ \\__\\   \\ \\__\\ \\ \\_______\\____\\_\\  \\ " << endl;
cout << "   |\\_________\\   \\|__|  \\|__|\\|__|    \\|__|  \\|_______|\\_________\\" << endl;
cout << "   \\|_________|                                        \\|_________|" << endl;                                                                                                                
	player -> SHOW_DETAIL();
	return true;
}

bool Dungeon::PlayerPackCheck(){
//Player Pack Check
cout << "------------------------------------------------------------------------" << endl;
cout << " ________  ________  ________  ___  __            ________  ___  ___  _______   ________  ___  __       " << endl;
cout << "|\\   __  \\|\\   __  \\|\\   ____\\|\\  \\|\\  \\         |\\   ____\\|\\  \\|\\  \\|\\  ___ \\ |\\   ____\\|\\  \\|\\  \\     " << endl;
cout << "\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|_       \\ \\  \\___|\\ \\  \\\\\\  \\ \\   __/|\\ \\  \\___|\\ \\  \\/  /|_   " << endl;
cout << " \\ \\   ____\\ \\   __  \\ \\  \\    \\ \\   ___  \\       \\ \\  \\    \\ \\   __  \\ \\  \\_|/_\\ \\  \\    \\ \\   ___  \\  " << endl;
cout << "  \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\       \\ \\  \\____\\ \\  \\ \\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\\\ \\  \\ " << endl;
cout << "   \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\       \\ \\_______\\ \\__\\ \\__\\ \\_______\\ \\_______\\ \\__\\\\ \\__\\" << endl;
cout << "    \\|__|     \\|__|\\|__|\\|_______|\\|__| \\|__|        \\|_______|\\|__|\\|__|\\|_______|\\|_______|\\|__| \\|__|" << endl;
cout << "------------------------------------------------------------------------" << endl;
	player -> SHOW_PACK();
	return true;
}

bool Dungeon::PlayerPokemonCheck(){
//Collected Pokemon Check
cout << "--------------------------------------------------------" << endl;
cout << " ____   ___   __  _    ___  ___ ___   ___   ____   _____" << endl;
cout << "|    \\ /   \\ |  |/ ]  /  _]|   |   | /   \\ |    \\ / ___/" << endl;
cout << "|  o  )     ||  ' /  /  [_ | _   _ ||     ||  _  (   \\_ " << endl;
cout << "|   _/|  O  ||    \\ |    _]|  \\_/  ||  O  ||  |  |\\__  |" << endl;
cout << "|  |  |     ||     \\|   [_ |   |   ||     ||  |  |/  \\ |" << endl;
cout << "|  |  |     ||  .  ||     ||   |   ||     ||  |  |\\    |" << endl;
cout << "|__|   \\___/ |__|\\_||_____||___|___| \\___/ |__|__| \\___|" << endl;
cout << "--------------------------------------------------------" << endl;
	player -> SHOW_POKEMONS();
	return true;                                                        
}

bool Dungeon::PlayerTalkNPC(NPC *npc){
	cout << "---------------------------------------------------------" << endl;
	cout << "I have these commodities : " << endl;
	auto commodities = npc->get_commodities();
	for(auto &commodity : commodities){
		commodity.SHOW_DETAIL();
	}
	cout << "---------------------------------------------------------" << endl;
	cout << endl;
	cout << "Do you want to buy something? Enter the index." << endl;
	int idx=0;
	for(auto &commodity : commodities){
		cout << '(' << idx++ << ')' << ' ' << commodity.get_NAME() << endl;
	}
	while(true){
		cout << "You have $" << player->get_MONEY() << endl;
		string input; cin >> input;
		if(input.size() == 1 && (input[0]-'0')<(int)commodities.size()){
			int need_money = commodities[input[0]-'0'].get_PRICE();
			int have_money = player->get_MONEY();
			if(have_money >= need_money){
				cout << "You get " + commodities[input[0]-'0'].get_NAME() + "!" << endl;
				player->set_MONEY(have_money - need_money);
				Item buy = commodities[input[0]-'0'];
				Item *new_item = new Item(buy.get_NAME() , buy.get_TYPE() , buy.get_HP() , buy.get_MP() , 
															buy.get_ATK() , buy.get_DEF() , buy.get_PRICE() , buy.get_PART());
				player -> set_new_item(new_item);
			}
			else{
				cout << "Give me MORE MONEY!!" << endl;
			}
			break;
		}
		else{
			cout << "Enter the commodities index.";
		}
	}
	return true;
}

int Dungeon::Check_Multiplier(const string &T1 , const string &T2){
	if(T1 == "Grass" and T2 == "Water") return 2;
	if(T1 == "Water" and T2 == "Fire" ) return 2;
	if(T1 == "Fire"  and T2 == "Grass") return 2;
	if(T1 == "Light" and T2 == "Dark" ) return 2;
	if(T1 == "Dark"  and T2 == "Light") return 2;
	return 1;
}

void Dungeon::Battle(Pokemon *pokemon){
	srand(time(0));
	//Battle Start
	cout << "------------------------------------------------------------------------" << endl;
	cout << "________       ________________                _____              _____ " << endl;
	cout << "___  __ )_____ __  /__  /___  /____     _________  /______ _________  /_" << endl;
	cout << "__  __  |  __ `/  __/  __/_  /_  _ \\    __  ___/  __/  __ `/_  ___/  __/" << endl;
	cout << "_  /_/ // /_/ // /_ / /_ _  / /  __/    _(__  )/ /_ / /_/ /_  /   / /_  " << endl;
	cout << "/_____/ \\__,_/ \\__/ \\__/ /_/  \\___/     /____/ \\__/ \\__,_/ /_/    \\__/  " << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while(IsAlive() and (pokemon -> get_HP_CUR() > 0)){
		/* If player and pokemon both alive, battle continue. */
		cout << double(pokemon->get_HP_MAX()-pokemon->get_HP_CUR()) << '/' << pokemon->get_HP_MAX() << endl;
		int catch_rate = double(pokemon->get_HP_MAX()-pokemon->get_HP_CUR())/pokemon->get_HP_MAX()*100;
		cout << pokemon -> get_HP_CUR() << " / " << pokemon -> get_HP_MAX() << endl;
		assert(catch_rate >= 0 && catch_rate <= 100);
		cout << "Battling, What do you want to do?" << endl;
		cout << "(F)ight : Choose fight skill to attack pokemon." << endl;
		cout << "(C)atch : Use pokemon ball to catch pokemon. (Successful rate : " << catch_rate << ')' << '%' << endl;
		cout << "(S)tatus : Check your status." << endl;
		cout << "(R)un : Escape the Battle. (Successful rate : 33%)" << endl;
		string opt_player; cin >> opt_player;
		//player actions
		if(opt_player == "F"){
			while(true){
				cout << "(H)it : The damage is (your ATK) - (enemy DEF). Cost 0 MP." << endl;
				if((player) -> get_MP_CUR() >= 10){
					cout << "(K)ick : The damage is (your ATK*2 - (enemy DEF). Cost 10 MP.)" << endl;
				}
				string fight; cin >> fight;
				int Multiplier = Check_Multiplier(player->get_TYPE() , pokemon->get_TYPE());
				cout << "------------------------------------------------------------------------" << endl;
				if(fight == "H"){
					cout << "You hit " << pokemon->get_NAME() << "." << endl;
					if(Multiplier == 2) cout << "Enemy will take 2x damage from you, because you have counter type." << endl;
					pokemon -> take_damage(player -> get_ATK() * Multiplier);
					break;
				}
				else if (fight == "K"){
					cout << "You kick " << pokemon->get_NAME() << "." << endl;
					pokemon -> take_damage(player -> get_ATK() * 2 * Multiplier);
					player -> set_MP_CUR(player -> get_MP_CUR() - 10);
					break;
				}
				else{
					cout << "Enter 'H' or 'K'." << endl;
				}
				cout << "------------------------------------------------------------------------" << endl;
			}
		}
		else if(opt_player == "C"){
			int seed = rand()%100;
			if(seed <= catch_rate){
				cout << "You catch " << pokemon->get_NAME() << " successfully !!!" << endl;
				pokemon -> set_HP_CUR(0);
				player -> set_new_pokemons(pokemon);
				cout << "enter (P) check your Pokemons! or enter any other words skip." << endl;
				string inp; cin >> inp;
				if(inp == "P"){
					PlayerPokemonCheck();
				}
			}
			else{
				cout << "Catch Fail~" << endl;
			}
		}
		else if(opt_player == "R"){
			int seed = rand()%3;
			if(seed == 1){
				cout << "Escape successfully!" << endl;
			}
			else{
				cout << "Escape Fail ~~~!" << endl;
			}
		}
		else{
			if(opt_player == "S") player -> SHOW_DETAIL();
			else cout << "Please Enter correct options" << endl;
			continue;
		}
		//pokemon actions
		if(pokemon -> get_HP_CUR() > 0){
			int Multiplier = Check_Multiplier(pokemon->get_TYPE() , player->get_TYPE());
			int player_HP = player -> get_HP_CUR();
			int pokemon_ATK = pokemon-> get_ATK() * Multiplier;
			int player_DEF = player -> get_DEF();
			int damage = max(0 , pokemon_ATK - player_DEF); // if damage is negative , set it zero.
			cout << "------------------------------" << endl;
			cout << pokemon->get_NAME() + " hit you! You got " + to_string(damage) + " damage." << endl;
			cout << "------------------------------" << endl;
			player -> set_HP_CUR(player_HP - damage);
		}
	}
	if(pokemon -> get_HP_CUR() == 0){
		//You beat the pokemon.
		Current_Room() -> clear_characters();
		cout << (pokemon -> get_NAME()) + " dead, You win." << endl;
		// cout << "You get $" << pokemon -> get_EXP() << endl;
		cout << "--------------Battle End---------------" << endl;
		return;
	}
}

bool Dungeon::PlayerBattlePokemon(Pokemon *pokemon){
	cout << (pokemon -> get_NAME()) + " shout at you !!!" << endl;
	//debug
	Battle(pokemon);
	//

	return true;
}

void Dungeon::runDungeon(){
	while(!Finish_Game()){
		EnterRoom(player -> get_cur_room());
		PlayerAction();
	}
	GameFinishLogo();
}

void Dungeon::GameFinishLogo(){
	cout <<  "  _____                        ______ _       _     _     " << endl;
	cout <<  " / ____|                      |  ____(_)     (_)   | |    " << endl;
	cout <<  "| |  __  __ _ _ __ ___   ___  | |__   _ _ __  _ ___| |__  " << endl;
	cout <<  "| | |_ |/ _` | '_ ` _ \\ / _ \\ |  __| | | '_ \\| / __| '_ \\ " << endl;
	cout <<  "| |__| | (_| | | | | | |  __/ | |    | | | | | \\__ \\ | | |" << endl;
	cout <<  " \\_____|\\__,_|_| |_| |_|\\___| |_|    |_|_| |_|_|___/_| |_|" << endl;
}