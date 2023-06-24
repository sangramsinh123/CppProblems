import java.util.*;

public class Solution {
    public static int parallelCourses(int n, int[][] edges) {
        
        // topological sort
        List<List<Integer>> adj = new ArrayList<>(n+1);
        for(int i=0;i<=n;i++){
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[n+1];
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            indegree[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }
        int level = 0;
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int front = q.remove();
                n--;
                // if(adj.get(front) == null){
                //     continue;
                // }
                for(int child : adj.get(front)){
                    indegree[child]--;
                    if(indegree[child] == 0){
                        q.add(child);
                    }
                }
            }
            level++;
        }
        if(n == 0){
            return level;
        }
        return -1;
    }
}
