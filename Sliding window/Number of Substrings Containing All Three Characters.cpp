// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         map<char,int> mp;
//         int j=-1,i=-1;
//         int c=0;
//         while(true){
//             bool f1 = false,f2 = false;
            
//             //acquire
//             while(i<n-1){
//                 f1=true;
//                 i++;
//                 char ch = s[i];
//                 mp[ch]++;
//                 //break when we got at least 1 occurences of each element  
//                 if(mp['a'] > 0 and mp['b'] >0 and mp['c']>0){
//                     c+=(n-i);
//                     break;
//                 }
                
//                 //
//             }
            
//             while(j<i){
//                 f2 = true;
//                 j++;
                
//                 char ch = s[j];
//                 mp[ch]--;
//                 if(mp[ch] == 0){
//                     mp.erase(ch);
//                 }
//                 if(mp['a'] == 0 or mp['b'] == 0 or mp['c']==0){
//                     break;
                    
//                 }
//                 //this loop break when at least 1 of them is not there
//                 if(mp['a'] > 0 and mp['b'] >0 and mp['c']>0){
//                     c += (n-i);
                    
//                 }
                
                
                
//             }
            
//             if(f1==false and f2 == false){
//                 break;
//             }
//         }
//         return c;
        
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int> mp;
        int j=0;
        int c=0;
        for(int i=0;i<n;i++){
            //acquire untill it is invalid
            mp[s[i]]++;

            //relase till it is valid
            while(j<i and mp['a'] > 0 and mp['b']>0 and mp['c']>0){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
                c+=(n-i);
                
            }
            //collect ans;
            if(mp['a'] > 0 and mp['b']>0 and mp['c']>0){
                c+=(n-i);
            }
            
        }
        
        return c;
        
    }
};

/*
5-2= 3
012345
abccca
j i...
*/
