class Solution {
public:
    
    int lengthOfLongestSubstring(string &s) {
        
        //acquire till i get invalid
        //release till it is valid
        int n = s.size();
        vector<int> mp(256,0);
        int ans = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;//acquire
            //release
            while(i<j and mp[s[j]] >= 2){
                mp[s[i]]--;
                
                i++;
            }
            int len = j-i+1;
            ans = max(ans,len);
        }

        return ans;
    }
};
