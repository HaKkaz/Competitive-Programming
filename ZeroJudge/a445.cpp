#include<bits/stdc++.h>
using namespace std;
int fa[100000];

int F(int x){
	if(x == fa[x]) return x;
	return fa[x] = F(fa[x]);
}

void U(int a, int b){
	a = F(a) , b = F(b);
	if(a == b) return;
	fa[b] = a;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	int n, m, q;
 	cin >> n >> m >> q;
 	for(int i=1 ; i<=n ; ++i) fa[i] = i;

 	while(m--){
 		int a,b; cin >> a >> b;
 		U(a,b);
 	}

 	while(q--){
 		int a,b; cin >> a >> b;
 		if(F(a) == F(b)) cout << ":)\n";
 		else cout << ":(\n";
 	}
}