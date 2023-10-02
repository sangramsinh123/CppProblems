class Solution {
    public int buildGraph(int n, int[][] edges) {
        ArrayList<Integer>[] g = new ArrayList[n+1];
        for(int i = 0;i<n;i++){
            g[i] = new ArrayList<Integer>();
        }
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            g[u].add(v);
            g[v].add(u);
        }

        for(int i = 0;i<n;i++){
            System.out.print(i+"->");
            for(int child : g[i]){
                System.out.print(child+" ");
            }
            System.out.println();
        }
        return 0;
    }
}
