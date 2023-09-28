


class cmp implements Comparator<Integer>{
    public int compare(Integer a, Integer b){
        if(a%2 == 0){
            return -1;
        }
        else if(b%2 == 0){
            return 1;
        }
        return 0;
    }
}

class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int n = nums.length;
        Integer[] arr = new Integer[n];
        for(int i = 0;i<n;i++){
            arr[i] = nums[i];
        }
        Arrays.sort(arr,new cmp());
        for(int i = 0;i<n;i++){
            nums[i] = arr[i];
        }
        return nums;
    }
}
