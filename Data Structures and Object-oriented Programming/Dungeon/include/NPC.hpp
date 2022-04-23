#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "../include/Character.hpp"
#include "../include/Player.hpp"
#include "../include/Item.hpp"

using namespace std;

class NPC: public Character
{
private:
    // string script;
    vector<Item> commodities;
    string TALK;
public:
    // NPC();
    NPC(string,string,int,int,int,int,vector<Item>,string);
    /* Set & Get function*/
    // void setScript(string);
    void setCommodities(vector<Item>);
    string getScript();
    vector<Item> get_commodities();
    void script();
};


#endif // NPC_H_INCLUDED
