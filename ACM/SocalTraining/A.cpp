#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

const int MAXN = 310;
string first[MAXN];
string last[MAXN];
bool marked[30];
int main() {
	int n;
	while(scanf(" %d",&n) > 0 && n > 0){
		for(int i = 0; i < n; i++) {
			cin >> first[i];
			cin >> last[i];
		}
		int ans = 2000000000;
		for(int i = 0; i < (1 << 18); i++) {
			int cnd = 0;
			int u = i;
			while(u > 0) { cnd += u&1; u >>= 1;}
			memset(marked,0,sizeof(marked));	
			for(int j = 0; j < n; j++) {
				int li = last[j][0] - 'A';
				if(((1 << li) & i) == 0) {
					int fi = first[j][0] - 'A';
					if(!marked[fi]) {
						marked[fi] = true;
						cnd++;
					}
				}

			}
			if(cnd < ans) ans = cnd;
		}
		printf("%d\n",ans);
	}
}
