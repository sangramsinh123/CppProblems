class Seg {
public:
	vector<int> tree;

	Seg(int n) {
		tree = vector<int>(4 * n + 1);
	}

	void build(int node, int tl , int tr, vector<int> &nums) {

		if (tl == tr) {
			tree[node] = nums[tl];
			return;
		}
		int tm = tl + (tr - tl) / 2;
		build(2 * node + 1, tl, tm, nums);
		build(2 * node + 2, tm + 1, tr, nums);
		tree[node] = (tree[2 * node + 1] | tree[2 * node + 2]);

	}
	int queryUtil(int node, int tl, int tr, int ql, int  qr) {
		//No Overlap
		if (qr < tl || ql > tr) {
			return 0;
		}
		// Full OverLap
		if (ql <= tl and tr <= qr) {
			return tree[node];
		}
		// Partial Overlap
		int tm = tl + ((tr - tl) / 2);

		int leftOR = queryUtil(2 * node + 1, tl, tm, ql,	qr);
		int rightOR = queryUtil(2 * node + 2, tm + 1, tr, ql,	qr);

		return (leftOR | rightOR);

	}
	int query(int ql, int qr, int &n) {
		return queryUtil(0, 0, n - 1, ql, qr);
	}
};
