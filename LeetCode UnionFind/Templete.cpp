class UF{
public:
    vector<int> size,par;
    int sz ;
    //constructre Injection technique
    UF(int n){
        sz = n;
        par = vector<int>(n+1);
        size = vector<int>(n+1);
        for(int i=0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    //find Parent
    int find(int node){
        if(node == par[node]){
            return node;
        }

        return par[node] = find(par[node]);
    }
    // merge

    void merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){
            return;
        }
        if(size[pa] > size[pb]){
            par[pb] = pa;
            size[pa] += size[pb];
        }
        else if(size[pa] < size[pb]){
            par[pa] = pb;
            size[pb] += size[pa];
        }
        else{//equal ?????
            par[pa] = pb;
            size[pb] += size[pa];
        }
    }
    unordered_map<int,int> mp;
    int mxSizeConnectedComponent = 0;
    vector<int> getParArray(){
        for(int i=0;i<sz;i++){
            par[i] = find(i);
            mp[par[i]]++;

            mxSizeConnectedComponent = max(mxSizeConnectedComponent,mp[par[i]]);
        }
        return par;
    }

    int getSizeOfConnectedComponents(){
        int cnt = 0;
        for(int i=0;i<sz;i++){
            if(par[i] == i){
                cnt++;
            }
        }

        return cnt;
    }

    int getMaxSizeConnectedComponent(){
        return mxSizeConnectedComponent;
    }

    bool isConnected(int a, int b){
        if(find(a) == find(b)){
            return true;
        }
        return false;
    }
};
