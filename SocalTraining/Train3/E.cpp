#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXC = 110;
const int MAXP = 1010;
const int MAXV = 1110;
const int SOURCE = 0;
const int SINK = 1105;
const int MAXE = 200010;
const long long int INF = 1ll << 62;

int nedges;

//problem stuff
int m,n;

//edges stuff
int to[MAXE], next[MAXE];
long long int cap[MAXE], flow[MAXE];

//vertex stuff
int level[MAXV], fin[MAXV], pro[MAXV], fila[MAXV];

//stuff
vector<int> keys[MAXP];
bool haskey[MAXC][MAXP];

bool dinic_bfs(int source, int sink) {
	memset(level,0,sizeof(level));
	level[source] = 1;
	int comeco = 0;
	int fim = 1;
	fila[comeco] = source;
	while(comeco!=fim) {
		int v = fila[comeco++];
		for(int i = fin[v]; i >= 0; i = next[i]) {
			int w = to[i];
			if(level[w] == 0 && flow[i] < cap[i]) {
				level[w] = level[v] + 1;
				fila[fim++] = w;
			}

		}
	}
	return level[sink]>0;
}

long long int dinic_dfs(int v, int sink, long long int fl) {
	if(v == sink) return fl;
	for(int &e = pro[v]; e >= 0; e = next[e]) {
		int w = to[e];
		if(cap[e] > flow[e] && level[w] == level[v]+1) {
			long long int df = dinic_dfs(w,sink,min(fl,cap[e]-flow[e]));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

void make_edge(int s, int t, long long int cp) {
	if(s==t) return;
	to[nedges] = t; cap[nedges] = cp; flow[nedges] = 0; next[nedges] = fin[s]; fin[s] = nedges++;
	to[nedges] = s; cap[nedges] = 0; flow[nedges] = 0; next[nedges] = fin[t]; fin[t] = nedges++;
}

void connect_costumers() {
	for(int k = 1; k <= m; k++) {
		int len = keys[k].size();
		for(int i = 0; i < len; i++) {
			for(int j = i+1; j < len; j++) {
				make_edge(keys[k][i]+1000,keys[k][j]+1000,INF);
			}
		}
	}
}

int main () {
	nedges = 0;
	memset(fin,-1,sizeof(fin));
	scanf(" %d %d",&m,&n);
	for(int i = 1; i <= m; i++) {
		int a;
		scanf(" %d",&a);
		make_edge(SOURCE,i, a);
	}

	for(int i = 1001; i <= 1000 + n; i++) {
		int a,c;
		scanf(" %d",&a);
		for(int j = 0; j < a; j++) {
			int b;
			scanf(" %d",&b);
			keys[b].push_back(i-1000);
			make_edge(b,i,INF);
		}
		scanf(" %d",&c);
		make_edge(i,SINK,c);	
	}
	connect_costumers();

	long long int ans = 0;
	long long int delta = 0;
	while(dinic_bfs(SOURCE,SINK)) {
		for(int i = 0; i < MAXV; i++) pro[i] = fin[i];
		do {
			delta = dinic_dfs(SOURCE,SINK,INF);
			ans += delta;
		} while(delta>0);
	}
	printf("%lld\n",ans);
	return 0;
}
