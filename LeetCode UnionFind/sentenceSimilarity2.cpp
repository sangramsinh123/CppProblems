
#include <bits/stdc++.h>
using namespace std;



class unionFind{

private:
	unordered_map<string,string> parent;
public:

	unionFind(vector<pair<string, string>>& pairs){
		for(int i=0;i<pairs.size();i++){
			// make parent of itself
			parent[pairs[i].first] = pairs[i].first;
			parent[pairs[i].second] = pairs[i].second;
		}


		// i have made graph here only in constructor
		for(int i=0;i<pairs.size();i++){
			merge(pairs[i].first,pairs[i].second);
		}

	}

	string find(string a){
		if(parent[a] == a){
			return a;
		}
		return find(parent[a]);

	}

	void merge(string a,string b){
		string pa = find(a);
		string pb = find(b);

		//2 cases(lies in same or in diff)

		if(pa != pb){
			parent[pb] = pa;
		}
		
		else{
			// do not do anything
		}
		return;

	}

	bool connected(string a,string b){
		string pa = find(a);
		string pb = find(b);

		if(pa == pb){// parent are equal
			return true;
		}
		return false;
	}

};

class Solution{


public:

	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {

		unionFind uf(pairs);
		// base case

		if(words1.size() != words2.size()){
			return false;
		}
		for(int i=0;i<words1.size();i++){
			if(uf.connected(words1[i],words2[i]) == false){
				return false;
			}

		}

		return true;

	}


};



// int main(int argc, char const *argv[])
// {
	
// 	return 0;
// }