#include <stdio.h>
#include <string.h>
const int MAXN = 10010;
long long int dp[MAXN];
int val[MAXN];

int main() {
	int T,N;
	scanf(" %d",&T);
	for(int Test = 1; Test <= T; Test++) {
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		scanf(" %d",&N); 
		for(int i = 0; i < N; i++) {
			scanf(" %d",&val[i]);
		}
		dp[0] = val[0];
		dp[1] = (val[1] > val[0]) ? val[1] : val[0];
		for(int i = 2; i < N; i++) {
			dp[i] = dp[i-1];
			if(dp[i-2] + val[i] > dp[i])
				dp[i] = dp[i-2]+val[i];
		}
		printf("Case %d: %lld\n",Test, dp[N-1]);
	;
		
	}
}
