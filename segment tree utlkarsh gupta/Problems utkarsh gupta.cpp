q#include "bits/stdc++.h"
using namespace std;



#define ll 				long long
#define pii 			pair<int,int>
#define f 				first
#define s 				second
#define vi 				vector<int>
#define vl 				vector<long long>
#define rep(i,a,b)  	for(int i=a;i<b;i++)
#define repr(i,b,a) 	for(int i=b;i>a;i--)
#define pb 				push_back
#define all(x)			(x).begin(),(x).end()


//find the minimim and frequency of minimim in the given ranges

int tree[4*N];
bool lazy[4*N];
int updated[4*N];

//build 


void propogate(int v, int tl, int tr, int val){
	tree[v] += (val*(tr-tl+1));
	if(tl!= tr){
		lazy[v] = true;
		updated[v] += val;

	}

}

//lazyUpdate
void lazyUpdate(){
	if(lazy[v] == true){
		lazy[v] = false;
		int tm = tl +(tr-tl)/2;
		propogate(2*v+1,tl,tm,updated[v]);// propogate on left child
		propogate(2*v+2,tm+1,tr,updated[v]);// propogate on right child
		updated[v] = 0;
	}
}
//Range update
void update(int v,int tl,int tr, int l, int r, int val){

	//ot of range
	if(tr < l or r < tl){ //[ tr l   r  tl]
		return;
	}

	//if fully in this range
	if(l <= tl and tr <= r){//[l tl tr r]
		lazyUpdate();
	}
	else{
		pushDown();
		int tm = tl +(tr-tl)/2; 

		update(2*v+1, tl , tm , l, r,val);//left child
		update(2*v+2, tm+1 , tr , l, r,val);// right child

		tree[v] = ;
	}
}

//Range query
int query(int v,int tl,int tr, int l, int r){

}


void solve(){

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
	
	return 0;
}
