class Solution {
public:

    // int lengthOfLongestSubstringKDistinct(string &s, int k) {
    //     // write your code here
    //     map<char,int> mp;
    //     int n = s.size();
    //     int j=0;
    //     int ans = 0;

    //     for(int i=0;i<n;i++){//acquire till i get 3rd distinct char
    //         char ch = s[i];
    //         mp[ch]++;

    //         //relase loop till my k is valid
    //         while(mp.size() > k ){
    //             //erase from map
    //             mp[s[j]]--;
    //             if(mp[s[j]] == 0){
    //                 mp.erase(s[j]);
    //             }
    //             j++;
    //         }
    //         //abs cal

    //         int len = (i-j+1);
    //         ans = max(ans,len);

    //     }

    //     return ans;
    // }

    int lengthOfLongestSubstringKDistinct(string &s, int k){
        
        int n = s.size();
        if(n==0){
            return 0;
        }

        int i=-1;
        int j=-1;
        int ans = 0;
        map<char,int> mp;//frequency map

        while(true){
            bool f1 = false;
            bool f2 = false;

             //acquire loop till it became invalid
            while(i<n-1){
                
                f1 = true;
                i++;
                char ch = s[i];
                mp[ch]++;
                if(mp.size() <= k){
                    int len = i-j;
                    ans = max(ans,len);
                }
                else{
                    break;
                }
                
            }

            //release loop till k is valid
            while(j<i){
                f2 = true;
                j++;
                char ch = s[j];
                mp[ch]--;// i assume that there freq >=1 till now
                if(mp[ch] == 0){
                    mp.erase(ch);
                }
                

                if(mp.size() > k){
                    continue;
                }
                else{
                    int len = i-j;
                    ans = max(ans,len);
                    break;
                }
                
            }

            if(f1 == false and f2 == false){
                break;
            }
        }

        return ans;
       
    }
};
