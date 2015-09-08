#include <stdio.h>
#include <string.h>
const int MAXN = 1010;
int ss[MAXN],saux[MAXN],sf[MAXN],ps,paux,pf;

int main() {
	int N;
	while(scanf(" %d",&N) > 0 && N > 0){
		memset(ss,0,sizeof(ss));
		memset(saux,0,sizeof(saux));
		memset(sf,0,sizeof(sf));
		for(int i = 0; i < N; i++) {
			scanf(" %d",&ss[i]);
		}
		paux = pf = 0;
		ps = 0;
		int query = 1;
		bool can = true;
		while(pf < N && can) {
			if(ps < N && ss[ps] == query) {
				sf[pf++] = ss[ps++];
				query++;
			}
			else if(paux > 0 && saux[paux-1] == query) {
				sf[pf++] = saux[paux--];
				query++;
			}
			else if (ps < N) {
				saux[paux++] = ss[ps++];
			}
			else {
				can = false;
			}
		}
		printf("%s\n",can?"yes":"no");
	}
}
