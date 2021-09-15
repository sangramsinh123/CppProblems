class UnionFind{
public:
    vector<int> parent;
    UnionFind(int n){
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    };

    //find
    int find(int x){
        if(parent[x] != x){
            return find(parent[x]);
        }
        return x;
    }

    // union
    void merge(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            parent[pb] = pa;

        }

        return;
    }
    // check connection
    bool connected(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            return false;
        }

        return true;
    }
};

class Solution {
private:
    int n,m;
public:
    
    void surroundedRegions(vector<vector<char>> &board) {
        if(board.size() == 0){
            return;
        }
        n = board.size();
        m = board[0].size();

        UnionFind uf(n*m+1);
        int dummy = n*m;

        for(int i=0;i<n;i++){
            for(int j =0;j<m ;j++){
                if(board[i][j] == 'O'){
                    if(i==0 || j ==0 || i== n-1 || j == m-1){
                        uf.merge(node(i,j),dummy);
                    }
                    else{
                        //check 4 directions
                        if(board[i][j+1]=='O'){
                            uf.merge(node(i,j),node(i,j+1));
                        }
                        if(board[i][j-1]=='O'){
                            uf.merge(node(i,j),node(i,j-1));
                        }
                        if(board[i+1][j]=='O'){
                            uf.merge(node(i,j),node(i+1,j));
                        }
                        if(board[i-1][j]=='O'){
                            uf.merge(node(i,j),node(i-1,j));
                        }
                    }

                }
                // else{

                // }
            }
        }
        for(int i=0;i<n;i++){
            for(int j =0;j<m ;j++){
                if(uf.connected(node(i,j),dummy)){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }

    }

    int node(int i, int j){
        return i*m+j;

    }
};

/*


connected components


*/