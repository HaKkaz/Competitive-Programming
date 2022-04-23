#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.hpp"
#include "Room.hpp"
#include "NPC.hpp"

using namespace std;

class Dungeon{
private:
    Player* player;
    // vector<Room> rooms;
public:
    Dungeon();

    //Dungeon Actions
    void GameLogo();
    void createMap();
    void createPlayer();
    void startGame(){
        GameLogo();
        createPlayer();
        createMap();
        this -> player -> SHOW_DETAIL();
        runDungeon();
    }
    void runDungeon();
    bool Finish_Game();
    void GameFinishLogo();

    //Player Actions
    bool IsAlive();
    void chooseAction();
    void PlayerAction();
    bool PlayerGoBack();
    bool PlayerMove();
    bool PlayerStatusCheck();
    bool PlayerPackCheck();
    bool PlayerPokemonCheck();
    bool PlayerTalkNPC(NPC*);
    bool PlayerBattlePokemon(Pokemon*);
    void Battle(Pokemon*);
    Room* Current_Room();

    //Other Actions
    void NPC_Action(NPC*);
    void Pokemon_Action(Pokemon*);
    void EnterRoom(Room*);
    void set_Current_Room(Room*);
    int Check_Multiplier(const string& , const string&);
};


#endif // DUNGEON_H_INCLUDED

