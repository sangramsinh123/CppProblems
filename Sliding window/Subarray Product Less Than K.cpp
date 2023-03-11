class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //acquire till is invalid
        //relase till is valid
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int curr = 1;
        int i=0,j=0;
        int ans = 0;
        while(j<n){
            curr *= nums[j];
            j++;
            while(i<j and curr>=k){
                curr /= nums[i];
                i++;
            }
            ans += j-i;
        }

        return ans;
    }
};
