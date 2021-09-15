class UnionFind{
public:
	unordered_map<string,string> mp;
	UnionFind(vector<vector<string>> &pairs){
		for(int i=0;i<pairs.size();i++){

			// make parent of itself
			mp[pairs[i][0]] = pairs[i][0];
			mp[pairs[i][1]] = pairs[i][1];
		}

		for(int i=0;i<pairs.size();i++){
			merge(pairs[i][0],pairs[i][1]);
		}
	}

	// find
	string find(string s){
		if(mp[s] == s){
			return s;
		}
		return find(mp[s]);
	}

	// union
	void merge(string a,string b){
		string pa = find(a);
		string pb = find(b);

		if(pa != pb){
			mp[pa] = pb;
		}

		return ;

	}

	bool connected(string a,string b){
		string pa = find(a);
		string pb = find(b);
		if(mp[pa] == mp[pb]){
			return true;
		}
		return false;
	}
};



class Solution {
public:
   
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        
        UnionFind uf(pairs);
        //base case
        if(words1.size() != words2.size()){
        	return false;
        }

        for(int i=0;i<words1.size();i++){
        	// if(uf.find(words1[i]) != uf.find(words2[i])){
        	// 	return false;
        	// }
        	if(uf.connected(words1[i],words2[i]) == false){
        		return false;
        	}
        }

        return true;

    }

};
/*

UnionFind 

*/
