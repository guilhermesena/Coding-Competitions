#include<stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAXN=6010;

long long int dp[MAXN][2];
int conv[MAXN];
int nviz[MAXN];
bool def[MAXN][2];
bool bah[MAXN];
vector<int> viz[MAXN];
long long int max(long long int x, long long int y) {
	return x>y?x:y;
}
long long int solve(int v, int inc) {
	if(def[v][inc]) 
		return dp[v][inc];
	long long int ans = 0;
	if(inc) {
		for(int i = 0; i < nviz[v]; i++) {
			ans += solve(viz[v][i], 0);
		}
		ans += conv[v];
	} else {
		for(int i = 0; i < nviz[v]; i++) {
			ans += max(solve(viz[v][i], 0), solve(viz[v][i],1));
		}
	}
	

	dp[v][inc] = ans;
	def[v][inc] = true;

	return ans;
}

int main() {
	int n;
	scanf(" %d",&n);
	for(int i = 0; i < n; i++) {
		scanf(" %d",&conv[i]);
	}

	for(int i = 0; i < n-1; i++) {
		int k,l;
		scanf(" %d %d",&l,&k);
		viz[--k].push_back(--l);
		nviz[k]++;
		bah[l] = true;
	}
	int k,l;
	scanf(" %d %d",&k,&l);

	int root = -1;
	for(int i = 0; i < n; i++) {
		if(!bah[i]){
			root = i;
			break;
		}
	}
	solve(root, 0);
	solve(root,1);
	long long int ans = dp[root][0];
	if(dp[root][1] > ans) ans = dp[root][1];

	printf("%lld\n",ans);	
}
