import java.util.* ;
import java.io.*; 
public class Solution {
        
	public static int lengthOfLongestSubstring(String s) {
		// Write your code here.
		int n = s.length();
		int ans = 0;
		Map<Character, Integer> mp = new HashMap<>();
		int l = 0;
		for(int r=0;r<n;r++){
			mp.put(s.charAt(r), mp.getOrDefault(s.charAt(r) ,0)+1);

			//
			while((l<r) && (mp.get(s.charAt(r)) >= 2 )){
				// remove s[l] from mp
				mp.put(s.charAt(l) , mp.get(s.charAt(l)) -1 );
				if(mp.get(s.charAt(l)) == 0){
					mp.remove(s.charAt(l));
				}
				l++;
			}

			int len = r-l+1;
			ans = Math.max(ans, len);
		}

		return ans;
	}
}
