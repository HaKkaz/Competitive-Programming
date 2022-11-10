#include<iostream>
using namespace std;
int main(){
	int num[9][9];
	bool chk[9];
	while(cin >> num[0][0]){
		for(int i=0 ; i<9 ; i++){
			for(int j=0 ; j<9 ; j++){
				if(i == 0 && j == 0) continue;
				cin >> num[i][j];
			}
		}
		bool ok=true;
		for(int k=0 ; k<9 ; k+=3){
			for(int l=0 ; l<9 ; l+=3){
				fill(chk,chk+9,0);
				for(int i=k ; i<k+3 ; i++){
					for(int j=l ; j<l+3 ; j++){
						if( chk[num[i][j]-1] ) { ok = false; }
						else { chk[num[i][j]-1] = true; }
					}
				}
			}
		}
		for(int i=0 ; i<9 ; i++){
			fill(chk,chk+9,0);
			for(int j=0 ; j<9 ; j++){
				if( chk[num[i][j]-1] ) { ok = false; }
				else { chk[num[i][j]-1] = true; }
			}
		}
		for(int i=0 ; i<9 ; i++){
			fill(chk,chk+9,0);
			for(int j=0 ; j<9 ; j++){
				if( chk[num[j][i]-1] ) { ok = false; }
				else { chk[num[j][i]-1] = true; }
			}
		}
		ok ? cout << "yes" <<'\n' : cout << "no" << '\n' ;
	}
}