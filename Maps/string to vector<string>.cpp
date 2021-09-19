#include <bits/stdc++.h>
using namespace std;



vector<string> solve(string s){
    
    vector<string> ans;
    stringstream ss(s);
    string word;
    while(ss >> word){
        ans.push_back(word);
    }
    return ans;
}

int main() {
    string s;
    getline(cin,s);
    //cin>>s;//dont use this 
    vector<string> ans = solve(s);
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
	//cout<<"GfG!";
	return 0;
}