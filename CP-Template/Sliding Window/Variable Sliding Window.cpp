#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define inf INT_MAX
#define N_inf INT_MIN
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int mod = (int)1e9+9;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        fastIO
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 0;
        unordered_map<char,int> mp;
        while(r<n){
            //STEP 1 (Take the Right ptr element)
            mp[s[r]]++;
            //STEP 2 (Breaking Condition -> This Cond fails for [l...r] so shrink left Ptr) 
            while(l<r && mp[s[r]] > 1){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            //STEP 3 (Answer calculation Step) -> If Breaking condition fails i.e valid Window then cal Ans 
            len = max(len,r-l+1);
            //STEP 4 Incrment right ptr
            r++;
        }

        return len;
    }
};
