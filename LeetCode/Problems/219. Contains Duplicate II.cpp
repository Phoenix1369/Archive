class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = (int)nums.size();
		unordered_map<int,int> last;
		for (int i = 0; i < n; ++i) {
			if (last.count(nums[i])) {
				if ((i-last.at(nums[i])) <= k) {
					return true;
				}
			}
			last[nums[i]] = i;
		}
		return false;
	}
};
