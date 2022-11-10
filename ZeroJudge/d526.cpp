#include<deque>
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *Lc , *Rc;
	node(int x){ Lc = Rc = nullptr , data = x;}
};
node *insert(node *T,int x){
	if(T == nullptr)
		return new node(x);
	else{
		if(x<T->data) T->Lc = insert(T->Lc , x);
		else T->Rc = insert(T->Rc , x);
		return T;
	}
}
void pre(node *n){
	if(n == nullptr) return;
	cout<<n->data<<' ';
	pre(n->Lc);
	pre(n->Rc);
}
int main(){ios::sync_with_stdio(false),cin.tie(0);
	node *root;
	int n , x;
	while(cin >> n){
		cin >> x;
		root=new node(x);
		for(int i=1 ; i<n ; ++i){
			int x; cin >> x;
			insert(root , x);
		}
		pre(root);
		cout<<'\n';
	}
}