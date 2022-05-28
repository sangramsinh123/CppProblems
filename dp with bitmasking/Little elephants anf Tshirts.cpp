#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define int long long
int dp[102][1026];
bool arr[11][102];

int n;
int rec(int i,int mask){//i = tshirt , mask = n peoples
	//base case
	if(i==101){
	    if(mask == 0){
			return 1;
	    }
		return 0;
	
	}

	if(dp[i][mask] != -1){
		return dp[i][mask];
	}

	//opt1 
	int opt1 = rec(i+1,mask);
	//opt2 
	int opt2=0;
	for(int j=0;j<n;j++){
	    
	    if((mask&(1<<j)) != 0){//jth bit is set saw the eulers tree i have draw
	       if(arr[j][i]){
	           opt2 += rec(i+1,mask^(1<<j));
	       }
	    }
	    else{
	        continue;
	    }
		
	}

	dp[i][mask] = (opt1+opt2)%mod;

	return dp[i][mask];
}

void solve(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	memset(arr,false,sizeof(arr));
	string line;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,line);
		stringstream ss(line);
		int temp;
		while(ss>>temp){
			arr[i][temp] = true;
		}	
	}
	int mask = 0;
	for(int i=0;i<10;i++){
	    //set the ith bit
	    mask = mask^(1<<i);
	}
	cout << rec(1,mask) << endl;
}

signed main()
{
	int tc;
	cin>>tc;

	while(tc--){
		solve();
	}
	return 0;
}
