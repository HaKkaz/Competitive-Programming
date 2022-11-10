#define pii pair<int,int>
#define F first
#define S second
#include<bits/stdc++.h>
using namespace std;
int cross(const pii &a , const pii &b){
	return a.F*b.S - a.S*b.F;
}
signed main(){
	pii p[3];
	for(int i=0 ; i<3 ; ++i) cin >> p[i].F >> p[i].S;
	cout << abs(cross(make_pair(p[0].F-p[1].F , p[0].S-p[1].S) , make_pair(p[0].F-p[2].F , p[0].S-p[2].S))) << '\n';
}