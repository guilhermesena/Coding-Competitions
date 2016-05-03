#include <stdio.h>
#include <string.h>
int dp[110][110];
int ans[110][110];
int x[110], y[110];


int main(){
	int a,b,cnt=1;
	while(scanf(" %d %d",&a,&b) && a > 0){
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < a; i++) scanf(" %d",&x[i]);
		for(int i = 0; i < b; i++) scanf(" %d",&y[i]);

		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= b; j++) {
				dp[i][j] = dp[i-1][j];
				if(dp[i][j-1] > dp[i][j]) {
					dp[i][j] = dp[i][j-1];
				}
				if(x[i-1] == y[j-1]) {
					dp[i][j] = dp[i-1][j-1]+1;
				}	
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cnt++, dp[a][b]);		
	}
}

