




class UnionFind {
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) {
                parent.push_back(i);
                size.push_back(1);
            }
        }
        
        void merge(int a, int b) {
            int p_a = Find(a);
            int p_b = Find(b);
            
            if (p_a == p_b) {
                return;
            }
            
            if (size[p_a] > size[p_b]) {
                parent[p_b] = p_a;
                size[p_a] += size[p_b];
            } else {
                parent[p_a] = p_b;
                size[p_b] += size[p_a];
            }
            
            return;
        }
        
        int Find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }
        
        int GetSize(int x) {
            int p_x = Find(x);
            return size[p_x];
        }
        
    private:
        vector<int> parent;
        vector<int> size;
    };

class Solution {
public:
    int m ,n;
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        UnionFind uf(n*m + 1);
        
        
        int dummy = n*m;
        int ones=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1){
                    ones++;
                    if(i==0 or j==0 or i == n-1 or j == m-1){
                        uf.merge(dummy,node(i,j));
                    }
                    else{
                        if(grid[i][j+1] ==1){
                            
                            uf.merge(node(i,j),node(i,j+1));
                        }
                        if(grid[i][j-1]==1){
                            
                            uf.merge(node(i,j),node(i,j-1));
                            }
                        if(grid[i+1][j]==1){ 
                        
                            uf.merge(node(i,j),node(i+1,j));
                        }
                        if(grid[i-1][j]==1){
                        
                            uf.merge(node(i,j),node(i-1,j));
                        }
                    }
                 }
                
            }
        }
        
        return ones - uf.GetSize(dummy)+1;
        
    }
    
    
    int node(int i,int j){
        return i*m+j;
    }
};



/*

unionFind

*/