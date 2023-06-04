#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

const int MAXC = 2e5;
bitset<MAXC> keys_you_have;
bitset<MAXC> visited_room;
signed main(){
    fast;
    int n, m, k;
    cin >> n >> m >> k;

    int t; cin >> t;
    vector<int> init_keys;
    while(t--) {
        int key;
        cin >> key;
        keys_you_have[key] = true;
        init_keys.push_back(key);
    }

    vector< vector<int> > related_rooms(MAXC, vector<int>());
    vector< array<int,5> > keys_room_need(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int id; cin >> id;
            keys_room_need[i][j] = id;
            related_rooms[id].push_back(i);
        }
    }

    vector< vector<int> > keys_room_have(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> keys_room_have[i][j];
        }
    }

    int answer = 0;
    queue<int> que;
    auto walk = [&](int key_id) {
        for (int &related_room : related_rooms[key_id]) {
            if (visited_room[related_room]) continue;
            bool ok = true;
            for (int i = 0; i < k; ++i) {
                int key = keys_room_need[related_room][i];
                if (keys_you_have[key] == false) {
                    ok = false;
                }
            }
            if (ok) {
                answer++;
                visited_room[related_room] = true;
                for (int i = 0; i < k; ++i) {
                    int key = keys_room_have[related_room][i];
                    keys_you_have[key] = true;
                    que.push(key);
                }
            }
        }
    };

    for (int &init_key : init_keys) {
        walk(init_key);
    }

    while (que.size()) {
        int now_key = que.front();
        que.pop();
        walk(now_key);
    }
    cout << answer << '\n';
}