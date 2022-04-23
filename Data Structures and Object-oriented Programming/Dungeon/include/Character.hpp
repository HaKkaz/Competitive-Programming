#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <iostream>

using namespace std;

class Character
{
private:
    string NAME , TYPE;
    int ATK , DEF;
    int HP_MAX , MP_MAX;
    int HP_CUR , MP_CUR;
    string DERIVE;

public:
    // Character();
    Character(string,string,int,int,int,int,string);

    //show functions
    virtual void SHOW_DETAIL();


    //get functions
    string get_NAME();
    string get_TYPE();
    string get_DERIVE();
    int get_ATK();
    int get_DEF();
    int get_HP_MAX();
    int get_MP_MAX();
    int get_HP_CUR();
    int get_MP_CUR();

    //set functions
    void set_ATK(int);
    void set_DEF(int);
    void set_HP_CUR(int);
    void set_MP_CUR(int);
    void set_HP_MAX(int);
    void set_MP_MAX(int);
};


#endif // CHARACTER_HPP_INCLUDED