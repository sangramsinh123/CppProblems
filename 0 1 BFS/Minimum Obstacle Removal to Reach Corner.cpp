




struct cmp{
    bool operator() (const pair<int,int> &a,const pair<int,int> &b) const  {
        return a.second < b.second;
    }  
};


class Solution {
public:
    #define vi vector<int>
    #define pii pair<long long,long long>
    #define inf 1e9+9
    #define f first
    #define s second
    #define ll long long
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    vector<vector<pii>> buildGraph(vector<vector<int>>& grid,int n, int m){
        vector<vector<pii>> graph(n*m+1);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currCell = i*m+j;
                
                
                for(int d=0;d<4;d++){//all direction
                    int newR = i+dx[d];
                    int newC = j+dy[d];
                    
                    if(newR>=0 and newR<n and newC >= 0 and newC<m){
                        int newCell = newR*m+newC;
                        graph[currCell].push_back({newCell,grid[newR][newC]});
                    }
                }
            }
        }
        
        return graph;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<pii>> graph = buildGraph(grid,n,m);
        
        //Apply 0-1 BFS
//         vi dist(n*m,inf);
//         deque<int> dq;//curr_node
//         dq.push_back(0);
//         dist[0]=0;
        
//         while(!dq.empty()){
            
//             auto curr = dq.front();
//             dq.pop_front();
//             for(auto child: graph[curr]){
//                 int child_v = child.f;
//                 int wt = child.s;
//                 if(dist[curr]+wt < dist[child_v]){
//                     dist[child_v] = dist[curr]+wt;
//                     if(wt == 1){
//                         dq.push_back(child_v);
//                     }
//                     else{
//                         dq.push_front(child_v);
//                     }
//                 }
//             }
            
//         }
        
        
//         return dist[n*m-1];
        
        
        
        
        
        
        //Dijistras algorithm
        
        /*
        1) build graph
        2) multiset(sort according to incraseing order of weight)
        3) ms.insert({0,0}) // curr node weight
        
        */
        vi vis(n*m,0);
        vi dist(n*m,inf);
        multiset<pii , cmp> ms;//node,weight
        ms.insert({0,0});
        dist[0] = 0;
        
        while(not ms.empty()){
            pii curr_node = *ms.begin();
            ms.erase(ms.begin());
            int v = curr_node.f;
            int dt = curr_node.s;
            if(vis[v]){
                continue;
            }
            vis[v] = 1;
            for(pii &child: graph[v]){
                int child_v = child.f;
                int wt = child.s;
                
                if(dist[v]+wt < dist[child_v]){
                    dist[child_v] = dist[v]+wt ;
                    ms.insert({child_v,dist[child_v]});
                }
            }
        }
        return dist[n*m-1];
    }
};






