#include <bits/stdc++.h>
using namespace std;


#define pb push_back

void solve(vector<int> &a,int n, int k){
    map<int,int> fmap;
    vector<int> ans;
    for(int i=0;i<k;i++){
        fmap[a[i]]++;
        
    }
    ans.pb(fmap.size());
    
    for(int i=1;i+k<=n;i++){
        
        int j = i+k-1;
        fmap[a[j]]++;
        fmap[a[i-1]]--;
        
        if(fmap[a[i-1]] == 0){
            fmap.erase(a[i-1]);
        }
        
        ans.pb(fmap.size());
        
    }
    
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int k;
    cin>>k;
    
    solve(a,n,k);
    return 0;
}
