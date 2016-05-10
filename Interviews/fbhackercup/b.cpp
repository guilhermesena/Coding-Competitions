#include <stdio.h>
char g[2][1010];

int main() {
	int T;
	scanf(" %d",&T);
	for(int nT = 1; nT <= T; nT++) {
		int len;
		scanf(" %d",&len);
		scanf("%s",&g[0][1]);
		scanf("%s",&g[1][1]);
		g[0][0] = g[0][len+1] = g[1][0] = g[1][len+1] = 'X';
		g[0][len+2] = g[1][len+2] = '\0';

		int ans = 0;
		//First look for the dudes that are isolated
		for(int h = 0; h <= 1; h++) {
			for(int i = 1; i <= len+1; i++) {
				
				if(g[h][i] == '.' && g[h][i-1] == 'X' && g[h][i+1] == 'X') {
					//Found a singleton, add 1 either by filling upper column or by just putting a dude there
					ans++;
					g[h][i] = 'X';
					if(g[1-h][i] == 'X') continue;
					g[1-h][i] = 'X';
					for(int j = i+1; g[1-h][j] != 'X'; j++) g[1-h][j] = 'X';
					for(int j = i-1; g[1-h][j] != 'X'; j--) g[1-h][j] = 'X';		
				}
			}
		}

		//Now just fill up the rest
		for(int h = 0; h <= 1; h++) {
			bool started = false;
			for(int i = 0; i <= len+1; i++) {
				if(g[h][i] == '.' && !started) {ans++; started = true;}
				if(g[h][i] == 'X' && started) {started = false;}
			}
		}
		printf("Case #%d: %d\n",nT,ans);
	}
}
