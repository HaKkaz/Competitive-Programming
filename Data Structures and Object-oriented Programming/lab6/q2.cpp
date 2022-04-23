#include<iostream>
using namespace std;
/* Add whatever you want*/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

int main(){
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	fast;
	int n , kase=1;
	while(cin >> n , n){
		cout << "Scenario #" << kase++ << '\n';
		deque< deque<int> > qq;
		map<int,int> team , cnt;
		map<int , deque<int>* > where;
		for(int i=0 ; i<n ; ++i){
			int k ; cin >> k;
			for(int j=0 ; j<k ; ++j){
				int id; cin >> id;
				team[id] = i;
			}
		}

		string opt;
		while(cin >> opt){
			while(qq.size() && qq.front().empty()) {
				qq.pop_front();
			}
			if(opt[0] == 'S'){
				break;
			}
			if(opt[0] == 'E'){
				int id; cin >> id;
				if(where.find(team[id]) != where.end()){
					(*where[team[id]]).push_back(id);
				}
				else{
					qq.push_back(deque<int>(1,id));
					where[team[id]] = &qq[qq.size()-1];
				}
				cnt[team[id]]++;
			}
			if(opt[0] == 'D'){
				int who = qq.front().front();
				cnt[team[who]]--;
				if(cnt[team[who]] == 0) where.erase(team[who]);
				cout << who << '\n';
				qq.front().pop_front();
			}
		}
		cout<<'\n';
	}
}