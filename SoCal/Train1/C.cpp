#include <stdio.h>

int main() {
	int n;
	while(scanf(" %d",&n)>0 && n > 0){
		int p;
		scanf(" %d",&p);
		int a,b,c;
		if(p > n/2) {
			if(p%2 == 0) {
				a = n-p+1;
				b = n-p+2;
				c = p-1;
			}
			else {
				a = n - p;
				b = n-p+1;
				c = p+1;
			}
		}
		else {
			if(p%2 == 0) {
				a = p-1;
				b = n - p + 1;
				c = n - p + 2;
			}
			else {
				a = p+1;
				b = n-p;
				c = n-p+1;
			}
		}
		printf("%d %d %d\n",a,b,c);
	}
}
