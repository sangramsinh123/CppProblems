// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

#define pb push_back


// COMPARATOR ---------------------------------------------
class cmp{
public: 
    bool operator() (const int &a, const int &b){
        return a>b;
    }
};


int main() {
    vector<int> nums;
    nums.pb(15);
    nums.pb(1);
    nums.pb(13);
    nums.pb(10);
    
    sort(nums.begin(),nums.end(),  cmp());
    for(int i = 0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}


// ------------------------------------------------------------


int main() {
    vector<int> nums;
    nums.pb(15);
    nums.pb(1);
    nums.pb(13);
    nums.pb(10);
    
    sort(nums.begin(),nums.end(),  [&](const int &a, const int &b){
        return a>b;
    });
    for(int i = 0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}

// FUNCTION ------------------------------------------------------------

bool cmp(const int &a, const  int &b){
    return a>b;
}
int main() {
    vector<int> nums;
    nums.pb(15);
    nums.pb(1);
    nums.pb(13);
    nums.pb(10);
    
    sort(nums.begin(),nums.end(),&cmp);
    for(int i = 0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}
