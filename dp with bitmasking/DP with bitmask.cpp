#include <bits/stdc++.h>
using namespace std;


#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int costMatrix[21][21];
int n;
int dp[21][1<<21];// for the purpose of storage

int solve(int i,int bitmask){

	if(i==n){
		return 0;
	}
	//if dp[i][bitmask] != empty then return it
	if(dp[i][bitmask] != -1){
		return dp[i][bitmask];
	}
	int ans = INT_MAX;
	for(int j=0;j<n;j++){//i = people
		if((bitmask & (1<<j))){// if jth bit is set
			ans = min(ans , costMatrix[j][i] + solve(i+1,bitmask^(1<<j)));
		}
	}

    dp[i][bitmask] = ans;
	return dp[i][bitmask];
}

int32_t main(){
    fast_io;
   // int n;
	cin>>n;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>costMatrix[i][j];
		}
	}

	cout << solve(0,(1<<n)-1) ;

	return 0;
}