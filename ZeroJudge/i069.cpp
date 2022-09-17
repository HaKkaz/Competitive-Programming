#include<bits/stdc++.h>
using namespace std;

int arr[105]

int main(){
	int n; cin >> n ;
	for(int i=0 ; i<n ; ++i) cin >> arr[i];

	int sum = 0;
	int mx = 0;
	int mn = 1000000000;
	int mx_pos = -1;
	int mn_pos = -1;

	for(int i=0 ; i<n ; ++i){
		sum += arr[i];
		if(arr[i] > mx)
		{
			mx = arr[i];
			mx_pos = i;
		}
		if(arr[i] < mn)
		{
			mn = arr[i];
			mn_pos = i;
		}
	}

	sum /= n;

	arr[mn_pos] += mx - sum;
	arr[mx_pos] -= mx - sum;
	for(int i=0 ; i<n ; ++i) cout << arr[i] << ' ';
}
