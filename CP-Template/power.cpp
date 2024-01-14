{\rtf1\ansi\ansicpg1252\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red183\green111\blue179;\red24\green24\blue24;\red194\green126\blue101;
\red193\green193\blue193;\red70\green137\blue204;\red67\green192\blue160;\red202\green202\blue202;\red212\green214\blue154;
\red140\green211\blue254;\red167\green197\blue152;\red89\green138\blue67;}
{\*\expandedcolortbl;;\cssrgb\c77255\c52549\c75294;\cssrgb\c12157\c12157\c12157;\cssrgb\c80784\c56863\c47059;
\cssrgb\c80000\c80000\c80000;\cssrgb\c33725\c61176\c83922;\cssrgb\c30588\c78824\c69020;\cssrgb\c83137\c83137\c83137;\cssrgb\c86275\c86275\c66667;
\cssrgb\c61176\c86275\c99608;\cssrgb\c70980\c80784\c65882;\cssrgb\c41569\c60000\c33333;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl360\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include\cf4 \strokec4 <bits/stdc++.h>\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 using\cf5 \strokec5  \cf6 \strokec6 namespace\cf5 \strokec5  \cf7 \strokec7 std\cf5 \strokec5 ;\cb1 \
\
\
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  ll long long\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  pii \cf7 \strokec7 pair\cf8 \strokec8 <\cf6 \strokec6 int,int\cf8 \strokec8 >\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  vi \cf7 \strokec7 vector\cf8 \strokec8 <\cf6 \strokec6 int\cf8 \strokec8 >\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  pb push_back\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  F first\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  S second\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  inf INT_MAX\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  N_inf INT_MIN\cf5 \cb1 \strokec5 \
\cf2 \cb3 \strokec2 #define\cf6 \strokec6  fastIO \cf7 \strokec7 ios_base\cf6 \strokec6 ::\cf9 \strokec9 sync_with_stdio\cf6 \strokec6 (false);\cf10 \strokec10 cin\cf6 \strokec6 .\cf9 \strokec9 tie\cf6 \strokec6 (nullptr);\cf10 \strokec10 cout\cf6 \strokec6 .\cf9 \strokec9 tie\cf6 \strokec6 (nullptr);\cf5 \cb1 \strokec5 \
\pard\pardeftab720\sl360\partightenfactor0
\cf6 \cb3 \strokec6 const\cf5 \strokec5  \cf6 \strokec6 int\cf5 \strokec5  \cf10 \strokec10 mod\cf5 \strokec5  \cf8 \strokec8 =\cf5 \strokec5  (\cf6 \strokec6 int\cf5 \strokec5 )\cf11 \strokec11 1e9\cf8 \strokec8 +\cf11 \strokec11 7\cf5 \strokec5 ;\cb1 \
\
\
\
\
\cf6 \cb3 \strokec6 ll\cf5 \strokec5  \cf9 \strokec9 power\cf5 \strokec5 (\cf6 \strokec6 ll\cf5 \strokec5  \cf10 \strokec10 a\cf5 \strokec5 , \cf6 \strokec6 ll\cf5 \strokec5  \cf10 \strokec10 b\cf5 \strokec5 )\{\cf12 \strokec12 // a^b\cf5 \cb1 \strokec5 \
\pard\pardeftab720\sl360\partightenfactor0
\cf5 \cb3     \cf6 \strokec6 ll\cf5 \strokec5  \cf10 \strokec10 ans\cf5 \strokec5  \cf8 \strokec8 =\cf5 \strokec5  \cf11 \strokec11 1\cf5 \strokec5 ;\cb1 \
\cb3     \cf2 \strokec2 for\cf5 \strokec5 (\cf6 \strokec6 int\cf5 \strokec5  \cf10 \strokec10 i\cf5 \strokec5  \cf8 \strokec8 =\cf5 \strokec5  \cf11 \strokec11 1\cf5 \strokec5 ;\cf10 \strokec10 i\cf8 \strokec8 <=\cf10 \strokec10 b\cf5 \strokec5 ;\cf10 \strokec10 i\cf8 \strokec8 ++\cf5 \strokec5 )\{\cb1 \
\cb3         \cf10 \strokec10 ans\cf5 \strokec5  \cf8 \strokec8 =\cf5 \strokec5  (\cf10 \strokec10 ans\cf8 \strokec8 *\cf10 \strokec10 a\cf5 \strokec5 );\cb1 \
\cb3     \}\cb1 \
\
\cb3     \cf2 \strokec2 return\cf5 \strokec5  \cf10 \strokec10 ans\cf5 \strokec5 ;\cb1 \
\cb3 \}\cb1 \
\
\
\
\pard\pardeftab720\sl360\partightenfactor0
\cf6 \cb3 \strokec6 int\cf5 \strokec5  \cf9 \strokec9 main\cf5 \strokec5 ()\{\cb1 \
\
\pard\pardeftab720\sl360\partightenfactor0
\cf5 \cb3     \cf6 \strokec6 fastIO\cf5 \cb1 \strokec5 \
\
\cb3     \cf6 \strokec6 int\cf5 \strokec5  \cf10 \strokec10 t\cf5 \strokec5  ;\cb1 \
\pard\pardeftab720\sl360\partightenfactor0
\cf12 \cb3 \strokec12     // cin>>t;\cf5 \cb1 \strokec5 \
\pard\pardeftab720\sl360\partightenfactor0
\cf5 \cb3     \cf10 \strokec10 t\cf5 \strokec5  \cf8 \strokec8 =\cf5 \strokec5  \cf11 \strokec11 1\cf5 \strokec5 ;\cb1 \
\pard\pardeftab720\sl360\partightenfactor0
\cf12 \cb3 \strokec12     // while(t > 0)\{\cf5 \cb1 \strokec5 \
\cf12 \cb3 \strokec12     //  solve();\cf5 \cb1 \strokec5 \
\cf12 \cb3 \strokec12     //  t--;\cf5 \cb1 \strokec5 \
\cf12 \cb3 \strokec12     // \}\cf5 \cb1 \strokec5 \
\
\pard\pardeftab720\sl360\partightenfactor0
\cf5 \cb3     \cf10 \strokec10 cout\cf5 \strokec5  \cf9 \strokec9 <<\cf5 \strokec5  \cf9 \strokec9 power\cf5 \strokec5 (\cf11 \strokec11 2\cf5 \strokec5 ,\cf11 \strokec11 4\cf5 \strokec5  ) \cf9 \strokec9 <<\cf5 \strokec5  \cf9 \strokec9 endl\cf5 \strokec5 ;\cb1 \
\cb3     \cf2 \strokec2 return\cf5 \strokec5  \cf11 \strokec11 0\cf5 \strokec5 ;\cb1 \
\cb3 \}\cb1 \
}