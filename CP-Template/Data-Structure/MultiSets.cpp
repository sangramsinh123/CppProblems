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
// ll ModDivide(ll a, ll b , ll mod) { return (a % mod * BinExpo(b, mod - 2, mod)) % mod; }



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


void sets() {
	set<int> st; // Unique elements
	for (int i = 1; i <= 10; i++) {
		st.insert(i); // log(n)
	}
	// Traverse Through Sets
	for (auto it : st) {
		cout << it << " ";
	}
	cout << endl;

	// Find element in set
	auto it = st.find(1);// This is Iterator // log(n)
	if (it != st.end()) {
		cout << *(it)  << " ";
	}
	cout << endl;

	st.erase(*it); // This will also work st.erase(it); // log(n)

	for (auto it : st) {
		cout << it << " ";
	}
	cout << endl;
}


class cmp {
public:
	bool operator() (const int &a, const int &b)  const {
		return (a > b);
	}
};

// Substritution for Priority Queue
void Multiset(int n) {// It Internally Used Red-Black Tree
	multiset<int, cmp > ms;
	for (int i = 1; i <= n; i++) {
		ms.insert(i);// log(n)
		ms.insert(i);// log(n)
	}

	ms.erase(1); // It will delete all Ocuurence of val = 1

	auto it = ms.find(1); // This is Iterator // log(n)
	if (it != ms.end()) {
		ms.erase(it);// It will only delete first Ocuurence of val = 1
	}

	for (auto it : ms) {
		cout << it << " ";
	}
	cout << endl;
	cout << "First Element -> " << *(ms.begin()) << " "; // Output : 5
	cout << endl;
	cout << "Last Element  -> " << *(--ms.end()) << " "; // Output : 2
	cout << endl;
	cout << "First Element -> " <<  *(--ms.rend()) << " ";// Output : 5
	cout << endl;
	cout << "Last Element  -> " <<  *(ms.rbegin()) << " ";// Output : 2
}


int main() {
	// sets();
	int n;
	cin >> n;
	Multiset(n);
	return 0;
}

