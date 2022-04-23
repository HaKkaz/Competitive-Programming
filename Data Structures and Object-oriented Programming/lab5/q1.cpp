#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room;
    Room *right_room;
    int index;
  //add constructor or functions if you need
    Room(const int &idx):left_room(nullptr) , right_room(nullptr) , index(idx){}
    Room():left_room(nullptr) , right_room(nullptr) , index(-1){}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n ;
    Room *cur = nullptr , *root = nullptr;
    for(int i=0 ; i<n ; ++i){
        int idx ; cin >> idx;
        if(i == 0){
            cur = new Room(idx);
            root = cur;
        }
        else{
            cur->right_room = new Room(idx);
            cur->right_room->left_room = cur;
            cur = cur->right_room;
        }
    }
    int step; cin >> step;
    cur = root;
    cout << cur->index << ' ' ;
    while(step--){
        char dir ;
        cin >> dir;
        if(dir == 'l'){
            if(cur->left_room == nullptr) cout << -1 << ' ' ;
            else{
                cur = cur->left_room;
                cout << cur->index << ' ' ;
            }
        }
        if(dir == 'r'){
            if(cur->right_room == nullptr) cout << -1 << ' ' ;
            else{
                cur = cur->right_room;
                cout << cur->index << ' ' ;
            }
        }
    }
    return 0;
}