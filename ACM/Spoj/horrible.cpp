#include <stdio.h>
#include <string.h>
const int MAXN = 100010;
long long int a[MAXN];
long long int tree[5*MAXN];
long long int lazy[5*MAXN];

void add(int node, int p, int q, int start, int end, long long int val) {
	if(lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if(start != end) {
			int mid = (start+end)/2;
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (q < start || p > end || start > end) return;

	if(p <= start && end <= q) {
		tree[node] += (end-start+1)*val;
		if(start != end) {
			lazy[2*node+1] += val;
			lazy[2*node+2] += val;
		}
		return;
	}
	add(2*node+1,p,q,start,(start+end)/2,val);
	add(2*node+2, p, q, 1+ (start+end)/2, end, val);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}

long long int query (int node, int p, int q, int start, int end) {
	if(q < start || p > end || start > end) return  0;
	if(lazy[node] != 0) {
		tree[node] += (end-start+1)*lazy[node];
		if(start != end) {
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}	
		lazy[node] = 0;
	}
	if(p <= start && end <= q) return  tree[node];
	return query(2*node+1, p, q, start, (start+end)/2) + query (2*node+2, p, q, 1+(start+end)/2, end);
}

int main() {
	int T,N,C;
	scanf(" %d",&T);
	while(T--) {
		scanf(" %d %d",&N,&C);
		memset(a,0,sizeof(a));
		memset(lazy,0,sizeof(lazy));
		memset(tree,0,sizeof(tree));
		for(int i = 0; i < C; i++) {
			int qtype;
			scanf(" %d",&qtype);
			if(qtype == 0) {
				int p,q;
				long long int val;
				scanf(" %d %d %lld",&p,&q,&val);
				add(0, --p, --q, 0, N-1,val);
			}
			else if(qtype == 1) {
				int p,q;
				scanf(" %d %d",&p,&q);
				printf("%lld\n",query(0,--p,--q,0,N-1));
			}
		}
	}
}
