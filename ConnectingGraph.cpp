class ConnectingGraph {
public:
    
    vector<int> parent;
    ConnectingGraph(int n) {
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

    }

    int find(int x){
        if(parent[x] != x){
            return find(parent[x]);
        }
        return x;
    }
    void connect(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            parent[pb]= pa;
        }

        return;
    }

    
    bool query(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb){
            return true;
        }
        return false;
    }
};