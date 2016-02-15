#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long int ll;

const int MAXN = 100010;
const int TREE_SIZE = 250010;
ll tree[TREE_SIZE];
char s[MAXN];

ll sum(int i) {
	ll sum = 0ll;
	while (i > 0) {
		sum += tree[i];
		i -= ((i) & (-i));
	}
	return sum;
}

void add(int i, ll k) {
	while (i < TREE_SIZE) {
		tree[i] += k;
		i += ((i) & (-i));
	}
}

ll gcd(ll x, ll y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main() {
	int t,n,k;
	int dd = scanf(" %d", &t);
	while (t-- && scanf(" %d %d",&n,&k)>0) {
		int ww = scanf(" %s",s);
		int len = strlen(s);
		for(int i = 0; i < TREE_SIZE; i++) tree[i] = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				add(i + 1, 1ll);
			}
		}
		ll num = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				num += sum(min(i + k + 1, len)) - sum(max(i - k, 0));
			}
		}
		ll u = num;
		ll v = ((ll) len) * ((ll) len);
		ll g = gcd(v, u);
		u = u / g;
		v = v / g;
		printf("%lld/%lld\n", u, v);
	}
	return 0;
}

