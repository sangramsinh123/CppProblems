// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

#define ll long long int


int main() {
    
    cout << min(2,3) << endl;//O/P = 2
    
    //For multiple comparision do like this
    cout << min({2,3,5,1})<< endl;//O/P = 1
    
    cout << max({2,3,5,1})<< endl;//O/P = 5
    //ONLY Applicable to int only and not for long long int
    cout << max({2,3,5,1,1000000000}) << endl;//O/P = 1000000000
    return 0;
}
