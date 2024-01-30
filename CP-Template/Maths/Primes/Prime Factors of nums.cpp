class Solution {
public:
	int distinctPrimeFactors(vector<int>& nums) {
		int n = nums.size();
		map<int, int> mp;
		for (int num : nums) {
            // Find Prime Factors of each number 
			for (int i = 2; (i * i) <= num; i++) {
				while ((num % i) == 0) {
					mp[i]++;
					num /= i;
				}
			}
			if (num > 1) {
				mp[num]++;
			}
		}
		for (auto [k, p] : mp) {
			cout << k << " " << p << endl;
		}
		return mp.size();
	}
};
