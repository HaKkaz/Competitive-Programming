#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
 
int used[100001],sets[100001],rk[100001];
 
int root(int a){
	if (a != sets[a])
		sets[a] = root(sets[a]);
	return sets[a];
}
 
int main(){
	__IO
	int a,b,t = 1;
	while (cin >> a >>b && a >= 0 && b >= 0){
		for (int i = 0 ; i < 100000 ; ++ i){
			sets[i] = i;
			used[i] = rk[i] = 0;
		}
		int flag = 1;
		while(a||b){
			if (root(a) == root(b))
				flag = 0;
			if (flag){
				used[a] = used[b] = 1;
				sets[root(b)] = root(a);
			}
			cin >>a >> b;
		}
		
		if(flag == 1){
			int cnt = 0;
			for (int i = 0 ; i < 100000 ; ++i)
				if (used[i] && root(i) == i)
					if (cnt ++) {
						flag = 0;
						break;
					}
		}
		
		if(flag == 0)cout<<"Case "<<t<<" is not a tree.\n",t ++;
		else cout<<"Case "<<t<<" is a tree.\n",t ++;
	}
	
	return 0;
}