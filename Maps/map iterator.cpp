// class Solution {
// public:
//     string restoreString(string s, vector<int>& indices) {
//         map<int,char> fmap;
        
//         for(int i=0;i<s.size();i++){
//             fmap[indices[i]]=s[i];
            
//         }
        
//         string ans="";
//         for(int i=0;i<s.size();i++){
//             ans.push_back(fmap[i]);
//         }
        
//         // map<int,char>::iterator itr;
//         // for(itr = fmap.begin() ; itr != fmap.end();itr++){
//         //     //cout << (char)(i.first) << " " << i.second <<endl;
//         //     cout << itr->first << " " << itr->second <<endl;
//         // }
        
//         for(const auto &itr:fmap){
//             cout << itr.first <<" " << itr.second <<endl;
//         }
        
//         return ans;
//     }
// };








class Solution {
public:
    string restoreString(string s, vector<int>& indices){
        vector<pair<int,char>> fmap(s.size());
        string ans="";
        for(int i=0;i<s.size();i++){
            fmap[i].first = indices[i] ;
            fmap[i].second =s[i] ;
        }
        
        sort(fmap.begin(),fmap.end());
        
        for(int i=0;i<s.size();i++){
            ans.push_back(fmap[i].second);
        }
        
        return ans;
        
    }
};
