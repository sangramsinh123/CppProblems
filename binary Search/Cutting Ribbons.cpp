#include <bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define F 				first
#define S 				second
#define pii				pair<int,int>
#define pll				pair<ll,ll>
#define pb				push_back
#define vi 				vector<int>
#define vii				vector<vi>
#define vl 				vector<long long>
#define rec(i,n) 		for(int i=0;i<n;i++)
#define recn(i,a,b)		for(int i=a;i<=b;i++)
#define recr(i,n)		for(int i=n-1;i>=0;i--)
#define endl			'\n'
#define all(x)			x.begin(),x.end()
#define inf				1000000000000000005

const ll mod = 1e9 + 7;
ll mod_add(ll a, ll b){	a = (a % mod);	b = (b % mod);	return ((( a + b) % mod) + mod) % mod;}
ll mod_mul(ll a, ll b){ a = (a % mod);	b = (b % mod);	return ((( a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b){ a = (a % mod);  b = (b % mod);	return ((( a - b) % mod) + mod) % mod;}

ll ceil_div(ll a, ll b){	return (a % b == 0) ? (a/b) : (a/b)+1; }
ll gcd(ll a, ll b){ if(b == 0){ return a; } return gcd(b,a%b); }

//ll inv(ll i)
//ll pwr(ll a, ll b)
//****************************Template Ends*******************************//


//const int N = 2e5;

/*

GCD of all elements in array

int g = 0;
for(int i=0;i<n;i++){
	g = __gcd(g,a[i]);
}

gcd of even numbers is always = 2

========================

*/


/*
UPPER BOUND
LOWER BOUND

*/

#define py cout << "YES" << endl;
#define pn cout << "NO" << endl



int func(vector<int> &arr, int n , int len){
	//how many ribbons i can have after cut with len
	int c = 0;
	for(int i=0;i<n;i++){
		c+=floor(arr[i]/len);
	}

	return c;
	/*
	 [7,5,9] , k=4

	 0 1 2 3 4 5 6

	 mid = 3 ;
	 c= 2+1+3=6
	
	mid = 4
	c=1+1+2 = 4

	mid = 5
	c= 1+1+1 = 3<4



	*/

}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	
	//int mx = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	int lo = 1 ;
	int hi = 1e9 ; 

	int ans = 0;

	while(lo<=hi){
		int mid = lo+(hi-lo)/2;

		//0 1 2 3 4 5 6 7 
		int c = func(arr,n,mid);
		if(c >= k){
			ans = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	cout << ans << endl;

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
		
	clock_t z = clock();
	int tc;
	// cin>>tc;
	tc=1;
	while(tc--){
		solve();
	}

	cerr << ((double)(clock()-z)/CLOCKS_PER_SEC);

	return 0;
}
