



class UnionFind{
 public:
    vector<int> parent;
    int cc;//connected compoments
    UnionFind(int n){
        cc=0;
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        if(parent[x] != x){
            return find(parent[x]);
        }
        
        return x;
    }
    
    void merge(int a,int b){
        int pa = find(a);
        int pb = find(b);
        
        if(pa != pb){
            parent[pb]=pa;
            cc++;
        }
    }
    
    int clusterSize(){
        return cc;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections){
        if(connections.size()<n-1)
            return -1;
        
        UnionFind uf(n);
        for(int i=0;i<connections.size();i++){
            uf.merge(connections[i][0],connections[i][1]);
        }
        
        return n-(uf.clusterSize()) -1;
    }
   
    
};