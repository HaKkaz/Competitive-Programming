#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int cnt=0;
	while(cin >> n){
	
		vector<int> num;
		int sum=0;
		if(n == 0) break;
		for(int i=0 ; i<n ; i++){
			int x;
			cin >> x;
			sum += x;
			num.push_back(x);
		}
		sum /= n;
		int ans = 0;
		for(int i=0 ; i<n ; i++){
			if(num[i] < sum)  ans += (sum-num[i]);
		}
		cnt++;
		cout << "Set #" <<cnt<<"\nThe minimum number of moves is " << ans <<".\n";
		
	}
	
}