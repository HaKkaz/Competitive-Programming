#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
const int maxn = 1e5+500;
struct T
{
	T *lst , *nxt;
	string name;
	T(){lst = nxt = nullptr;}
	T(string _name):name(_name){lst = nxt = nullptr;}
}*tab[maxn];
map<string , T*> pos;
int top = 0;
string FIRST="" , LAST="";
signed main(){
	IOS;
	string opt;
	while(cin >> opt){

		if(opt == "SHOW"){
			T *now = pos[FIRST];
			while(now != nullptr){
				cout << now->name << ' ';
				now = now->nxt;
			}
			endl
			exit(0);
			/*
			endl
			for(auto &c : pos){
				debug(c.S->name);
				if(c.S->nxt != nullptr) debug(c.S->nxt->name);
			}
			exit(0);*/
		}
		if(opt == "ADD"){
			string X; cin >> X;
			tab[top] = new T(X);
			pos[X] = tab[top];
			if(LAST == ""){
				FIRST = LAST = X;
				top++;
				continue;
			}
			T *&posLAST = pos[LAST];
			posLAST->nxt = tab[top];
			tab[top]->lst = posLAST;
			LAST = X;
			top++;
		}
		if(opt == "INSERT"){
			string X , N; cin >> X >> N;
			if(N == FIRST) FIRST = X;
			T *&posN = pos[N];
			T *&lstN = posN->lst;
			tab[top] = new T(X);
			pos[X] = tab[top];
			if(lstN != nullptr){
				lstN->nxt = tab[top];
				tab[top]->lst = lstN;
			}
			posN->lst = tab[top];
			tab[top]->nxt = posN;
			top++;
			// debug(pos[X]->nxt->name);
			// debug(pos[N]->lst->name);
			// debug(FIRST) ;
			// debug(LAST);
		}
		if(opt == "REMOVE"){
			string X; cin >> X;
			T *&posX = pos[X];
			T *&nxtX = posX->nxt;
			T *&lstX = posX->lst;
			if(X == FIRST){
				if(posX->nxt != nullptr) FIRST = posX->nxt->name;
				else FIRST = "";
			}
			if(nxtX == nullptr && lstX == nullptr) ;
			if(nxtX == nullptr && lstX != nullptr) lstX->nxt = nullptr;
			if(nxtX != nullptr && lstX == nullptr) nxtX->lst = nullptr;
			if(nxtX != nullptr && lstX != nullptr){
				nxtX->lst = lstX;
				lstX->nxt = nxtX;
			}
			pos.erase(X);
		}
	}
}