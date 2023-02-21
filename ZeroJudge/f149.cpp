#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n, m;
int mp[20][20];
int dead[20][20];
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

bool check(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

signed main(){
	fast;
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mp[i][j];
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (mp[x][y] == 5) {
				bool hav_5 = false;
				// (x,y) 如果是探測器，往八方位看有沒有探測器，有的話這個探測器無效
				for (int d = 0; d < 8; ++d) {
					int xx = x + dx[d];
					int yy = y + dy[d];
					if (check(xx, yy) && mp[xx][yy] == 5) {
						hav_5 = true;
					}
				}

				if (hav_5) continue; // 無效

				for (int d = 0; d < 8; ++d) {
					int xx = x + dx[d];
					int yy = y + dy[d];
					if (check(xx, yy) && mp[xx][yy] == 1) {
						mp[xx][yy] = 2;
					}
				}
			}
		}
	}

	int can = 0, cannot = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			can += (mp[x][y] == 2);
			cannot += (mp[x][y] == 1);
		}
	}
	cout << can << ' ' << cannot << '\n';

}