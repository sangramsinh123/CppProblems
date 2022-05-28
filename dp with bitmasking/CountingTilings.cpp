#include <bits/stdc++.h>
using namespace std;


#define mod 1000000007
int dp[1001][1025];

int n,m;




void genrate_Mask(int curr_mask , int i,int next_mask, vector<int> possibleNextMask){

	//base case
	if(i==n+1){
		possibleNextMask.push_back(next_mask);
		return;
	}

	if((curr_mask&(1<<i)) != 0 ){
		genrate_Mask(curr_mask,i+1, next_mask,possibleNextMask);
	}

	if((curr_mask&(1<<i))==0 and (curr_mask&(1<<(i+1))) == 0 and i!=n){
		genrate_Mask(curr_mask,i+2, next_mask,possibleNextMask);
	}

	if((curr_mask&(1<<i))==0){
		genrate_Mask(curr_mask,i+1, next_mask^(1<<i),possibleNextMask);//set ith bit in next_mask
	}
}
int rec(int i,int mask){
	//base case
	if(i==m+1){
		if(mask == 0){
			return 1;
		}
		else{
			return 0;
		}

	}
	if(dp[i][mask] != -1){
		return dp[i][mask];
	}

	vector<int> possibleNextMask ;
	genrate_Mask(mask,1,0,possibleNextMask);
	//check out every possibleity of 
	int ans = 0;
	for(auto m:possibleNextMask){
		ans+=(rec(i+1,m))%mod;
	}


	dp[i][mask] = ans;
	return dp[i][mask];
}


void solve(){
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	cout << rec(1,0) << endl; 

}

signed main(){
	int tc;
	//cin>>tc;
	tc=1;
	while(tc--){
		solve();
	}

	return 0;
}