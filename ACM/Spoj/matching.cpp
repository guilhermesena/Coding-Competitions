#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int MAXN = 100010;
const int MAXM = 150010;
const int NIL = 0;
const int INF = 1 << 28;
vector<int> viz[MAXN];
int match[MAXN];
int nviz[MAXN];
int dist[MAXN];
int m,n,p;
bool dfs(int u){
	if(u == NIL) return true;
	for(int i = 0; i < nviz[u]; i++) {
		int v = viz[u][i];
		if(dist[match[v]] == dist[u]+1 && dfs(match[v])) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	dist[u] = INF;
	return false;

}
bool bfs() {
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(!match[i]) {
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INF;
	}	

	dist[NIL] = INF;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u == NIL) continue;

		for(int i = 0; i < nviz[u]; i++) {
			int v = viz[u][i];
			if(dist[match[v]] == INF) {
				dist[match[v]] = dist[u]+1;
				q.push(match[v]);
			}			
		}

	}
	return dist[NIL]!=INF;
}

int hopcroft_karp() {
	int ans = 0;
	while(bfs()){
		for(int i = 1; i <= n; i++) {
			if(match[i] == NIL && dfs(i))
				ans++;
		}
	}	
	return ans;
}

int main () {
	scanf(" %d %d %d",&n,&m,&p);
	for(int i = 0; i < p; i++) {
		int x,y;
		scanf(" %d %d",&x,&y);
		viz[x].push_back(n+y);
		viz[n+y].push_back(x);
		nviz[x]++;
		nviz[y+n]++;		
	}

	printf("%d\n",hopcroft_karp());
}
