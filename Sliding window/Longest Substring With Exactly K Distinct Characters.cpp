#include <bits/stdc++.h>
using namespace std;


#define pii pair<int,int>

#define f first
#define s second


class cmp{
public:
    bool operator() (const  int &a , const int &b) const {
        return (a<=b);
    }
};

int solve(string s, int k) {
    
    
    int n = s.size();
    
    int ans = 0;
    vector<pair<int,int>> store;
    map<char,int> fmap;
    
    //PEPCODING SUMIT SIR IDEA
    // int i=-1;
    // int j=-1;
    // while(true){
    //     bool f1 = false;
    //     bool f2 = false;
    //     //Aquire till it became invalid
    
    //     while(i<n-1){
    //         f1 = true;
    //         i++;
    //         char ch = s[i];
    //         fmap[ch]++;
            
    //         if(fmap.size() > k){
    //             break;            
    //         }
            
    //         int len = i-j;//??
    //         store.push_back((pair<int,int>){j,i});
    //         ans = max(ans,len);
    //     }
    
    
    //     //Release till it became valid
        
    //     while(j<i){
    //         f2 = true;
    //         j++;
    //         char ch = s[j];
    //         fmap[ch]--;
            
    //         if(fmap[ch] == 0){
    //             fmap.erase(ch);
    //         }
            
    //         if(fmap.size() <= k){
    //             break;
    //         }
            
    //         int len = i-j;
    //         store.push_back((pair<int,int>){j,i});
    //         ans = max(ans,len);
    //     }
        
    //     if(f1 == false and f2 == false){
    //         break;
    //     }
    // }
    
  
    //MY IDEA
    int j=0;
    for(int i=0;i<n;i++){//acquire till invalid
        fmap[s[i]]++;
        
        while(fmap.size() > k){//release till its valid
            
            fmap[s[j]]--;
            if(fmap[s[j]] == 0){
                fmap.erase(s[j]);
            }
            j++;
        }
        
        int len = i-j+1;
        ans = max(ans,len);
    }
    
    return ans;
        
}
    
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
	cout << solve(s,k);
	return 0;
}


