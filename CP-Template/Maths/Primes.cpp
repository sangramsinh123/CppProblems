#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define inf INT_MAX
#define N_inf INT_MIN
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int mod = (int)1e9+7;


// const int MAXN = 1e6;
vector<bool> factors;
void sieve(int n){
	for(int num = 2;num <=n;num++){
		if(factors[num]){
			continue;
		}
		for(int j = 2*num;j<=n;j += num){
			factors[j] = true;
		}
	}
}

class Solution {
public:
    int countPrimes(int n) {
        factors = vector<bool>(n+1);
        sieve(n);

        int cnt = 0;
        for(int i = 2;i<n;i++){
            if(factors[i] == false){
                cnt++;
            }
        }

        return cnt;
    }
};
