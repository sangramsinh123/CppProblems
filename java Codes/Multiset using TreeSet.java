// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        TreeSet<Integer> st = new TreeSet<>((a,b) -> a<b ? 1:-1);
        int[] arr = new int[]{1,1,1,1,2,2,3,3,4,4};
        
        for(int num : arr){
            st.add(num);
        }
        
        
        while(st.size() > 0){
            var frontEle = st.pollFirst();
            var lastEle  = st.pollLast();
            System.out.println(frontEle +"->" + lastEle);
        }
    }
}
