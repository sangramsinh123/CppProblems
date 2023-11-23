class SegmentTree{
public :
	int n;
	vector<int> tree;
	SegmentTree(vector<int> nums){
        this->n = nums.size();
		tree.resize(4*n+1);
	}


	void buildSegmentTree(vector<int> &nums,int node, int tl, int tr){

		if(tl == tr){
			tree[node] = nums[tl];
			return;
		}

		int leftChild = 2*node+1;
		int rightChild = 2*node+2;
		int tm = tl+(tr-tl)/2;
		buildSegmentTree(nums,leftChild, tl,tm);
		buildSegmentTree(nums,rightChild, tm+1,tr);
		tree[node] = (tree[leftChild]|tree[rightChild]);
	}

	int queryUtil(int node, int tl, int tr, int ql, int qr){
		// out of Bound [tr ql  qr tl]
		if(tr < ql or qr < tl){
			return 0;
		}
		// Subproblem [ql tl tr qr]
		if(ql<=tl && tr <= qr){
			return tree[node];
		}
		int tm = tl+(tr-tl)/2;
		int leftOR =  queryUtil(2*node+1,tl,tm,ql,qr);
		int rightOR = queryUtil(2*node+2,tm+1,tr,ql,qr);
		return (leftOR|rightOR);
	}

	int query(int L, int R){
		return queryUtil(0, 0, n-1,  L ,  R);
	}
};
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
		vector<int> ans(n,0);
		SegmentTree st(nums);
		st.buildSegmentTree(nums,0,0,n-1);
		for(int i = 0;i<n;i++){
			int req = st.query(i,n-1);
            cout << req << " ";
			int lo = i;
			int hi = n-1;
			
            int idx = hi;
			while(lo<=hi){
				int mid = lo+(hi-lo)/2;
				if(st.query(i,mid) == req){
					idx = mid;
					hi = mid-1;
				}
				else{
					lo = mid+1;
				}
			}
            ans[i] = idx-i+1;
		}

		return ans;
    }
};

/*
1 0 2 1 3

0001 0000 0010 0001 0011

0001 0001 0011 0011 0011


0023
*/
