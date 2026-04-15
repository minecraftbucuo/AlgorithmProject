#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& nums, int first, int len) {
	if (first == len) {
		res.push_back(nums);
		return;
	} else {
		for (int i = first; i < len; i++) {
			swap(nums[i], nums[first]);
			backtrack(res, nums, first + 1, len);
			swap(nums[i], nums[first]);
		}
	}
}

int main() {
	vector<vector<int>> ans;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	backtrack(ans, nums, 0, nums.size());

	for (int i = 0; i < (int)ans.size(); i++) {
		for (int j = 0; j < (int)ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
