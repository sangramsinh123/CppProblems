#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact){ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

void solve1(int n,int k){//for even

	ll *fact = new ll[n + 1];
	ll *ifact = new ll[n + 1];
	fact[0] = 1, ifact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		ifact[i] = mminvprime(fact[i], MOD);
	}
	ll y = 0;
	for (ll i = 0; i <= n - 2; i += 2) {
		ll x = combination(n, i, MOD, fact, ifact);
		y = mod_add(x, y, MOD);
	}

	ll dp[k+1];
	dp[0]=1;
	for(ll i = 1;i<=k;i++){
		ll opt1 =  expo(expo(2,i-1,MOD),n,MOD);
		ll opt2 =  mod_mul(y,dp[i-1],MOD);
		dp[i] = mod_add(opt1,opt2,MOD);
		//dp[i] = (opt1+opt2)%MOD;
	}

	cout << dp[k] << endl;
}

void solve2(int n,int k){//for odd

	ll *fact = new ll[n + 1];
	ll *ifact = new ll[n + 1];
	fact[0] = 1, ifact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		ifact[i] = mminvprime(fact[i], MOD);
	}
	ll y = 0;
	for (ll i = 0; i <= n - 1; i += 2) {
		ll x = combination(n, i, MOD, fact, ifact);
		y = mod_add(x, y, MOD);
	}

	ll dp[k+1];
	dp[0]=1;
	for(ll i = 1;i<=k;i++){
		ll opt1 =  dp[i-1];
		ll opt2 =  mod_mul(y,dp[i-1],MOD);
		dp[i] = mod_add(opt1,opt2,MOD);
	}

	cout << dp[k] << endl;
}


int32_t main(){
	fastio;
    int tc;
    cin>>tc;
    
    while (tc--) {
		int n, k;
		cin >> n >> k;
		if (k == 0) {
			cout << 1 << "\n";
			continue;
		}
		if (n % 2 == 0) {
			solve1(n, k);
		} else {
			solve2(n, k);
		}
	}
	



	return 0;
}