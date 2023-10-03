{\rtf1\ansi\ansicpg1252\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red70\green137\blue204;\red24\green24\blue24;\red193\green193\blue193;
\red67\green192\blue160;\red212\green214\blue154;\red140\green211\blue254;\red202\green202\blue202;\red167\green197\blue152;
\red183\green111\blue179;}
{\*\expandedcolortbl;;\cssrgb\c33725\c61176\c83922;\cssrgb\c12157\c12157\c12157;\cssrgb\c80000\c80000\c80000;
\cssrgb\c30588\c78824\c69020;\cssrgb\c86275\c86275\c66667;\cssrgb\c61176\c86275\c99608;\cssrgb\c83137\c83137\c83137;\cssrgb\c70980\c80784\c65882;
\cssrgb\c77255\c52549\c75294;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl360\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 class\cf4 \strokec4  \cf5 \strokec5 Solution\cf4 \strokec4  \{\cb1 \
\pard\pardeftab720\sl360\partightenfactor0
\cf4 \cb3     \cf2 \strokec2 public\cf4 \strokec4  \cf5 \strokec5 long\cf4 \strokec4  \cf6 \strokec6 continuousSubarrays\cf4 \strokec4 (\cf5 \strokec5 int\cf4 \strokec4 [] \cf7 \strokec7 nums\cf4 \strokec4 ) \{\cb1 \
\cb3         \cf5 \strokec5 long\cf4 \strokec4  \cf7 \strokec7 ans\cf4 \strokec4  \cf8 \strokec8 =\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf7 \strokec7 n\cf4 \strokec4  \cf8 \strokec8 =\cf4 \strokec4  \cf7 \strokec7 nums\cf4 \strokec4 .\cf7 \strokec7 length\cf4 \strokec4 ;\cb1 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf7 \strokec7 r\cf4 \strokec4  \cf8 \strokec8 =\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf7 \strokec7 l\cf4 \strokec4  \cf8 \strokec8 =\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3         \cf5 \strokec5 TreeMap\cf4 \strokec4 <\cf5 \strokec5 Integer\cf4 \strokec4 ,\cf5 \strokec5 Integer\cf4 \strokec4 > \cf7 \strokec7 tmp\cf4 \strokec4  \cf8 \strokec8 =\cf4 \strokec4  \cf10 \strokec10 new\cf4 \strokec4  \cf5 \strokec5 TreeMap\cf4 \strokec4 <>();\cb1 \
\cb3         \cf10 \strokec10 while\cf4 \strokec4 (r\cf8 \strokec8 <\cf4 \strokec4 n)\{\cb1 \
\cb3             \cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 put\cf4 \strokec4 (nums[r], \cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 getOrDefault\cf4 \strokec4 (nums[r], \cf9 \strokec9 0\cf4 \strokec4 )\cf8 \strokec8 +\cf9 \strokec9 1\cf4 \strokec4 );\cb1 \
\cb3             r\cf8 \strokec8 ++\cf4 \strokec4 ;\cb1 \
\
\cb3             \cf10 \strokec10 while\cf4 \strokec4 ((\cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 lastEntry\cf4 \strokec4 ().\cf6 \strokec6 getKey\cf4 \strokec4 ()\cf8 \strokec8 -\cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 firstEntry\cf4 \strokec4 ().\cf6 \strokec6 getKey\cf4 \strokec4 ()) \cf8 \strokec8 >\cf4 \strokec4  \cf9 \strokec9 2\cf4 \strokec4 )\{\cb1 \
\cb3                 \cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 put\cf4 \strokec4 (nums[l], \cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 getOrDefault\cf4 \strokec4 (nums[l], \cf9 \strokec9 0\cf4 \strokec4 )\cf8 \strokec8 -\cf9 \strokec9 1\cf4 \strokec4 );\cb1 \
\cb3                 \cf10 \strokec10 if\cf4 \strokec4 (\cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 get\cf4 \strokec4 (nums[l]) \cf8 \strokec8 ==\cf4 \strokec4  \cf2 \strokec2 null\cf4 \strokec4 )\{\cb1 \
\cb3                     \cf7 \strokec7 tmp\cf4 \strokec4 .\cf6 \strokec6 remove\cf4 \strokec4 (nums[l]);\cb1 \
\cb3                 \}\cb1 \
\cb3                 l\cf8 \strokec8 ++\cf4 \strokec4 ;\cb1 \
\cb3             \}\cb1 \
\
\cb3             ans \cf8 \strokec8 +=\cf4 \strokec4  (r\cf8 \strokec8 -\cf4 \strokec4 l);\cb1 \
\cb3         \}\cb1 \
\cb3         \cf10 \strokec10 return\cf4 \strokec4  ans;\cb1 \
\cb3     \}\cb1 \
\cb3 \}\cb1 \
}