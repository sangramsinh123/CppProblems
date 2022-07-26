class Solution {
public:
    
    #define pii pair<int,int>
    #define F first
    #define S second
    
    vector<int> nsl(vector<int>& arr, int n){
        stack<pii> st;//ele, idx
        vector<int> l(n);
        for(int i=0;i<n;i++){
            
            while(!st.empty() and st.top().F >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                l[i] = -1+1;
            }
            else{
                l[i] = st.top().S+1;
            }
            
            st.push({arr[i],i});
        }
        
        return l;
    }
    
    
    vector<int> nsr(vector<int>& arr, int n){
        
        stack<pii> st;//ele, idx
        vector<int> r(n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and st.top().F >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                r[i] = n-1;
            }
            else{
                r[i] = st.top().S-1;
            }
            
            st.push({arr[i],i});
        }
        
        return r;
    }
    
    
    int maximumScore(vector<int>& nums, int k) {
        //basically monotonic stack
        int n = nums.size();
        vector<int> l = nsl(nums,n);
        vector<int> r = nsr(nums,n);
    
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int li = l[i];
            int ri = r[i];
            
            if(li<=k and k<=ri){
                int t = nums[i]*(r[i]-l[i]+1);
                ans = max(ans,t);
            }
        
        }
        return ans;
        
    }
};

/*


1*6 = 6 (i=0 and j= 4) 



3*5 = 15 (i=1 and j= 5)

7*1 = 7 (i=3 and j= 3)

4*3 = 12 (i=3 and j= 5)


*/
