#include<bits/stdc++.h>
#define ED end()
#define BG begin()
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define BtoE(X) (X).begin(),(X).end()
#define test_
using namespace std;
vector<int> child[100005];
int f[100005];
int dist[100005];

void init()
{
	for(int i=0 ; i<100005 ; i++) child[i].clear();
	fill( f , f+100005 , 0 );
	fill( dist , dist+100005 , 0);
}

void deep( int vertex)
{
	dist[vertex]=0;
	if( child[vertex].size() )
	{
		for(int i=0 ; i<(int)child[vertex].size() ; i++){
			deep( child[vertex][i] );
			dist[vertex] = max( dist[vertex] , dist[child[vertex][i]]+1 );
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while(cin >> n){

    	init();

    	for(int i=1 ; i<=n ;i++)
    	{
    		int x;
    		cin >> x;
    		if(!x) continue;
    		for(int j=0 ; j<x ; j++){
    			int v; 
    			cin >> v;
    			child[i].PB(v);
    			f[v] = i;
    		}
    	}
    	int now = 1;
    	long long sum = 0;

    	while( f[now] ){
    		now = f[now];
    	}


    	deep( now );
    	for(int i=1 ; i<=n ; i++){
    		sum += dist[i];
    	}
    	cout << now << '\n' << sum << '\n';
    }
}