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
const int mod = (int)1e9+7;




ll power(ll a, ll b){// a^b
	ll ans = 1;
	for(int i = 1;i<=b;i++){
		ans = (ans*a)%mod;
	}

	return ans;
}


// Binary Exponentianal
ll BinaryExponention(ll a, ll b){	
	if(b == 0){
		return 1;
	}

	ll base = BinaryExponention(a,b/2);
	ll ans = 1;
	if(b%2 == 1){
		ans = (base*base)%mod;
		ans = ans*a;
	}
	else{
		ans = (base*base)%mod;
	}

	return ans;
}



int main(){

	fastIO

	int t ;
	// cin>>t;
	t = 1;
	// while(t > 0){
	// 	solve();
	// 	t--;
	// }

	// cout << power(2,4 ) << endl;
	cout << BinaryExponention(2,10 ) << endl;
	return 0;
}
