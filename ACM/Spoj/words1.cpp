#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void dfs(int v, vector< vector<int> > &liga, vector<int> &marked) {
	marked[v] = 1;
	for(int i = 0; i < 26; i++) {
		if(!marked[i] && (liga[v][i] || liga[i][v])) dfs(i, liga, marked);
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int  n;
		vector< vector<int> > liga(26);
		for(int i = 0; i < 26; i++) {
			liga[i].reserve(26);
		}
		vector<int> nvert(26);
		vector<int> marked(26);
		vector<int> in(26);
		vector<int> out(26);
		for(int i = 0; i < 26; i++) {
			marked[i] = 0;
			nvert[i] = 0;
			in[i] = 0;
			out[i] = 0;
			for(int j = 0; j < 26; j++) liga[i][j] = 0;

		}

		cin >> n;
		while(n--) {
			string word;
			cin >> word;
			int st = word[0] - 'a', nd = word[word.size()-1] - 'a';
			in[nd]++;
			out[st]++;
			liga[nd][st] = 1;
			liga[st][nd] = 1;
			nvert[st] = 1;
			nvert[nd] = 1;
		}

		int connected = 1;
		for(int i = 0; i < 26; i++) {
			if(nvert[i]) {
				dfs(i, liga, marked); 
				break;
			}
		}

		for(int i = 0; i < 26; i++) {
			if(nvert[i] && !marked[i]) {
				connected = 0; 
				break;
			}
		}

		if(!connected) {
			cout << "The door cannot be opened.\n";
			continue;
		}

		int start = 0, end = 0, i;
		for(i=0;i<26;i++){
			if(in[i] == out[i]+1) end++;
			else if(out[i] == in[i]+1) start++;
			else if(out[i] != in[i]) break;
		}
		
		
		
		if(i == 26 && ((start == 0 && end == 0) || (start == 1 && end == 1))) 
			cout <<"Ordering is possible.\n";
		else 
			cout << "The door cannot be opened.\n";
		
	}
}
