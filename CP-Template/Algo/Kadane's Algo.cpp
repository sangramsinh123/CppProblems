int getMaxSubarraySum(vector<int> &a, int l, int r) {// Kadanes Algo
	int currSum = 0;
	int mx = INT_MIN;
	for (int i = l; i <= r; i++) {
		currSum += a[i];
		if (currSum > mx) {
			mx = currSum;
		}
		if (currSum < 0) {
			currSum = 0;
		}

	}

	return mx;
}
