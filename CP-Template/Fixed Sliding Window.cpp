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
    vector<int> getSubarrayBeauty(vector<int>& nums, int windowSize, int x) {
        fastIO
        int n = nums.size();
		int l = 0;
		int r = 0;
		vector<int> ans;
		vector<int> mp(51,0);
		while(r<n){
			if(r-l+1 == windowSize){
				if(nums[r] < 0){
                    mp[nums[r]*(-1)]++;
                }
                // cout << l << " " << r << endl;
				// cal ans
                int x_dash = x;
                bool f = false;
				for(int j = 50;j>=1;j--){
                    if(mp[j] > 0){
                        x_dash -= mp[j];
                        if(x_dash <= 0){
                            ans.pb(j*(-1));
                            f = true;
                            break;
                        }
                    }
                }
                if(!f){
                    ans.pb(0);
                }

                if(nums[l] < 0){
                    if(mp[nums[l]*(-1)] > 0){
                        mp[nums[l]*(-1)]--;
                    }
                }

				
				l++;
				r++;
			}
			else if(r-l+1 < windowSize){
				if(nums[r] < 0){
                    mp[nums[r]*(-1)]++;
                }
                r++;
			}
		}

		return ans;
    }
};
