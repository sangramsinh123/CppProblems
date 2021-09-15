


class UF{//unionFind
public:
    vector<int> parent;
    bool flag;

    // UF(int n){
    //     parent = vector<int>(n);
    //     for(int i=0;i<n;i++){
    //         parent[i]=i;
    //     }

    //     // for(int i=0;i < e.size();i++){
    //     //     merge(e[i][0],e[i][1]);
    //     // }

    // };

    UF(int n, vector<vector<int>> &e){
        parent = vector<int>(n);
        flag = true;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i < e.size();i++){
            flag = flag && merge(e[i][0],e[i][1]);
        }

    };

    int find(int x){
        if(parent[x] != x){
            return find(parent[x]);
        }
        return x;

    }

    // void merge(int a,int b){
    //     int pa = find(a);
    //     int pb = find(b);

    //     if(pa != pb){
    //         parent[pb]=pa;

    //     }
    //     return;

    // }

    bool merge(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            parent[pb]=pa;
            return true;

        }
        return false;

    }

    bool connected(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb){
            return true;

        }
        return false;
    }
};

class Solution {
public:
    
    bool validTree(int n, vector<vector<int>> &edges) {
        UF uf(n,edges);
        if(n-1 != edges.size() || n==0){
            return false;
        }
        // for(int i=0;i < edges.size();i++){
        //     // if(uf.find(edges[i][0]) == uf.find(edges[i][1])){
        //     //     return false;
        //     // }
        //     if(uf.connected(edges[i][0],edges[i][1]) == true){
        //         return false;
        //     }
        //     else{
        //     uf.merge(edges[i][0],edges[i][1]);
        //     }
        // }
        // return true;

        return uf.flag;

    }
};