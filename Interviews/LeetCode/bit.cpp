#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class NumArray {
public:
	vector<int> tree;
	vector<int> nums_vec;
	int MAXN;

	NumArray(vector<int> &nums) {
		MAXN = nums.size()+1;
		for(int i = 0; i < MAXN; i++) {
			tree.push_back(0);
			nums_vec.push_back(0);
		}

		for (int i = 0; i < nums.size(); i++) {
				update(i, nums[i]);
		}
	}

	int read(int idx) {
		int sum = 0;
		while (idx > 0) {
			sum += tree[idx];
			idx -= idx & -idx;
		}
		return sum;
	}

	void update_aux(int idx, int val) {
		while (idx < MAXN) {
			cout << "idx = " << idx << "\n";
			tree[idx] += val;
			idx += idx & -idx;
		}
	}

	void update(int i, int v) {
		int delta = v - nums_vec[i+1];
		nums_vec[i+1] = v;
		update_aux(i+1, delta);
	}

	int sumRange(int i, int j) {
		return read(j + 1) - read(i);
	}
};

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(9);

	NumArray na(nums);

	for(int i = 0; i <= nums.size(); i++) cout << na.read(i) << "\n";
	na.update(2, 50);
	for(int i = 0; i <= nums.size(); i++) cout << na.read(i) << "\n";

}
