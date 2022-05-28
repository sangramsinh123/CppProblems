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


// const int N = 1e5+5;

// struct cmp{
// 	bool operator() (pii a, pii b){
		
// 	}
// };

/*

1)implement dfs,bfs
2)binary search , upper_bound,lower_bound
3)sieve#include "bits/stdc++.h"
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


// const int N = 1e5+5;

// struct cmp{
// 	bool operator() (pii a, pii b){
		
// 	}
// };

/*

1)implement dfs,bfs
2)binary search , upper_bound,lower_bound
3)sieve
4)basic dynamic programming
5)Important notes
6)Multiset {IMPORTANT LUV_VIDEO}
*/




const int N = 1e5;
//for segment tree
int tree[4*N];
bool lazy[4*N];
int updated[4*N];



// void build(){

// }

void propgate(int v, int tl,int tr,int val){
	tree[v] += (val*(tr-tl+1));
	if(tl != tr){//if it is not leaf node
		lazy[v] = true;
		updated[v] +=val;

	}

}
void pushDown(int v,int tl,int tr){

	if(lazy[v] == true){
		lazy[v] = false;
		int tm = tl+(tr-tl)/2;
		propgate(2*v+1,tl,tm,updated[v]);//left
		propgate(2*v+2,tm+1,tr,updated[v]);//right
		updated[v] = 0;
	}
	
}


void update(int v, int tl, int tr, int l ,int r, int val){
	if(tr < l or r < tl){//out of range  [  tr  l r tl]
		return;
	}

	if(l <= tl and tr <= r){//if totally inside range [l tl tr r]
		propgate(v,tl,tr,val);

	}
	else{
		pushDown(v,tl,tr);
		int tm = tl+(tr-tl)/2;
		update(2*v+1,tl,tm,l,r,val);
		update(2*v+2,tm+1,tr,l,r,val);
		tree[v] = tree[2*v+1]+tree[2*v+2];
	}
}

//range query
int query(int v, int tl ,int tr ,int l, int r){

	if(tr < l or r < tl){//out of range  [  tr  l r tl]
		return 0;
	}
	if(l <= tl and tr <= r){//if totally inside range [l tl tr r]
		return tree[v];
	}
	else{
		pushDown(v,tl,tr);
		int tm = tl+(tr-tl)/2;
		int left = query(2*v+1,tl,tm,l,r);
		int right = query(2*v+2,tm+1,tr,l,r);
		return left+right;
	}
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

