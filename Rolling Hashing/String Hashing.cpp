{\rtf1\ansi\ansicpg1252\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <bits/stdc++.h>\
using namespace std;\
\
\
\
\
void solve() \{\
  string s;\
  cin >> s;\
  int n = s.size();\
  int ans = (s[0]-'a'+1);\
  int pr = 31;\
  int mod = 10000000007;\
  int power = pr;\
  for (int i = 1; i < n; i++) \{\
    char ch = s[i];\
\
    ans += ((ch - 'a' + 1) * (power))%mod;\
    power = (power * pr)%mod;\
  \}\
\
  cout << ans << endl;\
\}\
\
int main() \{\
\
  int t;\
  cin >> t;\
  while (t--) \{\
    solve();\
  \}\
  return 0;\
\}}