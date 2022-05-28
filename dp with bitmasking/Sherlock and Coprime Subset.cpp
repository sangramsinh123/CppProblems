#include <bits/stdc++.h>
using namespace std;



#define int long long
int n;
vector<int> A;
int dp[21][1<<20];

//01 knapsack problem

int rec(int i , int mask){

	//base case (when we have only 2 members left)
	if(i==n){
		return 0;
	}
	//visited case
	if(dp[i][mask] != -1){
		return dp[i][mask];
	}
	int ans = rec(i+1,mask);
	for(int j=0;j<n;j++){

		if((mask&(1<<j)) != 0){//jth bit is set then continue
			continue;
		}
		else{
			//coprime condition check with jth bit
			if( __gcd(A[i],A[j]) == 1){
				ans = max(ans,rec(i+1,mask^(1<<j)));
			}
			
		}

	}

	dp[i][mask] = ans;

	return dp[i][mask];
}

void solve(){
	cin>>n;
	A = vector<int> (n);
	memset(dp,-1,sizeof(dp));
	for ( int i = 0; i < n; i++ ) {
		cin >> A[i];
	}
	
	int ans = rec(0,0);

	cout << ans << endl;
}


int32_t main(){
	//take input 

	int tc;
	cin>>tc;

	while(tc--){
		solve();
	}

	return 0;
}