#include <bits/stdc++.h>
using namespace std;


int t[100];
int n;
void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) {
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {

		if (l & 1) {
			res += t[l];

			// cout << l <<" ";
			l++;
		}
		if (r & 1) {
			r--;
			res += t[r];
			// cout << r <<endl;
		}
	}
	return res;
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) {
		t[p >> 1] = t[p] + t[p ^ 1];
		cout << p << " ";
	}
}
