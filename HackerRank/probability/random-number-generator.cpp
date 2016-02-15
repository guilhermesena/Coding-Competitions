#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}
int main() {
	int t;
	scanf(" %d",&t);
	while(t--) {
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		if(a > b) {
			int swap = b;
			b = a;
			a = swap;
		}

		if(c < a) {
			int u = c*c;
			int v = 2*a*b;
			int g = gcd(v,u);
			u = u/g;
			v = v/g;
			printf("%d/%d\n",u,v);
		}
		else if(c>=a && c < b) {
			int u = 2*c-a;
			int v = 2*b;
			int g = gcd(v,u);
			u = u/g;
			v = v/g;
			printf("%d/%d\n",u,v);
		}

		else if (c >= b && c <= a+b) {
			int u = 2*a*b - a*a +(2*a+b-c)*(c-b);
			int v = 2*a*b;
			int g = gcd(v,u);
			u = u/g;
			v = v/g;
			printf("%d/%d\n",u,v);
		}
		else {
			printf("1/1\n");
		}
		
	}
}
