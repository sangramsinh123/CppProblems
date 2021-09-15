/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


// class UnionFind{
// public:
//     vector<int> parent;
//     int size;
//     UnionFind(int n){
//         parent = vector<int>(n);
//         for(int i=0;i<n;i++){
//             parent[i]=i;
//         }

//         size = 0;
//     }

//     //find
//     int find(int x){
//         if(parent[x] != x){
//             return find(parent[x]);//path compreshion
//         }

//         return x;

//     }
//     //merge

//     void merge(int a,int b){
//         int pa = find(a);
//         int pb = find(b);

//         if(pa != pb){
//             parent[pa] = pb;
//             size--;
//         }

//     }

// };


// class Solution {
// public:
    
//     vector<int> numIslands2(int n, int m, vector<Point> &operators) {
//        //base case

//        vector<int> ans;
//        if(operators.size() == 0 or operators.empty()){
//            return ans;
//        }

//     //    vector<int> dirx = {-1,1,0,0};// left right up down
//     //    vector<int> diry = {0,0,1,-1};

//        vector<int> dirs = {-1, 0, 1, 0, -1};
//        vector<vector<bool>> grid(n,vector<bool> (m));

//         UnionFind uf(n*m);
//        for(Point p : operators){
//            (uf.size)++;
//            grid[p.x][p.y] = true;
           

//            for(int d=0;d<4;d++){
            
               
//                if(_x < 0 or _y < 0 or _x >= n or _y >= m or grid[_x][_y]==false){
//                    continue;
//                }
//                uf.merge((p.x)*m+p.y , (_x*m)+_y);
//                grid[_x][_y] = true;
//            }

//            ans.push_back(uf.size);

//        }
//        return ans;
//     }
// };


    int node(int x,int y,int m) {
        return x*m+y;
    }
    class UnionFind {
        public: 
            vector<int> parent;
   
            UnionFind(int num){
                for(int i = 0;i<num;i++){
                    parent.push_back(-1);
                }
                return;
            };
        
            int find(int x){
                if(parent[x]==x){
                    return x;
                }
                return parent[x] = find(parent[x]);
            };
        
            int connect(int a,int b){
                int fa = find(a);
                int fb = find(b);
                if(fa != fb){
                    parent[fa] = fb;
                    return 1;
                }
                return 0;
            };
        
    };  

    class Solution {
    public:
        int dir[2][4] = {{1,0,0,-1},{0,1,-1,0}};
        vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
            vector<int> ret;
            if(operators.size()==0){
                return ret;
            }
        
            UnionFind uf(n*m);
            int count = 0;
            int t = operators.size();
            for(int k = 0; k<t; k++){
                int id = node(operators[k].x,operators[k].y,m);
                if(uf.parent[id]==-1){
                    uf.parent[id] = id;
                    count += 1;
                    for(int i = 0;i<4;i++){
                        int next_x = operators[k].x + dir[0][i];
                        int next_y = operators[k].y + dir[1][i];
                        int nid = node(next_x,next_y,m);
                        if(next_x>-1&&next_x<n&&next_y>-1&&next_y<m&&uf.parent[nid]!=-1){
                            if(uf.connect(node(operators[k].x,operators[k].y,m),node(next_x,next_y,m))){
                                count--;
                            }
                         }
                     }
                 }
               ret.push_back(count);
            }
            return ret;
          }
      };