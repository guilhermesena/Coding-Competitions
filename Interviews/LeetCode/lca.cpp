#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct entry {
	int nr[2], p;

	bool operator <(const entry &rhs) const {
		return nr[0] == rhs.nr[0] ?
				(nr[1] < rhs.nr[1] ? 1 : 0) : (nr[0] < rhs.nr[0] ? 1 : 0);
	}
};

long find_lcp(int x, int y, vector<vector<int> > &P, int stp, int N) {
	int k;
	long ans = 0;
	if (x == y)
		return N - x;

	for (k = stp - 1; k >= 0 && x < N && y < N; k--) {
		if (P[k][x] == P[k][y]) {
			x += 1 << k, y += 1 << k, ans += 1 << k;
		}
	}
	return ans;
}

long stringSimilarity(string value) {
	const int MAXGAP = 21;
	const int N = value.size();

	vector<vector<int> > P(MAXGAP);
	vector<entry> L(N);

	for (int i = 0; i < MAXGAP; i++) {
		P[i].reserve(N);
	}

	for (int i = 0; i < N; i++) {
		P[0][i] = value[i] - 'a';
	}

	int stp = 1;
	for (int cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
		for (int i = 0; i < N; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = (i + cnt < N) ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L.begin(), L.end());
		for (int i = 0; i < N; i++) {
			P[stp][L[i].p] =
					(i > 0 && L[i].nr[0] == L[i - 1].nr[0]
							&& L[i].nr[1] == L[i - 1].nr[1]) ?
							(P[stp][L[i - 1].p]) : (i);
		}
	}

	vector<int> sa(N), lcp(N);

	for (int i = 0; i < N; i++) {
		sa[P[stp - 1][i]] = i;
	}

	long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += find_lcp(i, 0, P, stp, N);
	}

	return ans;

}
int main() {
	int t, i;
	scanf("%d", &t);
	char a[100001];
	for (i = 0; i < t; i++) {
		scanf("%s", a);
		long long int res = stringSimilarity(a);
		printf("%lld\n", res);
	}
	return 0;
}
