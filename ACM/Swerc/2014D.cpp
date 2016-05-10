#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

const int MAXN = 200010;
int matching[MAXN];
int seen[MAXN];
vector<int> viz[MAXN];
int nviz[MAXN];
bool augment(int v) {
	for(int i = 0; i < nviz[v]; i++) {
		int w = viz[v][i];
		if(!seen[w]) {
			seen[w] = 1;
			if(matching[w] < 0 || augment(matching[w])){
				matching[w] = v;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n,m;
	scanf(" %d %d",&n,&m);
	memset(nviz,0,sizeof(nviz));	
	for(int i = 0; i < m; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		viz[a].push_back(n+b);
		nviz[a]++;
	}	
	int ans = 0;
	memset(matching,-1,sizeof(matching));
	for(int i = 0; i < n; i++) {
		memset(seen,0,sizeof(seen));
		ans += augment(i);
	}
	printf("%s",ans>=n?"YES":"NO");
}
