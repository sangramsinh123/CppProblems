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
const int mod = (int)1e9+9;


class Solution {
public:

    ll hash(string s){
        ll prime = 31;
        ll p_pow = 1;
        ll hashValue = 0;
        for(char ch : s){
            hashValue = (hashValue + (ch-'a'+1)*p_pow)%mod;
            p_pow = (p_pow*prime)%mod;
        }

        return hashValue;
    }
    int strStr(string s, string p) {
        fastIO
        int n = s.size();
        // STEP 1
        ll hp = hash(p);
        // STEP 2
        vector<ll> PrefixHash(n);
        ll prime = 31;
        // STEP 3
        vector<ll> powerArray(n);
        
        for(int i = 0;i<n;i++){
            if(i == 0){
                powerArray[0] = 1;
                PrefixHash[i] = ((s[i]-'a'+1)*powerArray[0])%mod;
            }
            else{
                powerArray[i] = (powerArray[i-1]*prime)%mod ;
                PrefixHash[i] = (PrefixHash[i-1]+((s[i]-'a'+1)*powerArray[i])%mod)%mod;
            }
        }



        int idx = -1;
        int m = p.size();
        //01234567
        
        for(int i = 0;i<=(n-m);i++){
            int j = i+m-1;
            // STEP 4
            ll currHash = (i>=1) ? (PrefixHash[j]-PrefixHash[i-1]+mod)%mod : (PrefixHash[j])%mod;
            // STEP 5
            ll leftSide = (hp*powerArray[i])%mod; // IMPORTANT

            // STEP 6
            if(currHash == leftSide){
                return i;
            }
        }
        return -1;
    }
};

