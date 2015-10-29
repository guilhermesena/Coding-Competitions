#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
long long int INF = 1ll << 62;

long long int make_number(vector<int> v){
	int len = v.size();
	int numzeros = 0;	
	long long int ans = 0;
	for(int i = 0; i < len; i++) {
		if(v[i] == 0) {
			numzeros++;
		}
		else if (ans == 0) {
			ans += v[i];
			for(int j = 0; j < numzeros; j++) ans *= 10;
		}
		else {
			ans *= 10;
			ans += v[i];
		}
	}
	return ans;
}
int nums[20];
int main() {
	int n;
	while(scanf (" %d",&n) > 0 && n > 0) {
		memset(nums, 0, sizeof(nums));
		for(int i = 0; i < n; i++) scanf(" %d",&nums[i]);
		long long int ans = INF;
		for(int i = 0; i < (1 << n); i++) {
			vector<int> na,nb;
			na.clear();
			nb.clear();
			for(int j = 0; j < n; j++) {
				if((1 << j) & i) {
					na.push_back(nums[j]);
				}
				else {
					nb.push_back(nums[j]);
				}
			}
			sort(na.begin(), na.end());
			sort(nb.begin(), nb.end());
			long long int sa = make_number(na), sb = make_number(nb);
			if(sa == 0 || sb == 0) continue;
			if(sa+sb < ans) ans = sa+sb;
		}
		printf("%lld\n",ans);
	}
}
