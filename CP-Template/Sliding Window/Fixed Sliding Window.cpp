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
const int mod = (int)1e9+7;




 
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ws = 3;
        int l = 0;
        int r = 0;
        map<int,int> mp;
        int cnt = 0;
        while(r<n){
            if(r-l+1 < ws){ // Fixed Window is small
                //STEP 1
                mp[s[r]]++;
                r++;
            }
            else if(r-l+1 == ws){// Fixed Window = Window size
                //STEP 2
                mp[s[r]]++;
                
                //STEP 3 (Answer calculation)
                if(mp.size() == ws){
                    cnt++;
                }
                //STEP 4 Remove ele from Left Ptr
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }


                l++;
                r++;

            }
        }

        return cnt;
    }
};
