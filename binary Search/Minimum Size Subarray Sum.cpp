


class Solution {
public:
    #define ll long long
    bool check(int mid ,vector<int>& nums,int n,int t){
        ll sum=0;
        for(int i=0;i<mid;i++){
            sum+=nums[i];
        }
        
        if(sum>=t){
            return true;
        }
        
        for(int i=1;i+mid<=n;i++){
            int j = i+mid-1;
            
            sum+=nums[j];
            sum-=nums[i-1];
            
            if(sum>=t){
                return true;
            }
        }
        
        
        return false;
    }
    int minimumSize(vector<int> &nums, int target) {
        int n = nums.size();
        if(n==0){
            return -1;
        }
        int s = 0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s < target){
            return -1;
        }
        if(s == target){
            return n;
        }
        int lo = 1;
        int hi = n;
        int ans ;
        //FFFFTTTTT
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            
            if(check(mid,nums,n,target) == true){//true
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        
        return ans;
    }
};