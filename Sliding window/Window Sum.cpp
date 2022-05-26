class Solution {
public:
    #define ll long long
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        ll sum=0;
        vector<int> ans;
        int n = nums.size();
        if(n==0){
            return ans;
        }
        if(k==1){
            return nums;
        }
        
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans.push_back(sum);
        int j;
        for(int i=1;i+k<=n;i++){
            int j = i+k-1;
            sum += nums[j];
            sum -= nums[i-1];
            ans.push_back(sum);
        }

        return ans;
    }
};
