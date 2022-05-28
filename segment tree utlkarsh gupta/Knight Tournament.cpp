#include <bits/stdc++.h>
using namespace std;


//#define int long long
#define pii pair<int,int>
#define f first
#define s second

const int N = 3e5;
int tree[4*N];
// void build(int root , int tl , int tr){

// 	if(tl==tr){
// 		//every king is alive
// 		tree[root] = 0;
// 		//return;
// 	}
// 	else{
// 		int mid = tl+(tr-tl)/2;
// 		build(2*root+1,tl,mid);
// 		build(2*root+2,mid+1,tr);

// 		tree[root] = 0;//how many kings are dead

// 	}

// }


//point query and range update
void update(int root , int tl,int tr,int l, int r,int w){

	if(tree[root] != 0){
		return;
	}
	//out of range
	if(tl > r or tr < l){//[ tl tr]
		return;
	}

	//if fully ranges
	if(l <= tl and tr <= r){// how many kings kills excpect w
		tree[root] = w;
		return;

	}

	else{//partailly in ranges
		int tm = tl+(tr-tl)/2;
		update(2*root+1,tl,tm,l,r,w);
		update(2*root+2,tm+1,tr,l,r,w);

	}

}


int query(int root,int tl, int tr,int i){
	if(tl==tr){
		return tree[tl];

	}
	
	if(tree[root]){
		if(not tree[2*root+1]){
			tree[2*root+1] = tree[root];
		}
		if(not tree[2*root+2]){
			tree[2*root+2] = tree[root];
		}

		tree[root]=0;
	}
	//else{
		int tm = tl+(tr-tl)/2;

		if( i <= tm ){//left
			return query(2*root+1,tl,tm,i);
		}
		else{
			return query(2*root+2,tm+1,tr,i);
		}
	//}
}


void solve(){
	int n,m;
	cin>>n>>m;
	//build(0,0,n-1);
	while(m--){	
		int l,r,w;
		cin>>l>>r>>w;
		l--,r--;
		if(l <= w-2){
			update(1,0,n-1,l,w-2,w);
		}
		if(w <= r){
			update(1,0,n-1,w,r,w);
		}
	}

	for(int i=0;i<n;i++){
		int q = query(1,0,n-1,i);
		cout << q << " ";
	}

	cout << endl;
}

// void solve2(){
// 	int n,m;
// 	cin>>n>>m;
// 	set<int> alive;
// 	for(int i=1;i<=(n+4);i++){
// 		alive.insert(i);
// 	}
// 	vector<int> ans(n+1,0);
// 	while(m--){	
// 		int l,r,w;
// 		cin>>l>>r>>w;

// 		auto itr = alive.lower_bound(l);

// 		while((*itr <= r) && (itr != alive.end())){//loop from l to r
// 			//who ever is present except w
// 			if(*itr != w){
				
// 				ans[*itr] = w;
// 				auto kill = itr;
// 				itr++;
// 				alive.erase(kill);
// 			}
// 			else{
// 				itr++;
// 			}
			
// 		}


// 	}

// 	for(int i=1;i<=n;i++){
// 		cout << ans[i] << " ";
// 	}
// 	cout << endl;
// }

int32_t main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int tc = 1;
	//cin>>tc;

	while(tc--){
		solve(); //using segment tree(incomplete)
		// solve2(); using set
		
	}
	return 0;
}