#include <iostream>
using namespace std;

int cnt[20000];
int arr[1005];

int main(){
	int n; cin >> n;
	for(int i=0 ; i<n ; ++i){
		int x;
		cin >> x;
		x += 10000; //所有數字都+10000就不會有負數了
		cnt[x]++;
		arr[i] = x;
	}

	int mx = 0; //出現最多次，是幾次
	int diff = 0; //不一樣的數字有幾個

	for(int i=1 ; i<20000 ; ++i){
		if(cnt[i] > mx){ // why?
			mx = cnt[i];
		}
		if(cnt[i] > 0){ // why?
			diff++;
		}
	}

	cout << diff << endl;

	if(mx == 1){
		cout << "NO" << endl;
	}
	else{
		for(int i=0 ; i<n ; ++i){
			if(cnt[ arr[i] ] == mx){
				cout << arr[i] - 10000 << ' ' ;
				cnt[ arr[i] ] = 0;
			}
		}
	}
}