#include<bits/stdc++.h>
using namespace std;



void bfs(int n) {

	vector<lli> indegree(n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	int visited = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		visited++;
		for (int child : adj[front]) {
			indegree[child]--;
			if (indegree[child] == 0) {
				q.push(child);
			}
		}
	}


	if (visited == n) {
		cout << "NO CYCLE" << endl;
	}
	else {
		cout << "CYCLE" << endl;
	}


}


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
		cout << endl;
	}
	return 0;
}

