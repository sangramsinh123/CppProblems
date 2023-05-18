import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution 
{
	public static ArrayList<Integer> countDistinct(ArrayList<Integer> arr, int n, int k) 
    {
        // Write your code here
        int ws = k;
        Map<Integer, Integer> mp = new HashMap<>();

        for(int i =0;i<ws;i++){
            mp.put(arr.get(i) , mp.getOrDefault(arr.get(i), 0) + 1);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(mp.size());
        for(int i=1;i<=n-ws;i++){
            // remove i-1
            mp.put(arr.get(i-1) , mp.get(arr.get(i-1)) - 1);
            if(mp.get(arr.get(i-1)) == 0){
                mp.remove(arr.get(i-1));
            }
            int r = i+ws-1;
            // add r
            mp.put(arr.get(r) , mp.getOrDefault(arr.get(r), 0) + 1);
            ans.add(mp.size());

        }

        return ans;
    }
}


