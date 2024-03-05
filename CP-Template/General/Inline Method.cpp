// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



int func(int &a){
    //cal
    //lambda function
    auto squareCal = [&](int a){
        return a*a;
    };
    int ans = squareCal(a);
    
    return ans;
}

int main() {
    // Write C++ code here
    int a = 10;
    
    cout << func(a)<< endl;

    return 0;
}
