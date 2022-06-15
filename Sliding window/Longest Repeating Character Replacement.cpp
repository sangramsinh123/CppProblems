class Solution {
public:
    
    bool check(int mid , string &s,int k,int n){
        //window size = mid
        //most frequent element(f)-mid <= k the return true
        int windowSize  = mid;
        
        vector<int> freq(26,0);
        int mx = 0;
        char mfc ;
        for(int i=0;i<windowSize;i++){
            freq[s[i]-'A']++;
            
            if(freq[s[i]-'A'] > mx){
                mx = freq[s[i]-'A'];
                mfc = s[i];
            }
            
        }
        // int mx = *max_element(freq.begin(),freq.end());
        if((windowSize-mx) <= k){
            return true;
        }
        
        //0 1 2 3 4 5
        for(int i=1;i<=n-windowSize;i++){
            int j = i+windowSize-1;
            freq[s[i-1]-'A']--;
            if(mfc == s[i-1]){
                mx--;
            }
            freq[s[j]-'A']++;
            if(s[j] == mfc){
                mx++;
            }
            
            if(freq[s[j]-'A'] > mx){
                mx = freq[s[j]-'A'];
                mfc = s[j];
            }
            
            
            // mx = *max_element(freq.begin(),freq.end());
            if(windowSize-mx <= k){
                return true;
            }
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        
        
        if(s.size() == 0){
            return 0;
        }
        int n = s.size();
        int lo = 1;
        int hi = n;
        
        int ans = lo;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid,s,k,n)){//true
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        
        return ans;
    }
};

/*

At most k diff characters
are allowed in this window

TTTTTTTFFFFFFF


if(){
    ans = mid;
    lo = mid+1;
}
else{
    hi = mid-1
}

return ans;
*/
