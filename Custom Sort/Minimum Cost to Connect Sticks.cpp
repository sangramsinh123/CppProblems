



// class cmp{
// public:
//     bool operator() (const  int &a , const int &b){
//         if(a<b){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

class Solution {
public:
    //Multiset
    // int minimumCost(vector<int> &sticks) {
    //     // write your code here
    //     int ans = 0;
    //     int n = sticks.size();
    //     multiset<int,cmp> ms;
    //     for(int i=0;i<n;i++){
    //         ms.insert(sticks[i]);
    //     }

    //     while(ms.size() > 1){
    //         int t1 = *ms.begin();
    //         ms.erase(ms.begin());
    //         int t2 = *ms.begin(); 
    //         ms.erase(ms.begin());
    //         int c = t1+t2;
    //         ans+=c;
    //         ms.insert(c);
    //     }

    //     return ans;
    // }

    //priority Queue
    
    int minimumCost(vector<int> &sticks) {
        // write your code here
        int ans = 0;
        int n = sticks.size();
        auto compare = [](int &a,int &b) {
            return (a > b);
        };
        priority_queue< int,vector<int> ,decltype(compare)> pq(compare);
        for(int i=0;i<n;i++){
            pq.push(sticks[i]);
        }

        while(pq.size() > 1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top(); 
            pq.pop();
            int c = t1+t2;
            ans+=c;
            pq.push(c);
        }

        return ans;
    }
};