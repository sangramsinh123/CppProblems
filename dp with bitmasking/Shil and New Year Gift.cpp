#include <bits/stdc++.h>
using namespace std;



#define int long long
int n;
int dp[1<<15][15];
int A[16];
int rec(int mask , int i){


	//base case
	if(mask == (1<<n)-1){
		return 0;
	}
	//visited case
	if(dp[mask][i] != -1){
		return dp[mask][i];
	}

	int ans = 0;
	for(int j=0;j<n;j++){
		if((mask&(1<<j)) == 1){//mask constains jth bit then do not do anything and move on
			continue;
		}
		else{
			//check for gcd contition
			ans = max(ans, __gcd(A[i],A[j]) + rec(mask|(1<<j) , j));
		}
	}

	dp[mask][i] = ans;
	return dp[mask][i];
}

int32_t main(){
	//take input 

	cin>>n;
	memset(dp,-1,sizeof(dp));
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans,rec(1<<i,i));
	}

	cout << ans << endl;

	return 0;
}