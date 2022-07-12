#include <bits/stdc++.h>
using namespace std;







vector<int> nextSmallerleft(vector<int>& nums, int n) { //Increasing Stack
#define pii pair<int,int>
#define f first
#define s second
  stack<pii> st;
  vector<int> l(n);

  for (int i = 0; i < n; i++) {
    while (!st.empty() && (st.top().f >= nums[i]) ) {
      st.pop();
    }

    if (st.empty()) {
      l[i] = -1;
    }
    else {
      l[i] = st.top().s;
    }

    st.push({nums[i], i});
  }

  return l;
}


int main() {

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> l = nextSmallerleft(nums, n);
  for (int i = 0; i < n; i++) {
    cout << l[i] << endl;
  }
  return 0;
}
