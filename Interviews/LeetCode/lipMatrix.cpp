#include <iostream>
#include <vector>

using std::vector;
using std::cout;
class Solution {
public:
	int longestIncreasingPath(vector<vector<int> >& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		if (n == 0)
			return 0;

		cout << "m = " << m << ", n = " << n << "\n";
		//it has at least 1 element
		int ans = 1;
		int **dp = new int*[m];
		for (int i = 0; i < m; i++)
			dp[i] = new int[n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!dp[i][j]) {
					dfs(i, j, m, n, matrix, dp, ans);
				}
			}
		}

		for (int i = 0; i < m; ++i)
			delete[] dp[i];
		delete[] dp;
		cout << ans << "\n";
		return ans;
	}

	int dfs(int x, int y, int m, int n, vector<vector<int> > &matrix, int **dp,
			int &ans) {

		if (dp[x][y])
			return dp[x][y];

		dp[x][y] = 1;

		if ((x + 1 < m) && (matrix[x + 1][y] < matrix[x][y])) {
			int w = dfs(x + 1, y, m, n, matrix, dp, ans);
			if (w + 1 > dp[x][y])
				dp[x][y] = w + 1;
		}

		if ((x - 1 >= 0) && (matrix[x - 1][y] < matrix[x][y])) {
			int w = dfs(x - 1, y, m, n, matrix, dp, ans);
			if (w + 1 > dp[x][y])
				dp[x][y] = w + 1;
		}

		if ((y + 1 < m) && (matrix[x][y + 1] < matrix[x][y])) {
			int w = dfs(x, y + 1, m, n, matrix, dp, ans);
			if (w + 1 > dp[x][y])
				dp[x][y] = w + 1;
		}
		if ((y - 1 >= 0) && (matrix[x][y - 1] < matrix[x][y])) {
			int w = dfs(x, y - 1, m, n, matrix, dp, ans);
			if (w + 1 > dp[x][y])
				dp[x][y] = w + 1;
		}

		if (dp[x][y] > ans)
			ans = dp[x][y];

		return dp[x][y];
	}
};

int main() {
	vector<int> m1, m2, m3, m4;
	m1.push_back(0);
	m1.push_back(1);
	m1.push_back(2);
	m1.push_back(3);
	m1.push_back(4);
	m1.push_back(5);
	m1.push_back(6);
	m1.push_back(7);
	m1.push_back(8);
	m1.push_back(9);
	m1.push_back(10);

	vector<vector<int> > mat;
	mat.push_back(m1);
	
	Solution s;
	s.longestIncreasingPath(mat);
}
