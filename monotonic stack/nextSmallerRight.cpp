#include <bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define f first
#define s second


vector<int> nextSmallerRight(vector<int> &nums,int n){
    
    stack<pii> is;//increasing Stack
    vector<int> r(n);
    for(int i=n-1;i>=0;i--){
        while(!is.empty() and (is.top().f >= nums[i])){
            is.pop();
        }
        
        if(is.empty()){
            is.push({nums[i],i});
            r[i] = -1;
            
        }
        else{
            r[i] = is.top().f;
        }
        
        if(is.top().f < nums[i]){
            is.push({nums[i],i});
        }
    }
    return r;
}


int main(){
    
    
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    vector<int> right = nextSmallerRight(nums,n);
    for(auto i: right){
        cout << i << endl;
    }
    return 0;
}
