#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 998244353
const int N = 1002 ;

ll dp[N][(2*N)][2][2]; // 2*N states because black and white are like in chess board.link : https://www.iconfinder.com/icons/4234910/board_chess_game_grid_sport_tile_tool_icon

ll n,k;
ll rec(ll i,ll components ,ll p1,ll p2){//p1 = black , int p2 = white

     //base case
     if(i==n){
          return (components==k);
     }
     //already visisted
     if(dp[i][components][p1][p2] != -1){
          return dp[i][components][p1][p2];
     }

     //i will calulate for all combinatios
     ll curr = 0;
     if(p1 == p2){
          curr = (curr + rec(i+1,components+1,p1,p2^1))%mod;
          curr = (curr + rec(i+1,components+1,p1^1,p2))%mod;
          curr = (curr + rec(i+1,components,p1,p2))%mod;
          curr = (curr + rec(i+1,components+1,p1^1,p2^1))%mod;
     } 
     else{
          curr = (curr + rec(i+1,components,p1^1,p2))%mod;
          curr = (curr + rec(i+1,components+2,p1^1,p2^1))%mod;
          curr = (curr + rec(i+1,components,p1,p2^1))%mod;
          curr = (curr + rec(i+1,components,p1,p2))%mod;

     }

     dp[i][components][p1][p2] = (curr)%mod;
     return dp[i][components][p1][p2];
}

void solve(){
     memset(dp,-1,sizeof(dp));
     cin>>n>>k;
     ll ans = 0;
     ans = (ans+rec(1,2,1,0))%mod ;// rec(start= 1, componnets till now= 2,cell(1,1) = white,cell(2,1) = black)
     ans = (ans+rec(1,2,0,1))%mod;// rec(start= 1, componnets till now= 2,cell(1,1) = black,cell(2,1) = white)
     ans = (ans+rec(1,1,0,0))%mod;// rec(start= 1, componnets till now= 1,cell(1,1) = black,cell(2,1) = black)
     ans = (ans+rec(1,1,1,1))%mod;// rec(start= 1, componnets till now= 1,cell(1,1) = white,cell(2,1) = white)

     cout << (ans)%mod << endl;
     
}

int32_t main(){

     fast_io;

     ll tc=1;
     while(tc--){
          solve();
     }

     return 0;
}




