


struct cmp{
    bool operator() (const pair<long long,long long> &a, const pair<long long,long long> &b) const {//{node,wt}
        return a.second <  b.second;
    }
};


class Solution {
public:
    #define pii pair<long long,long long>
    
    #define inf 1e9+10
    #define vi vector<int>
    #define f first
    #define s second
    
    int dx[4] = {1,-1,0,0};//right left up down
    int dy[4] = {0,0,1,-1};
    vector<vector<pii>> buildGraph(vector<vector<int>>& grid,int n, int m ){//Matric into graph
        int nm = n*m;
        vector<vector<pii>> graph(nm);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell = i*m+j;
                
                if(grid[i][j] == 1){//right
                    
                    if(j+1 < m){//right
                        graph[cell].push_back({(i*m)+(j+1),0});
                    }
                    
                    if(j-1 >= 0 ){//left
                        graph[cell].push_back({(i*m)+(j-1),1});
                    }
                    
                    if(i+1 < n ){//upper
                        graph[cell].push_back({(i+1)*m+(j),1});
                    }
                    
                    if(i-1 >= 0 ){//upper
                        graph[cell].push_back({(i-1)*m+(j),1});
                    }
                }
                if(grid[i][j] == 2){//left
                    
                    if(j+1 < m){//right
                        graph[cell].push_back({(i*m)+(j+1),1});
                    }
                    
                    if(j-1 >= 0 ){//left
                        graph[cell].push_back({(i*m)+(j-1),0});
                    }
                    
                    if(i+1 < n ){//upper
                        graph[cell].push_back({(i+1)*m+(j),1});
                    }
                    
                    if(i-1 >= 0 ){//upper
                        graph[cell].push_back({(i-1)*m+(j),1});
                    }
                }
                
                if(grid[i][j] == 3){// lower
                    if(j+1 < m){//right
                        graph[cell].push_back({(i*m)+(j+1),1});
                    }
                    
                    if(j-1 >= 0 ){//left
                        graph[cell].push_back({(i*m)+(j-1),1});
                    }
                    
                    if(i+1 < n ){//upper
                        graph[cell].push_back({(i+1)*m+(j),0});
                    }
                    
                    if(i-1 >= 0 ){//upper
                        graph[cell].push_back({(i-1)*m+(j),1});
                    }
                }
                
                if(grid[i][j] == 4){
                    if(j+1 < m){//right
                        graph[cell].push_back({(i*m)+(j+1),1});
                    }
                    
                    if(j-1 >= 0 ){//left
                        graph[cell].push_back({(i*m)+(j-1),1});
                    }
                    
                    if(i+1 < n ){//upper
                        graph[cell].push_back({(i+1)*m+(j),1});
                    }
                    
                    if(i-1 >= 0 ){//upper
                        graph[cell].push_back({(i-1)*m+(j),0});
                    }
                }
            }
        }
        
        
        return graph;
    }
    int minCost(vector<vector<int>>& grid) {
        // Node : {from to wt}
        
        int n = grid.size();
        int m = grid[0].size();
        int nm = n*m;
        
        vector<vector<pii>> graph = buildGraph(grid,n,m);
        
        //Dijkstras Algorithm
        
        vi dist(nm,inf);
        multiset<pii,cmp> ms;
        
        ms.insert({0,0});//assume only in right
        dist[0] = 0;
        
        while(!ms.empty()){
            pii v = *ms.begin();
            ms.erase(ms.begin());
            
            for(pii &child : graph[v.f]){
                int child_v = child.f;
                int wt = child.s;
                
                if(dist[v.f]+wt < dist[child_v]){
                    dist[child_v] = dist[v.f]+wt;
                    
                    ms.insert({child_v,dist[child_v]});
                }
            }
            
            
        }
        
        return dist[nm-1];
    }
};









