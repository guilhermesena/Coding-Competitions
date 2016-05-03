#include <stdio.h>
#include <vector>
using namespace std;
const int MAXV = 10010;
const int MAXE = 20010;
int nvisited;

struct vertex {
	int nviz;
	bool visited;
	vector<int> viz;
};

vertex v[MAXV];

bool dfs(int u, int parent) {
	if(v[u].visited) return false;
	nvisited++;
	v[u].visited = true;
	for(int i = 0; i < v[u].nviz; i++) {
		if(v[u].viz[i] != parent && !dfs(v[u].viz[i], u))
			return false;
	}
	return true;
}

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	nvisited = 0;
	for(int i = 0; i < N; i++)
		v[i].visited = false;

	for(int i = 0; i < M; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		v[--a].nviz++;
		v[--b].nviz++;
		v[a].viz.push_back(b);
		v[b].viz.push_back(a);		
	}
	bool cycle = dfs(0,-1);

	printf("%s\n",(cycle && (nvisited == N))?"YES":"NO");
}
