#include <stdio.h>
#include <string.h>
const int MAXN = 5010;
bool write[MAXN];
bool iscomposed[MAXN];
int main() {
	int n;
	scanf(" %d",&n);
	memset(write, false, sizeof(write));
	memset(iscomposed, false, sizeof(iscomposed));
	for(int i = 2; i*i <= n; i++) {
		if(!iscomposed[i]) {
			for(int j = i*i; j <= n; j += i)
				iscomposed[j] = true;
		}
	}
	for(int i = 2; i <= n; i++) {
		if(!iscomposed[i]) {
			int p = i;
			while(p <= n) {
				write[p] = true;
				p *= i;
			}
		}
	}
	int ans = 0;
	for(int i = 2; i <= n; i++)
		if(write[i]) ans++;
	printf("%d\n",ans);
	for(int i = 2; i <= n; i++)
		if(write[i])
			printf("%d ",i);

	return 0;

}
