// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
//SC = O(N)
//TC = O(N*N)
class Solution{
  public:
    vector<int> price;
    vector<int> dp;
    int rec(int n,int len){
    	if(len == 0){
    		return 0;
    	}
    	if(dp[len] != -1){
    	    return dp[len];
    	}
    	int mx = INT_MIN;
    	for(int i=1;i<=len;i++){
    		int t = price[i-1]+rec(n,len-i);
    		mx = max(mx,t);
    	}
        dp[len] = mx;
    	return dp[len];
    }
    int cutRod(int p[], int n) {
        //code here
        
        price = vector<int>(n);
        dp = vector<int>(n+1,-1);
        for(int i=0;i<n;i++){
            price[i] = p[i];
        }
        int ans = rec(n,n);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
