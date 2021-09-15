class ConnectingGraph3 {
public:
    vector<int> parent;
    int cc;
     ConnectingGraph3(int n) {
        parent = vector<int>(n);
        for(int i=0 ; i<n;i++){
            parent[i]=i;
        }
        cc=n;

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
            parent[pb] = pa;
            cc--;
        }
        return;
    }

    
    int query() {
        return cc;
    }
};