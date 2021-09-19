#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char,vector<char>> map;
    map.insert({'a',{'e'}});
    map.insert({'e',{'a','i'}});
    map.insert({'i',{'a','e','o','u'}});
    map.insert({'o',{'i','u'}});
    map.insert({'u',{'a'}});
    
    
    //using range based for loop
    for(const auto &i:map){
        cout << i.first << "->";
        for(auto &j : i.second){
            cout << j <<" ";
        }
        cout << endl;
    }
    
    
    //using iterators
    for(auto it = map.begin() ;it != map.end(); it++){
        cout << it->first << "->";
        for(auto it2 = it->second.begin() ;it2 !=it->second.end() ; it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    
    //range-based loop for map, subscript operator for vector
    for(const auto &i : map){
        cout << i.first << "->";
        for(auto j=0; j< i.second.size();j++){
            cout << i.second[j] << " ";
        }
        cout << endl;
    }
    
    
	return 0;
}