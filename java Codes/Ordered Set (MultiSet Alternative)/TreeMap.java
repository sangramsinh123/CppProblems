class Solution {
    public long continuousSubarrays(int[] nums) {
        long ans = 0;
        int n = nums.length;
        int r = 0;
        int l = 0;
        TreeMap<Integer,Integer> tmp = new TreeMap<>();
        while(r<n){
            tmp.put(nums[r], tmp.getOrDefault(nums[r], 0)+1);
            r++;

            while((tmp.lastEntry().getKey()-tmp.firstEntry().getKey()) > 2){
                tmp.put(nums[l], tmp.getOrDefault(nums[l], 0)-1);
                if(tmp.get(nums[l]) == 0){
                    tmp.remove(nums[l]);
                }
                l++;
            }

            ans += (r-l);
        }
        return ans;
    }
}
