#include<iostream>
#include<vector>
using namespace std;
const int coin[]={1,5,10,25,50};
int main(){
	int n;
	while(scanf("%d", &n) != EOF){	
		vector<long long> dp(n+1,0);
		dp[0] = 1;
		for(const int &c : coin)
			for(int i=0 ; i<=n ; ++i)
				if(i + c <= n) dp[i+c]+=dp[i];
		if(dp[n] == 1) printf("There is only 1 way to produce %d cents change.\n" , n);
		else printf("There are %ld ways to produce %d cents change.\n" , dp[n] , n);
	}
}