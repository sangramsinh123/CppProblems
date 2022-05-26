class Solution {
public:
    
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        map<char,int> mp;
        int n = s.size();
        int j=0;
        int ans = 0;
        for(int i=0;i<n;i++){//acquire till i get 3rd distinct char
            char ch = s[i];
            mp[ch]++;
            //relase loop
            while(mp.size() > 2 ){
                //erase from map
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
            }
            //abs cal

            int len = (i-j+1);
            ans = max(ans,len);

        }

        return ans;
    }
};