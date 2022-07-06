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
// #define rec(i,n) 		for(int i=0;i<n;i++)
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
//TC : O(logn) //SC : O(logn)//Implicit stack takes O(logn)
int pow(int a, int n){//f = true only n is even
	if(n==0){
		return 1;
	}

	int subpro = pow(a,n/2);
	int sq = subpro*subpro;

	if(n&1){// if n is odd
		return a*sq;
	}
	else{
		return sq;
	}

}
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


vector<int> dp;
vector<int> cache;

int rec(int n){


	//base case
	if(n==1){
		return 0;
	}
	if(n==2 or n==3){
		return 1;
	}
	if(cache[n] != -1){
		return cache[n];
	}
	
	int mn = rec(n-1);//option 1
	
	if(n%2==0){
		mn = min(mn,rec(n/2));//option 2
	}

	if(n%3==0){
		mn = min(mn,rec(n/3));//option 3
	}
	int ans = 1+mn;
	cache[n] = ans;
	return cache[n];

}

int TOPDOWN(int n){
	dp = vector<int> (n+1);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++){
		int mn = dp[i-1];
		if(i%2 == 0){
			mn = min(mn,dp[i/2]);
		}

		if(i%3 == 0){
			mn = min(mn,dp[i/3]);
		}
		dp[i] = 1+mn;
	}

	return dp[n];
}

void solve(){

	int n;
	cin>>n;
	cache = vector<int> (n+1,-1);

	cout << rec(n);
	// cout << TOPDOWN(n);
	
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