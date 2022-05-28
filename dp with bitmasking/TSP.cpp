#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);


/*

Brute force solution:

Try out all the possibilities
(N-1)*(N-2)*(N-3).......1
TC: O((N-1)!) it will not work for n=10



*/


class Bruteforce{
public:

	int TSP(int** costMatrix,int n){// return shortest path sum

		int source = 1;
		vector<int> nodes;
		for(int i=1;i<=n;i++){
			if(i!= source){
				nodes.push_back(i);
			}
			
		}

		int n = nodes.size();

		while(next_permutation(nodes.begin(),nodes.end())){
			
		}

		int ans = INT_MAX;



		return ans;
	}
};




int distanceMatrix[21][21];
int n;
int dp[21][1<<21];

int solve(int i,int mask){//mask = how many cities are available to meet to visit and i = current city

	/*
	base case

	when i dont have any cities to visit

	*/
	if(mask==0){
		return 0;
	}

	//overlapping state
	if(dp[i][mask] != -1){
		return dp[i][mask];
	}

	int ans = INT_MAX;

	for(int j=1;i<=n;j++){

		if(i!=j and (mask&(1<<j))){//if it is not same city and it is not visited earlier(i.e jth bit available)
			ans = min(ans,solve(i+1,mask^(1<<j)));
		}

	}
	dp[i][mask] = ans;
	return dp[i][mask] ;
}

int32_t main(){
	fast_io;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>distanceMatrix[i][j];
		}
	}


	cout << solve(1,(1<<n));//???? (1<<n)-1
	return 0;
} 