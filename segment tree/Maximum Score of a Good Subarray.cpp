class Solution {
public:
    
    vector<int> tree;
    
    //range minimum query 
    int build(vector<int>& nums, int root , int tl , int tr){
        //leaf
        if(tl == tr){
            tree[root] = nums[tl];
            return tree[root];
        }
        else{
            int tm = (tl+tr)/2;
            int leftMin = build(nums,2*root+1,tl,tm);
            int rightMin =build(nums,2*root+2,tm+1,tr);
            
            tree[root] = min(leftMin,rightMin);
            return tree[root];
        }
    
    }
    
    int query(int root , int l , int r, int tl, int tr){
        
        //out of range
        //[l.  r]
        if(l>tr or tl>r){
            return -1;
        }
        
        //totally inside
        if(l >= tl and tr >= r){ //[tl  l.    r  tr]
            return tree[root];
        }
        
        //partially 
        
            int m =( l+r)/2;
            int leftMin = query(2*root+1,l,m,tl,tr);
            int rightMin = query(2*root+2,m+1,r,tl,tr);
        
            if(leftMin == -1){
                return rightMin;
            }
            if(rightMin == -1){
                return leftMin;
            }
            return min(leftMin,rightMin);
        
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        tree = vector<int>(4*n,-1);
        
        build(nums,0,0,n-1);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i<=k and k<=j){
                    int mn = query(0,0,n-1,i,j);
                    
                    int t = mn*(j-i+1);
                    mx = max(mx,t);
                }
            }
        }
        return mx;
    }
};
