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
#define debug(x) cerr << "Debug -> " << #x << " = "  << x << '\n';
using namespace std;
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
struct Time
{
	int Y,M,D,H;
	Time(){Y=M=D=H=0;}
	Time(int _Y , int _M , int _D , int _H ):Y(_Y),M(_M),D(_D),H(_H){};
	bool operator<(const Time &tmp)const{
		if(Y != tmp.Y) return Y < tmp.Y;
		if(M != tmp.M) return M < tmp.M;
		if(D != tmp.D) return D < tmp.D;
		return H < tmp.H;
	}
	bool operator==(const Time &tmp)const{
		return Y == tmp.Y && M == tmp.M && D == tmp.D && H == tmp.H;
	}
};
struct Subject
{
	string name;
	Time tt;
	vector<pair< Time , pair<int,int> >> ID;
	int top;
	Subject(){}
	Subject(Time _tt , int _top):tt(_tt),top(_top){}
	bool operator<(const Subject &tmp)const{
		if(!(tt == tmp.tt)) return tt < tmp.tt;
		return top < tmp.top;
	}
};
map<string,Subject> sub;
set<string> vis;
signed main(){
	IOS;
	string name;
	int cnt = 0;
	while(cin >> name){
		getline(cin , name);
		cnt++;
		int ig=0;
		for(int i=ig ; i<sz(name) ; ++i){
			if(name[i] == ' ') ++ig;
			else break;
		}
		if(name.substr(ig,3) == "RE:" || name.substr(ig,3) == "Re:"){
			ig += 3;
		}
		for(int i=ig ; i<sz(name) ; ++i){
			if(name[i] == ' ') ++ig;
			else break;
		}
		name = name.substr(ig , sz(name)-ig);
		string Date; cin >> Date;
		int M,D,H,Y; cin >> M >> D >> H >> Y;
		string ID; cin >> ID;
		int id ; cin >> id;
		//
		Time now(Y,M,D,H);
		if(vis.find(name) != vis.end()){
			if(now < sub[name].tt) sub[name].tt = now;
			sub[name].name = name;
			sub[name].ID.push_back({now , {cnt,id}});
		}
		else{
			sub[name].name = name;
			sub[name]=Subject(now , cnt);
			sub[name].ID.push_back({now , {cnt,id}});
		}
		vis.insert(name);
		/*debug(name);
		debug(M);
		debug(D);
		debug(H);
		debug(Y);
		debug(id);*/
		sub[name].name = name;
		// debug(sub[name].name);
		// LINE
		// cout << "DEBUG NAME\n";
		// for(auto &c : sub) cout << c.S.name << '\n';
	}
	// LINE
	/*for(auto &c : vis) cout << c << '\n';
	LINE
	int stop=0;
	for(auto &c : sub){
		// ++stop;
		// if(stop == 2) return 0;
		cout << "Subject: " << c.F << '\n';
		cout << "ID: " ;
		for(int i=0 ; i<sz(c.S.ID) ; ++i){
			cout << c.S.ID[i].S.S << ",\n"[i==sz(c.S.ID)-1];
		}
	}*/
	vector<Subject> ans;
	for(auto &c:sub){
		ans.pb(c.S);
	}
	sort(all(ans));
	while(ans.size() > 2) ans.pop_back();
	for(auto &c : ans){
		cout << "Subject: " << c.name << '\n';
		cout << "ID: ";
		for(int i=0 ; i<sz(c.ID) ; ++i) cout << c.ID[i].S.S << ",\n"[i==sz(c.ID)-1];
		cout << '\n';
	}
	cout << '\n';
}
/*
Subject: 經濟風暴
Date: 11 20 10 2008
ID: 1

Subject: 美國總統當選人
Date: 11 19 12 2008
ID: 12

Subject: Re: 經濟風暴
Date: 11 21 20 2008
ID: 34

Subject: Re: 美國總統當選人
Date: 11 22 13 2008
ID: 98

*/