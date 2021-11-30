#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 

int main(){
	fast;
    vector<int> ids;
    int ans = 0 ;
    int n ; cin >> n ;
    for(int i=0 ; i<n ; ++i){
        int id , day;
        cin >> id >> day;
        if(day > 100) ids.push_back(id) , ans += (day-100) * 5;
    }
    sort(ALL(ids));
    if(ids.empty()) return cout << 0 << '\n' , 0;
    for(int &id : ids) cout << id << ' ';
    cout << '\n' << ans << '\n';
}

