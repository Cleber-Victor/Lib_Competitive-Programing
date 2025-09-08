@433 @int lis() {
@471 @	vector<int> dp;
@941 @	for (int i : a) {
@01D @		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
@CD1 @		if (pos == dp.size()) {
@D8F @			dp.push_back(i);
@793 @		} else {
@0BB @			dp[pos] = i;
@AB0 @		}
@CB8 @	}
@269 @	return dp.size();
@B71 @}
