// class Solution {
// public:
//     int totalFruit(vector<int>& arr) {
//         int n = arr.size();
//         int k=2;
//         int j=0;
//         map<int,int> mp;
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             //acquire till it is invalid
//             mp[arr[i]]++;
            
//             //relase till it is valid
//             while(j<i and mp.size() > 2){
//                 mp[arr[j]]--;
//                 if(mp[arr[j]] == 0){
//                     mp.erase(arr[j]);
//                 }
//                 j++;
                
//             }
            
//             //collect ans
//             int len = i-j+1;
//             ans = max(ans,len);
            
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int k=2;
        int j=-1,i=-1;
        map<int,int> mp;
        int ans = 0;
        
        while(true){
            bool f1 = false,f2 = false;
            //acquire
            while(i<n-1){
                f1 = true;
                i++;
                mp[arr[i]]++;

                if(mp.size() > 2){
                    break;
                }

                int len = i-j;
                ans = max(ans,len);
            }

            //relase
            while(j<i){
                f2 = true;
                j++;
                mp[arr[j]]--;
                if(mp[arr[j]] == 0){
                    mp.erase(arr[j]);
                }
                if(mp.size() <= 2){
                    break;
                }
                

                int len = i-j;
                ans = max(ans,len);
                
            }
            
            if(f1==false and f2 == false){
                break;
            }
        }
        return ans;
    }
};
