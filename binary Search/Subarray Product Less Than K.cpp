class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        //binary Search
        //prefix array
        long long n = nums.size();
        vector<double> prefix(n);
        prefix[0] = log(nums[0]);
        double logK = log(k);
        for(long long i=1;i<n;i++){
            prefix[i] = prefix[i-1];
            prefix[i] += log(nums[i]);
        }
        long long ans = 0;

        for(long long j=0;j<n;j++){
            if(j==0){
                long long lo = j;
                long long hi = n-1;
                long long li = lo;
                while(lo<=hi){
                    long long mid = lo+(hi-lo)/2;
                    //TTTTTFFFFFFF
                    if((prefix[mid]) < logK){
                        lo = mid+1;
                        li = mid;
                    }
                    else{
                        hi = mid-1;
                    }
                }

                long long ws = li-j+1;
                cout << li <<" ";
                if(ws == 1){
                    if(nums[j] < k){
                        ans += 1;
                    }
                }
                else{
                    ans += ws;
                }
                
            }
            else{
                long long lo = j;
                long long hi = n-1;
                long long li = lo;
                while(lo<=hi){
                    long long mid = lo+(hi-lo)/2;
                    //TTTTTFFFFFFF
                    if((prefix[mid]) < (logK+prefix[j-1])){
                        lo = mid+1;
                        li = mid;
                    }
                    else{
                        hi = mid-1;
                    }
                }

                long long ws = li-j+1;
                cout << li <<" ";
                if(ws == 1){
                    if(nums[j] < k){
                        ans += 1;
                    }
                }
                else{
                    ans += ws;
                }
            }

        }
        return ans;

    }
};



/*
arr = [10,5,2,6]
prefix_arr = [10,50,100,600]


*/
