class Solution {
    public int longestSubarray(int[] nums) {
        int z = 1;
        int l = 0;
        int n = nums.length;
        int ans = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int r = 0; r < n; r++){
            mp.put( nums[r] , (mp.getOrDefault(nums[r] , 0)) + 1);

            while((l<r) && ( mp.getOrDefault(0,0) > 1)){
                // remove the freq and increament
                mp.put(nums[l] , mp.get(nums[l])-1) ;
                if((mp.get(nums[l])) == 0){
                    mp.remove(nums[l]);
                }
                l++;
            }
            int len = r-l+1;
            ans = Math.max(ans,len);
        }
        if(ans == 0){
            return 0;
        }
        return ans-1;
    }
}
