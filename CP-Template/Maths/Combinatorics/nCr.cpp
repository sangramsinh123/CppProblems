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

// ==========================================================================================================
ll fact(ll x) {
	ll ans = 1;
	for (int i = 1; i <= x; i++) {
		ans = ModMultiply(ans, i, mod);
	}
	return ans;
}

// Basic Calculation TC = T*(3N)
ll nCr(int n , int r) {
	// Formala = numerator * Inverse(denominator)
	ll nume = fact(n);
	ll deno = ModMultiply(fact(r) , fact(n - r), mod);
	ll ans =  ModDivide(nume, deno, mod);
	return ans;
}


// ==========================================================================================================
// Using Precomputation to Calculate nCr
const int N = 1e6 + 1;
ll factorial[N];
ll Inverse_factorial[N];
void Precompute(int n) {
	factorial[0] = 1;
	for (int i = 1; i <= n; i++) {
		factorial[i] = ModMultiply(factorial[i - 1] , i, mod);
	}


	Inverse_factorial[n] = BinExpo(factorial[n], mod - 2, mod);// log(mod)
	for (int i = n - 1; i >= 0; i--) {
		// Inverse_factorial[i] = BinExpo(factorial[i], mod - 2, mod); // TC : N*log(mod) + T
		Inverse_factorial[i] = ModMultiply(i + 1 , Inverse_factorial[i + 1], mod);  // TC : N+T
	}
}


// TC = N + T*log(Mod) = Precomputation + T*(Mod Inverse Calculation) ,  where T = TestCases
ll nCr(int n , int r) {
	// Formala = numerator * Inverse(denominator)
	ll nume = factorial[n];
	ll deno = ModMultiply(factorial[r] , factorial[n - r], mod); // factors[r]*factors[n-r]
	ll ans =  ModDivide(nume, deno, mod); // log(mod)
	return ans;
}

// ==========================================================================================================

// Using Inverse_factors and factors , TC = N+T = Precomputation + TestCase
ll nCr(int n , int r) {
	// Formala = numerator * Inverse(denominator)
	ll ans = factorial[n];
	ans = ModMultiply(ans , Inverse_factorial[r], mod); //ans * Inverse_factors[r]
	ans = ModMultiply(ans , Inverse_factorial[n - r], mod); //ans * Inverse_factors[n-r]

	return ans;
}


// ==========================================================================================================

int32_t main() {
	Precompute(N);
	cout << nCr(12, 5) << endl;
	return 0;
}



