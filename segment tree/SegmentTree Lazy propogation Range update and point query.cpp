//SegmentTree Lazy propogation Range update and point query



#include <bits/stdc++.h>
using namespace std;


class SegmentTree{
public:
	vector<int> treeNode;
	vector<int> ar;

	SegmentTree(vector<int> arr){
		ar = arr;
		int n =ar.size();
		treeNode = vector<int>(4*n);
	}

	void buildTree(int node , int start, int end){
		if(start==end){
			treeNode[node]=ar[start];
		}
		else{
		//left tree
			int mid = (start+end)/2;
			buildTree(node*2,start,mid);
			buildTree(node*2+1,mid+1,end);
			treeNode[node] = 0;// lazy propogation

		}
	
	}
	void update(int node , int start , int end , int l , int r , int val){
	//4 cases 
	if(r < start or end < l){//outside ([s e] [l r] [s e])
		return;
	}
	if(start==end){//leaf node
		treeNode[node] +=val;// if [l,r] is ([2,2] and val=3)or l,r is same
	}
	else if((l<=start) and (end<=r)){ //totally inside
		treeNode[node] +=val;

	}
	else{//partially
		int mid = (start+end)/2;
		update(node*2,start,mid,l,r,val);
		update(node*2+1,mid+1,end,l,r,val);
	}
	}

	void propogate(int node,int start, int end){
	if(start==end){
		return;
	}
	//whatever data is there pass to childrens
	int data = treeNode[node];
	treeNode[node*2]+=data;//left child
	treeNode[node*2+1]+=data;//right child
	treeNode[node]=0;

}

	int query(int node , int start,int end,int idx ){
		propogate(node,start,end);
		if(start==end){
			return treeNode[node];
		}
		else{
			int mid = (start+end)/2;
			if( (start<= idx) && (idx <= mid)){
				return query(node*2,start,mid,idx);//left

			}
			else{
				return query(node*2+1,mid+1,end,idx);//right

			}
		
		}
	}


};



int32_t main(int argc, char const *argv[]){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	SegmentTree obj(arr);
  	obj.buildTree(1,0,n-1);
	int q;
	cin>>q;

	while(q--){
		int a;
		cin>>a;
		if(a==1){//update
			int l,r,val;
			cin>>l>>r>>val;
			obj.update(1,0,n-1,l,r,val);

		}
		else{
			int idx;
            cin>>idx;
            long long ans = obj.query(1,0,n-1,idx);
            cout << ans<<endl;

		}
	}
	return 0;
}

