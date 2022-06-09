    //NEXT GREATER TO RIGHT
    vector<int> ngr(vector<int>& nums){//decreasng stack
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() and  nums[st.top()] < nums[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans[i] = (ans[i]-i);
        }
        return ans; 
    }
    
    //NEXT GREATER TO LEFT
    vector<int> ngl(vector<int>& nums){//decreasng stack
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and  nums[st.top()] <= nums[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i=n-1;i>=0;i--){
            ans[i] = (i-ans[i]);
        }
        return ans; 
        
    }
    
    //NEXT SMALLEST TO RIGHT
    vector<int> nsr(vector<int>& nums){//increasing stack
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() and  nums[st.top()] > nums[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans[i] = (ans[i]-i);
        }
        return ans;
    }
  
    //NEXT SMALLEST TO LEFT
    vector<int> nsl(vector<int>& nums){//increasing stack
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and  nums[st.top()] >= nums[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i=n-1;i>=0;i--){
            ans[i] = (i-ans[i]);
        }
        return ans;
    }
