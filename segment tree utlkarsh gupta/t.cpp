#include <bits/stdc++.h>
using namespace std;



#define int long long
#define pii pair<int,int>
#define f first
#define s second

int min(int a,int b){

	if(a>=b){
		return b;
	}else{
		return a;
	}

}

int max(int a,int b){

	if(a>=b){
		return a;
	}else{
		return b;
	}

}

const int N = 1e5;
int tree[4*N] = {0};
void build(int root, int tl,int tr,string& s){
	if(tl == tr){
		int currMask = 0;
		int ch = s[tl]-'a';
		tree[root] = (currMask| (1<<ch));
		//tree[root] |= (1<<ch);  check ??????
	}

	else{
		int mid = tl +(tr-tl)/2;

		build(2*root+1,tl,mid,s);//left
		build(2*root+2,mid+1,tr,s);//right

		tree[root] = (tree[2*root+1] | tree[2*root+2]);//find 

	}
}

int query(int root , int tl , int tr, int l, int r){
	//if out of range
	if(l > tr or r < tl){ //[l tl tr r]
		return 0;
	}
	//if fully in range
	if(l <= tl and tr <= r){//????
		return tree[root];
	}	
	//partiall range

	else{
		int mid = tl+(tr-tl)/2;

		int left = query(2*root+1 ,tl ,mid, l, r);
		int right =query(2*root+2 ,mid+1 ,tr, l, r) ;

		return (left|right);
	}

}

void update(int root,int tl,int tr,int pos,char c,string& s){
	//i need to go at that position and unset the prevoius char and set the curr char

	if(tl == tr){
		s[tl] = c;
		int currMask = 0;
		tree[root] = (currMask|(1<<(c-'a')));
	}
	else{
		int mid = tl+(tr-tl)/2;

		if(pos <= mid){//belongs to left side
			update(2*root+1,tl,mid,pos,c,s);
		}
		else{
			update(2*root+2,mid+1,tr,pos,c,s);
		}

		tree[root] = (tree[2*root+1]|tree[2*root+2]);
	}
}

void solve(){
	//for query find ans using __builtin_popcount(query())
	string s;
	cin>>s;
	int n = s.size();
	build(0,0,n-1,s);
	int q;
	cin>>q;	
	while(q--){
		int t;
		cin>>t;

		if(t==1){
			int pos;
			char c;
			cin>>pos>>c;
			pos--;
			update(0,0,n-1,pos,c,s);
		}
		else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			int ans = query(0,0,n-1,l,r);

			cout << __builtin_popcount(ans)<< endl;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int tc = 1;
	//cin>>tc;

	while(tc--){
		solve();
	}
	return 0;
}
