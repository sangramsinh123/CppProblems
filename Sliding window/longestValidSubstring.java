class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        int n = word.length();
        Set<String> st  = new HashSet<>();
        int mxSize = 0;
        for(String s : forbidden){
            st.add(s);
            mxSize = Math.max(mxSize,s.length());
        }

        int l = 0;
        int ans = 0;
        for(int r = 0;r<n;r++){
            for(int i = r ;i>r-mxSize && i>=l;i--){
                if(st.contains(word.substring(i, r+1))){
                    l = i+1;
                    break;
                }
            }
            int len = r-l+1;
            ans = Math.max(ans,len);
        }

        return ans;
    }
}
