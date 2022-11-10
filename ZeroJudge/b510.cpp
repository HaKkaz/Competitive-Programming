#include<bits/stdc++.h>
using namespace std;
int ans=0 , queen = 0 , castle = 0 , n , m;
char table[25][25];
void solve(int x , int y){
	if(x == n+m-1 && y == n+m){
		//走到底就要停止
		if(queen == m && castle == n){
			//符合條件才是答案
			++ans;
		}
		return;
	}
	if(y == n+m){
		//if y == n+m , fix y
		x = x+1 , y = 0;
	}
	//put nothing
	{
		solve(x , y+1);
	}
	//put queen
	{
		bool check = 1;
		//if check == 0 : cannot put
		for(int i=0 ; i<n+m ; ++i){
			if(table[i][y] != '_') check=0;
			if(table[x][i] != '_') check=0;
		}
		for(int i=x,j=y ; i>=0 && j>=0 ; --i,--j){
			if(table[i][j] != '_') check=0;
		}
		for(int i=x,j=y ; i>=0 && j<n+m ; --i,++j){
			if(table[i][j] != '_') check=0;
		}
		if(check && queen + 1 <= m){
			++queen;
			table[x][y] = '*';
			solve(x , y+1);
			table[x][y] = '_';
			--queen;
		}
	}
	//put castle
	{
		bool check = 1;
		for(int i=0 ; i<n+m ; ++i){
			if(table[i][y] != '_') check=0;
			if(table[x][i] != '_') check=0;
		}
		for(int i=x,j=y ; i>=0 && j>=0 ; --i,--j){
			if(table[i][j] == '*') check=0;
		}
		for(int i=x,j=y ; i>=0 && j<n+m ; --i,++j){
			if(table[i][j] == '*') check=0;
		}
		if(check && castle + 1 <= n){
			++castle;
			table[x][y] = '+';
			solve(x , y+1);
			table[x][y] = '_';
			--castle;
		}
	}
}
int main(){
	cin >> m >> n ;
	for(int i=0 ; i<n+m ; ++i)
		for(int j=0 ; j<n+m ; ++j)
			table[i][j] = '_';
	solve(0,0);
	cout << ans << '\n';
}