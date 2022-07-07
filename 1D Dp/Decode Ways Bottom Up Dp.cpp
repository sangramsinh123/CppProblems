class Solution {
public:
    
    
    int BottomUpDP(string &s){
        int n = s.size();
        
        vector<int> dp(n,0);
        
        dp[0] = s[0]=='0'?0:1 ;
        
        for(int i=1;i<n;i++){
            //0 0
            if(s[i-1] == '0' and s[i] == '0'){
                dp[i] = 0;
            }
        
            //!0 0(take care of <= 26)
            else if(s[i-1]-'0' >= 1 and s[i] == '0'){
                if(stoi(s.substr(i-1,2)) <= 26){
                    dp[i] = ((i>=2)?dp[i-2]:1);//10 or 20 
                }
                else{
                    dp[i] = 0;
                }
            }
            //0 !0
            else if(s[i-1]-'0' == 0 and s[i]-'0' >= 1){//01 02 
                dp[i] = dp[i-1];
            }
            //!0 !0(take care of <= 26)
            else{//21 22 26 but not 27
                if(stoi(s.substr(i-1,2)) <= 26){
                    dp[i] = dp[i-1]+((i>=2)?dp[i-2]:1);//10 or 20 
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
        }
        
        return dp[n-1];
    }
    int numDecodings(string s) {
        int ans =  BottomUpDP(s);
        
        return ans;
    }
};
