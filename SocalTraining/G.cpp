#include <stdio.h>
#include <string.h>

using namespace std;

char grid[15][11];
bool visited[15][11];
int dfs(int x, int y, char c, bool exclude) {
	if(x < 0 || x >= 12 || y < 0 || y >= 10 || visited[x][y]) return 0;
	visited[x][y] = true;
	if(grid[x][y] != c) return 0;
	int ans = 1;

	if(exclude) grid[x][y] = 0;
	ans += dfs(x-1,y,c,exclude);
	ans += dfs(x+1,y,c,exclude);
	ans += dfs(x,y-1,c,exclude);
	ans += dfs(x,y+1,c,exclude);

	return ans;
	
}

void move_vertically() {
	for(int col = 0; col < 10; col++) {
		int start = -1;
		for(int row = 0; row < 12; row++) {
			if(grid[row][col] == 0 && start == -1) start = row;
			else if(grid[row][col]!=0 && start != -1) {
				int u = grid[row][col];
				grid[start++][col] = u;
				grid[row][col] = 0;
			}
		}
	}
}

void move_horizontally() {
	int start = -1;
	for(int col = 0; col < 10; col++) {
		if(start == -1 && grid[0][col] == 0) {
			start = col;
		} else if (grid[0][col]!=0 && start != -1) {
			for(int row = 0; row < 12; row++) {
				grid[row][start] = grid[row][col];
				grid[row][col] = 0;
			}
			start++;
		}
	}
}

void print_grid() {
	for(int row = 11; row >= 0; row--) printf("%s\n",grid[row]);
	printf("\n");
}


int main() {
	int n;
	while(scanf(" %d",&n) > 0 && n > 0) {
		memset(grid,0,sizeof(grid));
		for(int i = 11; i >= 0; i--) {
			scanf("%s",grid[i]);
		}
		int ans = 120;
		for(int i = 0; i < n; i++) {
			memset(visited,0,sizeof(visited));
			char col;
			int row;
			scanf(" %c %d",&col,&row);
			int x = row - 1;
			int y = col - 'a';
			char color = grid[x][y];
			if(grid[x][y] != 0 && dfs(x,y,grid[x][y],false) > 2) {
				memset(visited,0,sizeof(visited));
				ans -= dfs(x,y,grid[x][y],true);
				move_vertically();
				move_horizontally();
			}
		}
		printf("%d\n",ans);
	}
}

