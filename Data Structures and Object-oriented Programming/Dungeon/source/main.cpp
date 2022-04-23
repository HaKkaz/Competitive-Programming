#include <iostream>
#include <string>
#include <vector>
#include "../include/Dungeon.hpp"
#include "../include/Item.hpp"
// #include "../include/Monster.hpp"
// #include "../include/NPC.hpp"
#include "../include/Pokemon.hpp"
#include "../include/Character.hpp"


using namespace std;

int main(){
    // Dungeon dungeon = Dungeon();
    // dungeon.runDungeon();
    
    Dungeon game;
    game.startGame();
    if(game.IsAlive()){
        cout << "Choose Action" << endl;
    }
    system("Pause");
    return 0;
}
