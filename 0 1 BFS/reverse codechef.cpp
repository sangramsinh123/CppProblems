#include <bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define f first
#define s second
const int N = 1e5+5;
const int inf = 1e9+10;
vector<pii> graph[N];

vector<int> level(N,inf);
int n, m;



int bfs(){
	deque<int> dq;


	dq.push_back(1);
	level[1] = 0;
	while(!dq.empty()){
		int curr = dq.front();
		dq.pop_front();

		for(auto child: graph[curr]){
			int child_v = child.f;
			int wt = child.s;
			if(level[curr]+wt < level[child_v]){
				level[child_v] = level[curr]+wt;
				if(wt == 0){
					dq.push_front(child_v);
				}
				else{
					dq.push_back(child_v);
				}
			}
			
		}
	}


	return level[n] == inf ? -1: level[n];

}



int32_t main(){
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		if(u==vv){
			continue;
		}
		graph[u].push_back({v,0});
		graph[v].push_back({u,1});

	}

	cout << bfs() << endl;


	return 0;
}
