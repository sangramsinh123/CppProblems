#include <bits/stdc++.h>
using namespace std;


#define pii pair<int,int>

#define f first
#define s second

void solve(){
	int n ;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<int> IndexOfNextSmaller(n,-1),IndexOfPrevoiusSmaller(n,-1);//increasing stack
	stack<pii> MonotonicStack;

	//=============================================================================================================
	//NextSmaller
	for(int i=0;i<n;i++){

		while(!MonotonicStack.empty() && MonotonicStack.top().f  > arr[i]){
			pii temp = MonotonicStack.top();
			IndexOfNextSmaller[temp.s] = i ;
			MonotonicStack.pop();
		}
		MonotonicStack.push({arr[i],i});
	}

	//clear the stack
	while(!MonotonicStack.empty()){
		MonotonicStack.pop();
	}
	// for(int i=0;i<n;i++){
	// 	cout << IndexOfNextSmaller[i] <<" " ;
	// }
	// cout << endl;

	//=============================================================================================================
	//PrevoiusSmaller
	for(int i=n-1;i>=0;i--){

		while(!MonotonicStack.empty() && MonotonicStack.top().f  > arr[i]){
			pii temp = MonotonicStack.top();
			IndexOfPrevoiusSmaller[temp.s] = i ;
			MonotonicStack.pop();
		}
		MonotonicStack.push({arr[i],i});
	}

	//clear the stack
	while(!MonotonicStack.empty()){
		MonotonicStack.pop();
	}

	// for(int i=0;i<n;i++){
	// 	cout << IndexOfPrevoiusSmaller[i] <<" " ;
	// }
	// cout << endl;

	//=============================================================================================================



}
int32_t main(){

	solve();
	return 0;
}


