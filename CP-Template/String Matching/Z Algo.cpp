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


vector<int> z_function(string s) {
	int n = s.size();
	vector<int> z(n, 0);
	int l = 0, r = 0;
	// take care of Proper Prefix Initially
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[0 + i - l]); // z[0 + i - l] = counter part
		}
		while ((i + z[i]) < n and s[0 + z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		// update r
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1
		}
	}
	return z;
}


int main() {

	return 0;
}


