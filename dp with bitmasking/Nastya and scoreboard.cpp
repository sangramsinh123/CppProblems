#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long


ll maxi = -1:
ll AppendNumbers(ll a,ll b){
	return (a*10)+b;
}

ll max(ll a,ll b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}

}

ll change(ll i){
	vector<string> = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<int> countOfUnsetBit = {};
	return countOfUnsetBit[i];
}
int n,k;
int change[2001][10];
int dp[2001][2001];

ll rec(ll row , ll k){

	if(row == n){
		return (k==0);
	}

	for(ll i=9;i>=0;i--){//for curr row check every number is possible or not
		//2 conditions
		if(change[row][i] != -1){//if it is possible to make i number
			if(change[row][i]<=k){

			}
			else{
				dp[row][k] = 0;
			}
		}	
		
	}
}

int32_t main(){
	ll n,k;
	cin>>n>>k;
	memset(change,-1,sizeof(change));
	memset(dp,-1,sizeof(dp));
	vector<string> arr(n);
	string t;
	for(ll i=0;i<n;i++){
		cin>>t;
		arr.push_back(t);
	}

	for(int ind=0;ind<n;ind++){
		for(int i=0;i<=9;i++){
			string s1 = digit[i];
			string s2 = arr[ind];
		}
	}
	string s = ""
	cout << rec(0,k,s) << endl;
	return 0;
}