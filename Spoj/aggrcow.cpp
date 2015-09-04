#include <stdio.h>
#include <algorithm>
using namespace std;

int n,c,t;
long long int pos[100010];


bool tryDist(long long int dist) {
	int tot = 1;
	long long int lastpos = pos[0];
	for(int i = 1; i < n; i++) {
		if(pos[i] - lastpos >= dist) {
			lastpos = pos[i];
			if(++tot == c) return true;
		}
	}
	return false;
}

long long int binarySearch(long long int min, long long int max) {
	long long int start = min;
	long long int end = max;
	while (end-start>1) {
		long long int mid = start + (end-start)/2;
		if(tryDist(mid))
			start = mid;
		else
			end = mid;
	}
	return start;	
}

int main() {
	scanf(" %d",&t);
	while(t--) {
		scanf(" %d %d",&n,&c);
		for(int i = 0; i < n; i++) {
			scanf(" %lld",&pos[i]);
		}
		sort(pos,pos+n);
		printf("%lld\n",binarySearch(0, pos[n-1]-pos[0]+1));
	}
}
