#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int val[30];
string words[110];
char alpha[30];

bool compara (string a, string b) {
	int la = a.size();
	int lb = b.size();
	int p = 0;
	while(p < la && p < lb) {
		if(val[a[p]-'A'] < val[b[p]-'A']) return true;
		else if (val[a[p]-'A'] > val[b[p]-'A']) return false;
		p++;
	}
	if(la < lb) return true;
	return false;
}

int main() {
	int n;
	int T=1;
	while (scanf(" %d",&n)>0 && n > 0) {
		scanf(" %s",alpha);
		int len = strlen(alpha);
		for(int i = 0; i < len; i++) val[alpha[i]-'A'] = i;
	     	for(int i = 0; i < n; i++)
			cin >> words[i];

		sort(words, words+n, compara);
		printf("year %d\n",T++);
		for(int i = 0; i < n; i++) cout << words[i] << endl;
	}
	return 0;
}
