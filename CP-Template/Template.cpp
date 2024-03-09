


/*
  Compete against Yourself.
  Author - Sangramsinh
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
  https://codeforces.com/contest/4/submission/150120627
*/


#include<bits/stdc++.h>
using namespace std;

#define ll 				long long
#define pii 			pair<int,int>
#define pb 				push_back
#define F 				first
#define S 				second
#define all(x) 			x.begin(),x.end()
#define fo(i,n) 		for(int i = 0;i<n;i++)
#define repA(i,st,en)   for(int i=(st);i<=(en);++i)
#define repD(i,st,en)   for(int i=(en);i>=(st);--i)
#define inf 			INT_MAX
#define N_inf 			INT_MIN
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl 			"\n"

const int mod = (int)1e9 + 7;

using lli = 	long long int;
using mytype = 	long double;
using ii = 		pair<lli, lli>;
using vii = 	vector<ii>;
using vi = 		vector<lli>;


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

template <class T>
using ordered_set =  __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.




void solve() {


}


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
	return 0;
}


