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

ll ModAdd(ll a, ll b , ll mod) {
	return (a % mod + b % mod) % mod;
}

ll ModSubtract(ll a, ll b , ll mod) {
	return ((a % mod) - (b % mod) + mod) % mod;
}

ll ModMultiply(ll a, ll b , ll mod) {
	return (a % mod * b % mod) % mod;
}

ll ModDivide(ll a, ll b , ll mod) {
	return (a % mod * ModMultiply(b, mod - 2, mod)) % mod;
}



void solve(){
	
}


int main(){

	fastIO

	int t ;
	// cin>>t;
	t = 1;
	while(t > 0){
		solve();
		t--;
	}

	return 0;
}
