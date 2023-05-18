{\rtf1\ansi\ansicpg1252\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red252\green93\blue186;\red23\green23\blue23;\red202\green202\blue202;
\red72\green255\blue104;\red255\green255\blue255;\red253\green170\blue90;\red80\green93\blue147;\red174\green122\blue247;
}
{\*\expandedcolortbl;;\cssrgb\c100000\c47451\c77647;\cssrgb\c11765\c11765\c11765;\cssrgb\c83137\c83137\c83137;
\cssrgb\c31373\c98039\c48235;\cssrgb\c100000\c100000\c100000;\cssrgb\c100000\c72157\c42353;\cssrgb\c38431\c44706\c64314;\cssrgb\c74118\c57647\c97647;
}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl420\partightenfactor0

\f0\fs28 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 import\cf4 \strokec4  \cf5 \strokec5 java\cf6 \strokec6 .\cf5 \strokec5 util\cf6 \strokec6 .*\cf4 \strokec4  \cf6 \strokec6 ;\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 import\cf4 \strokec4  \cf5 \strokec5 java\cf6 \strokec6 .\cf5 \strokec5 io\cf6 \strokec6 .*;\cf4 \strokec4  \cb1 \
\cf2 \cb3 \strokec2 import\cf4 \strokec4  \cf5 \strokec5 java\cf6 \strokec6 .\cf5 \strokec5 util\cf6 \strokec6 .\cf5 \strokec5 ArrayList\cf6 \strokec6 ;\cf4 \cb1 \strokec4 \
\
\cf2 \cb3 \strokec2 public\cf4 \strokec4  \cf2 \strokec2 class\cf4 \strokec4  \cf5 \strokec5 Solution\cf4 \strokec4  \cb1 \
\cf6 \cb3 \strokec6 \{\cf4 \cb1 \strokec4 \
\cb3     \cf2 \strokec2 public\cf4 \strokec4  \cf2 \strokec2 static\cf4 \strokec4  \cf5 \strokec5 ArrayList\cf6 \strokec6 <\cf5 \strokec5 Integer\cf6 \strokec6 >\cf4 \strokec4  \cf5 \strokec5 countDistinct\cf6 \strokec6 (\cf5 \strokec5 ArrayList\cf6 \strokec6 <\cf5 \strokec5 Integer\cf6 \strokec6 >\cf4 \strokec4  \cf5 \strokec5 arr\cf6 \strokec6 ,\cf4 \strokec4  \cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 n\cf6 \strokec6 ,\cf4 \strokec4  \cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 k\cf6 \strokec6 )\cf4 \strokec4  \cb1 \
\cb3     \cf6 \strokec6 \{\cf4 \cb1 \strokec4 \
\cb3         \cf8 \strokec8 // Write your code here\cf4 \cb1 \strokec4 \
\cb3         \cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 ws\cf4 \strokec4  \cf6 \strokec6 =\cf4 \strokec4  \cf5 \strokec5 k\cf6 \strokec6 ;\cf4 \cb1 \strokec4 \
\cb3         \cf5 \strokec5 Map\cf6 \strokec6 <\cf5 \strokec5 Integer\cf6 \strokec6 ,\cf4 \strokec4  \cf5 \strokec5 Integer\cf6 \strokec6 >\cf4 \strokec4  \cf5 \strokec5 mp\cf4 \strokec4  \cf6 \strokec6 =\cf4 \strokec4  \cf2 \strokec2 new\cf4 \strokec4  \cf5 \strokec5 HashMap\cf4 \strokec4 <>\cf6 \strokec6 ();\cf4 \cb1 \strokec4 \
\
\cb3         \cf2 \strokec2 for\cf6 \strokec6 (\cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 i\cf4 \strokec4  \cf6 \strokec6 =\cf9 \strokec9 0\cf6 \strokec6 ;\cf5 \strokec5 i\cf6 \strokec6 <\cf5 \strokec5 ws\cf6 \strokec6 ;\cf5 \strokec5 i\cf6 \strokec6 ++)\{\cf4 \cb1 \strokec4 \
\cb3             \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 put\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 )\cf4 \strokec4  \cf6 \strokec6 ,\cf4 \strokec4  \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 getOrDefault\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 ),\cf4 \strokec4  \cf9 \strokec9 0\cf6 \strokec6 )\cf4 \strokec4  \cf6 \strokec6 +\cf4 \strokec4  \cf9 \strokec9 1\cf6 \strokec6 );\cf4 \cb1 \strokec4 \
\cb3         \cf6 \strokec6 \}\cf4 \cb1 \strokec4 \
\cb3         \cf5 \strokec5 ArrayList\cf6 \strokec6 <\cf5 \strokec5 Integer\cf6 \strokec6 >\cf4 \strokec4  \cf5 \strokec5 ans\cf4 \strokec4  \cf6 \strokec6 =\cf4 \strokec4  \cf2 \strokec2 new\cf4 \strokec4  \cf5 \strokec5 ArrayList\cf4 \strokec4 <>\cf6 \strokec6 ();\cf4 \cb1 \strokec4 \
\cb3         \cf5 \strokec5 ans\cf6 \strokec6 .\cf5 \strokec5 add\cf6 \strokec6 (\cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 size\cf6 \strokec6 ());\cf4 \cb1 \strokec4 \
\cb3         \cf2 \strokec2 for\cf6 \strokec6 (\cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 i\cf6 \strokec6 =\cf9 \strokec9 1\cf6 \strokec6 ;\cf5 \strokec5 i\cf6 \strokec6 <=\cf5 \strokec5 n\cf6 \strokec6 -\cf5 \strokec5 ws\cf6 \strokec6 ;\cf5 \strokec5 i\cf6 \strokec6 ++)\{\cf4 \cb1 \strokec4 \
\cb3             \cf8 \strokec8 // remove i-1\cf4 \cb1 \strokec4 \
\cb3             \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 put\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 -\cf9 \strokec9 1\cf6 \strokec6 )\cf4 \strokec4  \cf6 \strokec6 ,\cf4 \strokec4  \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 -\cf9 \strokec9 1\cf6 \strokec6 ))\cf4 \strokec4  \cf6 \strokec6 -\cf4 \strokec4  \cf9 \strokec9 1\cf6 \strokec6 );\cf4 \cb1 \strokec4 \
\cb3             \cf2 \strokec2 if\cf6 \strokec6 (\cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 -\cf9 \strokec9 1\cf6 \strokec6 ))\cf4 \strokec4  \cf6 \strokec6 ==\cf4 \strokec4  \cf9 \strokec9 0\cf6 \strokec6 )\{\cf4 \cb1 \strokec4 \
\cb3                 \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 remove\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 i\cf6 \strokec6 -\cf9 \strokec9 1\cf6 \strokec6 ));\cf4 \cb1 \strokec4 \
\cb3             \cf6 \strokec6 \}\cf4 \cb1 \strokec4 \
\cb3             \cf7 \strokec7 int\cf4 \strokec4  \cf5 \strokec5 r\cf4 \strokec4  \cf6 \strokec6 =\cf4 \strokec4  \cf5 \strokec5 i\cf6 \strokec6 +\cf5 \strokec5 ws\cf6 \strokec6 -\cf9 \strokec9 1\cf6 \strokec6 ;\cf4 \cb1 \strokec4 \
\cb3             \cf8 \strokec8 // add r\cf4 \cb1 \strokec4 \
\cb3             \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 put\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 r\cf6 \strokec6 )\cf4 \strokec4  \cf6 \strokec6 ,\cf4 \strokec4  \cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 getOrDefault\cf6 \strokec6 (\cf5 \strokec5 arr\cf6 \strokec6 .\cf5 \strokec5 get\cf6 \strokec6 (\cf5 \strokec5 r\cf6 \strokec6 ),\cf4 \strokec4  \cf9 \strokec9 0\cf6 \strokec6 )\cf4 \strokec4  \cf6 \strokec6 +\cf4 \strokec4  \cf9 \strokec9 1\cf6 \strokec6 );\cf4 \cb1 \strokec4 \
\cb3             \cf5 \strokec5 ans\cf6 \strokec6 .\cf5 \strokec5 add\cf6 \strokec6 (\cf5 \strokec5 mp\cf6 \strokec6 .\cf5 \strokec5 size\cf6 \strokec6 ());\cf4 \cb1 \strokec4 \
\
\cb3         \cf6 \strokec6 \}\cf4 \cb1 \strokec4 \
\
\cb3         \cf2 \strokec2 return\cf4 \strokec4  \cf5 \strokec5 ans\cf6 \strokec6 ;\cf4 \cb1 \strokec4 \
\cb3     \cf6 \strokec6 \}\cf4 \cb1 \strokec4 \
\cf6 \cb3 \strokec6 \}\cf4 \cb1 \strokec4 \
\
\
\
}