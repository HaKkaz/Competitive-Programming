#include<bits/stdc++.h>

#define Vi vector<int>
#define Vs vector<string>
#define Mii map<int,int>
#define Msi map<string,int>
#define Mis map<int,string>
#define Mss map<string,string>
#define PB push_back
#define PF push_front

typedef long long ll;
using namespace std;
const int MAXN=10001;

long long  n,wei[MAXN],val[MAXN],dp[MAXN][105];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>wei[i]>>val[i];
		
	for(int i=wei[1];i<=100;i++)
		dp[1][i]=val[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=100;j++){
			dp[i][j]=dp[i-1][j];
			if(wei[i]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-wei[i]]+val[i]);
		}
	}
	cout<<dp[n][100];
}