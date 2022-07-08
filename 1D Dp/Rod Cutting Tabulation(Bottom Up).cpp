#include <bits/stdc++.h>
using namespace std;




int main(){
    
    int n;
    cin>>n;
    
    vector<int> price(n+1);
    for(int i=1;i<=n;i++){
        cin>> price[i];
    }
    //Partioning stratergy 
    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = price[1];
    for(int i=2;i<=n;i++){
        int mx = INT_MIN;
        int len = i;
        for(int j=1;j<=i;j++){
            int t = price[j]+dp[len-j];
            mx = max(mx,t);
        }
        dp[i] = mx;
    }
    
    cout << dp[n] << endl;
    return 0;
}
