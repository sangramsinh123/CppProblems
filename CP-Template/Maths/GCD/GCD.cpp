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


// TC : log(min(a,b))
int EuclidGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	a = a % b;
	if (a >= b) {

	} else {
		swap(a, b);
	}

	return EuclidGcd(a, b);
}

// ax + by = gcd(a,b) -> Linear Diophatine Eqn -> To find This Eqn we used Extended Euclid's Algo
pair<int, int> extended_gcd(int a, int b) {
	if (b == 0) {
		return {1, 1};
	}

	pair<int, int> p = extended_gcd(b, a % b);
	int x2 = p.F;
	int y2 = p.S;

	int x = y2;
	int y = x2 - (floor(a / b) * y2);

	return {x, y};
}


int main(){

	fastIO
	cout << gcd(12,5)<<endl;
	return 0;
}
