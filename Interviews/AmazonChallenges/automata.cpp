/* The idea is to do a "reverse DFS" from the extinct automata and count the nodes it reaches. Took over 1 hour to finish running!*/
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 5;
const int nvert = 1 << (N*N);
int marked[nvert];
vector<int> edges[nvert];
long long int ans = 0;
void dfs(int v) {
	marked[v] = 1;
	ans++;
	int len = edges[v].size();
	for(int i = 0; i < len; i++) {
		if(!marked[edges[v][i]]) dfs(edges[v][i]);
	}
}

int num_neighbors(int i, int j, int **m){
	int ans = 0;
	if(i-1 >= 0 && j-1 >= 0 && m[i-1][j-1]==1) ans++;
	if(i-1 >= 0 && m[i-1][j] == 1) ans++;
	if(i-1 >= 0 && j+1 < N && m[i-1][j+1] == 1) ans++;
	

	if(j-1 >= 0 && m[i][j-1] == 1) ans++;
	if(j+1 < N && m[i][j+1] == 1) ans++;

	if(i+1 < N && j-1 >=0 && m[i+1][j-1]==1) ans++;
	if(i+1 < N && m[i+1][j] == 1) ans++;
	if(i+1 < N && j+1 < N && m[i+1][j+1] == 1) ans++;

	return ans; 
}

int neighbor(int v) {
	//encode
	int u = v;
	int **mat = new int*[N];
	int **mat2 = new int*[N];
	for(int i = 0; i < N; i++) {
		mat[i] = new int[N];
		mat2[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++){
			mat[i][j] = v&1;
			v >>= 1;
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int nn = num_neighbors(i,j,mat);
			if(nn == 1 || nn == 2) mat2[i][j] = 1;
			else mat2[i][j] = 0;
		}
	}

	//decode
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			ans += (mat2[i][j]) << (N*i+j);
		}
	}
	for(int i = 0; i < N; i++){
		delete [] mat[i];
		delete [] mat2[i];
	}
	delete mat;
	delete mat2;
	return ans;
}

int main() {
	memset(marked,0,sizeof(marked));
	printf("Nvert = %d\n", nvert);
	for(int i = 0; i < nvert; i++) {
		edges[neighbor(i)].push_back(i);
	}
	dfs(0);
	printf("%lld\n",nvert - ans);
}
