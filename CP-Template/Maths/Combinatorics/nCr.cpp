#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define inf INT_MAX
#define N_inf INT_MIN
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int mod = (int)1e9 + 7;
ll min(ll a, ll b) { if (a >= b) { return b; } return a; }
ll max(ll a, ll b) { if (a >= b) { return a; } return b; }

ll ModAdd(ll a, ll b , ll mod) { return (a % mod + b % mod) % mod; }
ll ModSubtract(ll a, ll b , ll mod) { return ((a % mod) - (b % mod) + mod) % mod; }
ll ModMultiply(ll a, ll b , ll mod) { return (a % mod * b % mod) % mod; }



ll BinExpo(ll base , ll pow, ll mod) {
	// base Cond
	if (pow == 0) {
		return 1;
	}
	if (pow == 1) {
		return base;
	}
	ll newBase = BinExpo(base, pow / 2, mod);
	ll ans = 1;
	if (pow % 2) {
		ans = ((newBase % mod) * (newBase % mod)) % mod;
		ans = ((ans % mod) * (base % mod)) % mod;
	}
	else {
		ans = ((newBase % mod) * (newBase % mod)) % mod;
	}

	return ans;

}

ll ModDivide(ll a, ll b , ll mod) { return (a % mod * BinExpo(b, mod - 2, mod)) % mod; }


ll fact(ll x) {
	ll ans = 1;
	for (int i = 1; i <= x; i++) {
		ans = ModMultiply(ans, i, mod);
	}
	return ans;
}

// Basic Calculation TC = 3*(max(n,r))
ll nCr(int n , int r) {
	// Formala = numerator * Inverse(denominator)
	ll nume = fact(n);
	ll deno = ModMultiply(fact(r) , fact(n - r), mod);
	ll ans =  ModDivide(nume, deno, mod);
	return ans;
}

// Using Seive to Calculate nCr
// void nCr(int n, int r) {

// }

int32_t main() {
	cout << nCr(12, 4) << endl;
	return 0;
}

