#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

string words[32];
int color[32];
int numcolors;
int viz[32][32];
int nviz[32];
int liga[32][32];
int last;
bool included[26];
void make_edges(string s) {
	int len = s.size();
	for(int i = 0; i < len; i++) {
		included[s[i] - 'A'] = true;
		for(int j = 0; j < len; j++) {
			int va = s[i] - 'A';
			int vb = s[j] - 'A';
			if(i!=j && !liga[va][vb]) {
				liga[va][vb] = liga[vb][va] = 1;
				viz[va][nviz[va]++] = vb;
				viz[vb][nviz[vb]++] = va;
			}
		}
	}
}

bool isSafe(int v, int c) {
	for(int i = 0; i < nviz[v]; i++) {
		int w = viz[v][i];
		if(color[w] == c) return false;
	}
	return true;
}

bool colorRec(int v) {
	if(v == last) {
		for(int c = 1; c <= numcolors; c++) {
			if(isSafe(v,c)) {
				color[v] = c;
				return true;
			}
		}
	}
	for(int i = 1; i <= numcolors; i++) {
		if(isSafe(v, i)) {
			color[v] = i;
			int next;
			for(int i = v+1; i < 26; i++) {
				if(included[i]) {
					next = i;
					break;
				}
			}
			if(colorRec(next)) return true;
			color[v] = 0;
		}
	}
	return false;
}

int compara(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int main() {
	int n;
	char exc;

	while(scanf(" %d",&n) > 0 && n > 0) {
		memset(color, 0, sizeof(color));
		memset(viz,0,sizeof(viz));
		memset(nviz,0,sizeof(nviz));
		memset(liga,0,sizeof(liga));
		memset(included, 0, sizeof(included));
		scanf(" %c",&exc);
		for(int i = 0; i < n; i++) {
			cin >> words[i];
			numcolors = words[i].size();
			make_edges(words[i]);
		}
		for(int i = 0; i < 26; i++) if(included[i]) last = i;	
		for(int i = 0; i < 26; i++) {
			if(included[i]) {
				colorRec(i);
				break;
			}
		}
		vector<int> ans[4];
		for(int i = 0; i < 26; i++) {
			if(included[i]) {
				ans[color[i] - 1].push_back(i);
			}
		}
		for(int i = 0; i < numcolors; i++) if(ans[i].size() < 6) ans[i].push_back(exc-'A');
		for(int i = 0; i < numcolors; i++) sort(ans[i].begin(), ans[i].end());
		sort(ans, ans+numcolors, compara);
		for(int i = 0; i < numcolors; i++) {
			int len = ans[i].size();
			for(int j = 0; j < len; j++) printf("%c",ans[i][j]+'A');
			if(i < numcolors - 1)printf(" ");
		}
		printf("\n");
	}
}
