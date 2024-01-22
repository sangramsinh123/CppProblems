#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define inf INT_MAX
#define N_inf INT_MIN
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int mod = (int)1e9 + 7;



class cmp {
public:
	bool operator() (const int a, const  int b) {
		if (a >= b) {
			return true;
		}

		return false;
	}
};

int main() {
	// int n ;
	// cin >> n;
	// while (n--) {
	// 	cout << "sam" << endl;
	// }
	priority_queue<int, vector<int> , cmp> pq;
	for (int i = 0; i <= 10; i++) {
		pq.push(i);
	}


	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	//OUTPUT : 0 1 2 3 4 5 6 7 8 9 10
	return 0;
}
