/*

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.
You're going to share this chocolate with K friends, so you need to cut K times to get K + 1 pieces, each of which is 
made up of a series of small pieces.
Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.
Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]


Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.

*/




class Solution {
public:

    bool check(vector<int> &arr, int &k, int &n , int mid){
        int chucks = 0;
        int CurrSum = 0;
        for(int i=0;i<n;i++){
            CurrSum += arr[i];
            if(CurrSum >= mid){
                CurrSum = 0;
                chucks++;
            }
        }

        return (chucks >= (k+1));
    }
    int maximizeSweetness(vector<int> &arr, int k) {
        int n = arr.size();

        //TTTTTTFFFFFFF

        int lo = 0;
        int hi = 1000000009;
        int ans = lo;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(arr,k,n,mid)){//true
                lo = mid+1;
                ans = mid;
            }
            else{
                hi = mid-1;
            }
        }

        return ans;
    }
};
