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



ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	else{
		a = a%b;
		if(a>=b){

		}
		else{
			swap(a,b);
		}
		return gcd(a,b);
	}
}



int main(){

	fastIO
	cout << gcd(12,5)<<endl;
	return 0;
}
