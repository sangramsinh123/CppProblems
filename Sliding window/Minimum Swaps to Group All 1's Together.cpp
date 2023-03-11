#include <bits/stdc++.h> 
int groupAllOneTogether(vector<int> &arr, int n) {
	// Write your code here.
	int ws = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == 1){
			ws++;
		}
	}
	if(ws == 0){
		return -1;
	}
	int zero_cnt = 0;
	int mn = INT_MAX;
	for(int i=0;i<ws;i++){
		if(arr[i] == 0){
			zero_cnt++;
		}
	}
	mn = min(mn,zero_cnt);

	for(int i=1;i<=n-ws;i++){
		if(arr[i-1] == 0){
			zero_cnt--;
		}

		if(arr[i+ws-1] == 0){
			zero_cnt++;
		}
		mn = min(mn,zero_cnt);

	}

	return mn;
}
