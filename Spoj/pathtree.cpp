#include <stdio.h>
#include <vector>
#include <string.h>


const int MAXN = 10010;
using namespace std;

struct vertex {
	int nviz;
	vector<int> viz;
};

vertex vert[MAXN];
int height[MAXN];
int visited[MAXN];
int chosen;
int maxheight;
int ans;

void dfs(int v, int h) {
	visited[v] = 1;
	height[v] = h;
	if(h > maxheight || chosen == -1) {
		maxheight = h;
		chosen = v;
	}
	for(int i = 0; i < vert[v].nviz; i++) {
		int w = vert[v].viz[i];
		if(!visited[w]) {
			dfs(w, h+1);
		}
	}
}

int main() {
	int N;
	scanf(" %d",&N);
	for(int i = 0; i < N-1; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		vert[a].nviz++;
		vert[a].viz.push_back(b);
		vert[b].nviz++;
		vert[b].viz.push_back(a);
	}
	chosen = -1;
	maxheight = 0;
	dfs(1,0);
	int chosen_aux = chosen;
	chosen = -1;
	maxheight = 0;
	memset(height,0,sizeof(height));
	memset(visited,0,sizeof(visited));
	dfs(chosen_aux, 0);

	printf("%d\n",height[chosen]);

}
