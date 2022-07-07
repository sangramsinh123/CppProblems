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


//map<string,int> mp;we are not using it it becoz key = string and it go upto 5000

vector<int> dp;
int rec(string &s,int i,int n){
        if(i>=n){
            return 1;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        if(s[i] >= '1' and s[i] <= '9'){
            ans += rec(s,i+1,n);//option1 = to take 1 char
        }
        //s[i]+s[i+1]
        if(s.substr(i,2) >= "10" and s.substr(i,2) <= "26" and i<=n-2){
            ans += rec(s,i+2,n);//option2 = to take 2 char
        }
        dp[i] = ans;
        return ans;
 }


void solve(string s){

	int n = s.size();
	dp = vector<int>(5005,-1);
	cout << rec(s,0,n) << endl;
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
	while(1){
		string s;
		cin>>s;
		if(s[0]=='0'){
			break;
		}
		solve(s);
	}

	cerr << ((double)(clock()-z)/CLOCKS_PER_SEC);

	return 0;
}
