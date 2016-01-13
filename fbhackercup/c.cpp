#include <stdio.h>
const int MAXN = 100010;
typedef long long int ll;

ll prices[MAXN];
int main() {
	int T;
	scanf(" %d",&T);
	for(int nT = 1; nT <= T; nT++) {
		printf("Case #%d: ",nT);
		int N;
		long long int P;
		scanf(" %d %lld",&N,&P);
		for(int i = 0; i < N; i++)
			scanf(" %lld", &prices[i]);

		if(N < 2) {
			printf("%d\n", ((prices[0] <= P) ? 1 : 0));
			continue;
		}

		int start = 0, end = 1;
		ll ans = 0;
		ll partial =  prices[0];
		if(prices[0] <= P) ans++;
		while(end < N) {
			partial += prices[end];
			while(start < end && partial > P) {
				partial -= prices[start];
				start++;
			}
			ans += (end-start);
			if(prices[end] <= P) ans++;
			end++;
		}

		printf("%lld\n",ans);
	}
}
