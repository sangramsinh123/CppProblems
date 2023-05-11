
class UF{
    private int[] par;
    private int[] size;
    
    public UF(int n){
        par = new int[n+1];
        size = new int[n+1];
        
        for(int i=1;i<=n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    
    //find
    public int find(int x){
        if(x == par[x]){
            return x;
        }
        
        return par[x] = find(par[x]);
    }
    
    // merge
    
    public void merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){
            return;
        }
        if(size[pa] > size[pb]){
            par[pb]  = pa;
            size[pa]+= size[pb];
        }
        else{
            par[pa]  = pb;
            size[pb] += size[pa];
        }
        
    }

    public void getParArray(int n){
        for(int i=1;i<=n;i++){
            par[i] = find(i);
        }
    }

    public int getSize(int n){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(par[i] == i){
                cnt++;
            }
        }

        return cnt;
    }
}


class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UF uf = new UF(n);

        // make the connections of cities

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    int city1 = i+1;
                    int city2 = j+1;
                    uf.merge(city1,city2);
                }
            }
        }

        uf.getParArray(n);
        int provinces = uf.getSize(n);

        return provinces;
    }
}






