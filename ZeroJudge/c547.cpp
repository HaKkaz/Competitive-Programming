#include<iostream>
int n,dp[10005],i;main(){for(dp[1]=1,dp[2]=2,i=3;i<=10000;++i)dp[i]=(dp[i-1]+dp[i-2])%1000000007;while(std::cin>>n)std::cout<<dp[n]<<'\n';}