#include <bits/stdc++.h>
using namespace std;




void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = (s[0]-'a'+1);
  int pr = 31;
  int mod = 10000000007;
  int power = pr;
  for (int i = 1; i < n; i++) {
    char ch = s[i];

    ans += ((ch - 'a' + 1) * (power))%mod;
    power = (power * pr)%mod;
  }

  cout << ans << endl;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
