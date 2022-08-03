/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


 class cmp{
public:
    bool operator() (const Interval a, const Interval b) {
        return (a.end <= b.end); 
    }
 };

  class cmp2{
public:
    bool operator() (const Interval a, const Interval b) {
        return (a.start <= b.start); 
    }
 };

class Solution {
public:
    //Brute Force
    // int minMeetingRooms(vector<Interval> &intervals) {
    //     vector<int> arr(1e5,0);
    //     int mx = 0;
    //     for(auto it:intervals){
    //         int s = it.start;
    //         int e = (it.end)-1;
    //         mx = max(mx,e);
    //         for(int i=s;i<=e;i++){
    //             arr[i] += 1;
    //         }
    //     }
    //     int ans = INT_MIN;
    //     for(int i=0;i<=mx;i++){
    //         // cout << arr[i] <<" ";
    //         ans = max(ans,arr[i]);
    //     }

    //     return ans;
    // }



    //using PQ/Multiset
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),cmp2());
        multiset<Interval,cmp> ms;//sort according to increasing order of ending time
        ms.insert(intervals[0]);
        int n = intervals.size();
        int ans = 1;
        for(int i=1;i<n;i++){
            //remove(or empty) all the rooms whose ending time is small than start time of current meeting
            int s = intervals[i].start;
            
            while(!ms.empty()){
                auto e = (*ms.begin()).end;
                if(e>s){
                    break;
                }
                else{
                    ms.erase(ms.begin());
                }
            }

            ms.insert(intervals[i]);
            int sz = ms.size();
            ans = max(ans,sz);

        }

        return ans;
    }
};










